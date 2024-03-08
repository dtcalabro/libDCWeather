// libDCWeather.m
#import "libDCWeather.h"
#import <os/log.h>
#include <dlfcn.h>
#import <objc/runtime.h>

#define DEGREE_SYMBOL @"\u00B0"

#define TEMPERATURE_CHANGE_NOTIFICATION @"kDCWeatherTemperatureChange"
#define LOCATION_CHANGE_NOTIFICATION    @"kDCWeatherLocationChange"
#define CONDITION_CHANGE_NOTIFICATION   @"kDCWeatherConditionChange"

#define debug_log(...) ({\
	if (LDCW_DEBUG) {\
		char* str; \
		asprintf(&str, __VA_ARGS__); \
		os_log(OS_LOG_DEFAULT, "[LDCW_DEBUG] %s", str); \
	}\
})

enum ConditionCode {
    Tornado = 0,
    TropicalStorm = 1,
    Hurricane = 2,
    SevereThunderstorms = 3,
    Thunderstorms = 4,
    MixedRainAndSnow = 5,
    MixedRainAndSleet = 6,
    MixedSnowAndSleet = 7,
    FreezingDrizzle = 8,
    Drizzle = 9,
    FreezingRain = 10,
    Showers = 11,
    Rain = 12,
    SnowFlurries = 13,
    LightSnowShowers = 14,
    BlowingSnow = 15,
    Snow = 16,
    Hail = 17,
    Sleet = 18,
    Dust = 19,
    Foggy = 20,
    Haze = 21,
    Smokey = 22,
    Breezy = 23,
    Windy = 24,
    Frigid = 25,
    Cloudy = 26,
    MostlyCloudyNight = 27,
    MostlyCloudy = 28,
    PartlyCloudyNight = 29,
    PartlyCloudy = 30,
    ClearNight = 31,
    Sunny = 32,
    MostlySunnyNight = 33,
    MostlySunny = 34,
    MixedRainFall = 35,
    Hot = 36,
    IsolatedThunderstorms = 37,
    ScatteredThunderstorms = 38,
    ScatteredShowers1 = 39,
    HeavyRain = 40,
    ScatteredSnowShowers1 = 41,
    HeavySnow = 42,
    Blizzard = 43,
    NotAvailable = 44,
    ScatteredShowers2 = 45,
    ScatteredSnowShowers2 = 46,
    IsolatedThundershowers = 47
};

@implementation libDCWeather

+ (instancetype)sharedInstance {
	static dispatch_once_t p = 0;
	static __strong libDCWeather *_sharedSelf = nil;
	dispatch_once(&p, ^{
        // Initialize the shared instance here
		_sharedSelf = [[libDCWeather alloc] init];
        [_sharedSelf setAutoUpdateInvervalInMinutes:5];
	});
	return _sharedSelf;
}

- (instancetype)init {
    self = [super init];
    if (self) {
        // Initialization code here
        self.conditionIncludesSevereWeather = NO;
        [self setAutoUpdateInvervalInMinutes:5];

        self.weatherLocationManager = [objc_getClass("WeatherLocationManager") sharedWeatherLocationManager];
        [self.weatherLocationManager setDelegate:self];
        self.weatherLocationManager.updateInterval = self.updateInterval;
        self.weatherLocationManager.locationUpdatesEnabled = YES;
        self.weatherLocationManager.locationTrackingIsReady = YES;

        // Start location tracking in Weather.framework
        if ([self.weatherLocationManager respondsToSelector:@selector(setLocationTrackingReady:activelyTracking:watchKitExtension:)]) {
            [self.weatherLocationManager setLocationTrackingReady:YES activelyTracking:NO watchKitExtension:NO];
        }

        if ([self locationServicesEnabled]) {
            [self.weatherLocationManager setLocationTrackingActive:YES];
            [[objc_getClass("WeatherPreferences") sharedPreferences] setLocalWeatherEnabled:YES];

            // Force a new location update if possible
            [self.weatherLocationManager forceLocationUpdate];
        } else {
            // Location services are not enabled, so enable them
            // TODO: Implement a way to restore the original state after
            //debug_log("Location services are not enabled");
            [objc_getClass("CLLocationManager") setAuthorizationStatusByType:3 forBundleIdentifier:@"com.apple.weather"];

            [self.weatherLocationManager setLocationTrackingActive:YES];
            [[objc_getClass("WeatherPreferences") sharedPreferences] setLocalWeatherEnabled:YES];

            // Force a new location update if possible
            [self.weatherLocationManager forceLocationUpdate];
        }

        [self refreshLocation];

        // Start the update timer with the full interval
        [self _restartTimerWithInterval:self.updateInterval];
    }
    return self;
}

- (void)dealloc {
    // Remove observers
    [self.currentCity removeObserver:self forKeyPath:@"temperature"];
    [self.currentCity removeObserver:self forKeyPath:@"location"];
    [self.currentCity removeObserver:self forKeyPath:@"conditionCode"];
}

- (void)refreshLocation {
    //debug_log("refreshLocation");
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        // Force a new location update if possible
        [self.weatherLocationManager forceLocationUpdate];

        // Get the local weather city and update it
        //WeatherPreferences *weatherPreferences = [WeatherPreferences sharedPreferences];
        WeatherPreferences *weatherPreferences = [[WeatherPreferences alloc] init];
        [weatherPreferences setLocalWeatherEnabled:YES];

        self.currentCity = [weatherPreferences localWeatherCity];
        [self.currentCity update];
        
        // Add observers
        [self.currentCity addObserver:self
            forKeyPath:@"temperature"
            options:NSKeyValueObservingOptionNew | NSKeyValueObservingOptionOld
            context:NULL];
        [self.currentCity addObserver:self
            forKeyPath:@"location"
            options:NSKeyValueObservingOptionNew | NSKeyValueObservingOptionOld
            context:NULL];
        [self.currentCity addObserver:self
            forKeyPath:@"conditionCode"
            options:NSKeyValueObservingOptionNew | NSKeyValueObservingOptionOld
            context:NULL];

        [self requestRefresh];
    });
}

- (BOOL)locationServicesEnabled {
    //debug_log("locationServicesEnabled");

    // Check if local weather is enabled and location services are enabled
    if (![[WeatherPreferences sharedPreferences] isLocalWeatherEnabled] || ![CLLocationManager locationServicesEnabled]) {
        return NO;
    }
    return YES;
}

- (void)conditionIncludesSevereWeather:(BOOL)conditionIncludesSevereWeather {
    //debug_log("conditionIncludesSevereWeather");
    _conditionIncludesSevereWeather = conditionIncludesSevereWeather;
}

- (void)setAutoUpdateInvervalInSeconds:(NSInteger)interval {
    //debug_log("setAutoUpdateInvervalInSeconds");
    self.updateInterval = interval;
    self.weatherLocationManager.updateInterval = self.updateInterval;
    [self _restartTimerWithInterval:interval];
}

- (void)setAutoUpdateInvervalInMinutes:(NSInteger)interval {
    //debug_log("setAutoUpdateInvervalInMinutes");
    self.updateInterval = interval * 60;
    self.weatherLocationManager.updateInterval = self.updateInterval;
    [self _restartTimerWithInterval:self.updateInterval];
}

- (void)setAutoUpdateInvervalInHours:(NSInteger)interval {
    //debug_log("setAutoUpdateInvervalInHours");
    self.updateInterval = interval * 60 * 60;
    self.weatherLocationManager.updateInterval = self.updateInterval;
    [self _restartTimerWithInterval:self.updateInterval];
}

- (void)observeValueForKeyPath:(NSString *)keyPath
                      ofObject:(id)object
                        change:(NSDictionary<NSKeyValueChangeKey,id> *)change
                       context:(void *)context {
    // If the old and new values are the same, do nothing
    if (change[NSKeyValueChangeOldKey] == change[NSKeyValueChangeNewKey])
        return;

    if ([keyPath isEqualToString:@"temperature"]) {
        // The temperature has changed
        //debug_log("Temperature has changed");
        [[NSNotificationCenter defaultCenter] postNotificationName:TEMPERATURE_CHANGE_NOTIFICATION object:self];
    } else if ([keyPath isEqualToString:@"location"]) {
        // The location has changed
        //debug_log("Location has changed");
        [[NSNotificationCenter defaultCenter] postNotificationName:LOCATION_CHANGE_NOTIFICATION object:self];
    } else if ([keyPath isEqualToString:@"conditionCode"]) {
        // The conditionCode has changed
        //debug_log("Condition code has changed");
        [[NSNotificationCenter defaultCenter] postNotificationName:CONDITION_CHANGE_NOTIFICATION object:self];
    }
}

- (void)requestRefresh {
    [self _refreshWeather];
    
    // And restart the update timer with the full interval
    [self _restartTimerWithInterval:self.updateInterval];
}

- (void)_restartTimerWithInterval:(NSTimeInterval)interval {
    if (self.updateTimer)
        [self.updateTimer invalidate];
    
    self.updateTimer = [NSTimer scheduledTimerWithTimeInterval:interval
                                                        target:self
                                                      selector:@selector(_updateTimerFired:)
                                                      userInfo:nil
                                                       repeats:NO];
    
    self.nextUpdateTime = [[NSDate date] dateByAddingTimeInterval:interval];

    //NSLog(@"[LDCW_DEBUG] Next update time: %@", self.nextUpdateTime);
}

- (void)_refreshWeather {
    //NSLog(@"[LDCW_DEBUG] Refreshing weather, location: %@", self.currentCity.location);
    [self _refreshWeatherWithLocation:self.currentCity.location];
}

- (void)_refreshWeatherWithLocation:(CLLocation*)location {
    // Set update delegate
    if ([self.currentCity respondsToSelector:@selector(associateWithDelegate:)])
        [self.currentCity associateWithDelegate:self];
    else if ([self.currentCity respondsToSelector:@selector(addUpdateObserver:)])
        [self.currentCity addUpdateObserver:self];
    
    // Force a location update
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        TWCLocationUpdater *locationUpdater = [objc_getClass("TWCLocationUpdater") sharedLocationUpdater];
        [locationUpdater updateWeatherForLocation:location city:self.currentCity];
    });
}

- (NSString *)temperatureString {
    //debug_log("temperatureString");

    // Check if location services are enabled
    if (![self locationServicesEnabled])
        return @"Temperature Not Available";

    WFTemperature *temperature = [self.currentCity temperature];
    //debug_log("City: %s, Temperature: %f %.0f%s", [self.currentCity.name UTF8String], temperature.fahrenheit, temperature.fahrenheit, [DEGREE_SYMBOL UTF8String]);
    return [NSString stringWithFormat:@"%.0f%@", temperature.fahrenheit, DEGREE_SYMBOL];
}

- (NSString *)conditionString {
    //debug_log("conditionString");

    // Check if location services are enabled
    if (![self locationServicesEnabled])
        return @"Condition Not Available";

    // Check for severe weather condition if enabled
    if (self.conditionIncludesSevereWeather) {
        if (self.currentCity.severeWeatherEvents.count > 0) {
            // Currently only checking the first severe weather event, but I may change this in the future since there can be multiple events
            WFSevereWeatherEvent *severeWeatherEvent = self.currentCity.severeWeatherEvents[0];
            return severeWeatherEvent.eventDescription;
        }
    }

    // Check for regular weather condition
    switch (self.currentCity.conditionCode) {
        case Tornado:                                       // 0
            return @"Tornado";
        case TropicalStorm:                                 // 1
            return @"Tropical Storm";
        case Hurricane:                                     // 2
            return @"Hurricane";
        case SevereThunderstorms:                           // 3
            return @"Severe Thunderstorms";
        case Thunderstorms:                                 // 4
            return @"Thunderstorms";
        case MixedRainAndSnow:                              // 5
            return @"Mixed Rain and Snow";
        case MixedRainAndSleet:                             // 6
            return @"Mixed Rain and Sleet";
        case MixedSnowAndSleet:                             // 7
            return @"Mixed Snow and Sleet";
        case FreezingDrizzle:                               // 8
            return @"Freezing Drizzle";
        case Drizzle:                                       // 9
            return @"Drizzle";
        case FreezingRain:                                  // 10
            return @"Freezing Rain";
        case Showers:                                       // 11
            return @"Showers";
        case Rain:                                          // 12
            return @"Rain";
        case SnowFlurries:                                  // 13
            return @"Snow Flurries";
        case LightSnowShowers:                              // 14
            return @"Light Snow Showers";
        case BlowingSnow:                                   // 15
            return @"Blowing Snow";
        case Snow:                                          // 16
            return @"Snow";
        case Hail:                                          // 17
            return @"Hail";
        case Sleet:                                         // 18
            return @"Sleet";
        case Dust:                                          // 19
            return @"Dust";
        case Foggy:                                         // 20
            return @"Foggy";
        case Haze:                                          // 21
            return @"Haze";
        case Smokey:                                        // 22
            return @"Smokey";
        case Breezy:                                        // 23
            return @"Breezy";
        case Windy:                                         // 24
            return @"Windy";
        case Frigid:                                        // 25
            return @"Frigid";
        case Cloudy:                                        // 26
            return @"Cloudy";
        case MostlyCloudyNight:                             // 27
            return @"Mostly Cloudy";
        case MostlyCloudy:                                  // 28
            return @"Mostly Cloudy";
        case PartlyCloudyNight:                             // 29
            return @"Partly Cloudy";
        case PartlyCloudy:                                  // 30
            return @"Parly Cloudy";
        case ClearNight:                                    // 31
            return @"Clear";
        case Sunny:                                         // 32
            return @"Sunny";
        case MostlySunnyNight:                              // 33
            return @"Mostly Clear";
        case MostlySunny:                                   // 34
            return @"Mostly Sunny";
        case MixedRainFall:                                 // 35
            return @"Mixed Rain Fall";
        case Hot:                                           // 36
            return @"Hot";
        case IsolatedThunderstorms:                         // 37
            return @"Isolated Thunderstorms";
        case ScatteredThunderstorms:                        // 38
            return @"Scattered Thunderstorms";
        case ScatteredShowers1:                             // 39
            return @"Scattered Showers";
        case HeavyRain:                                     // 40
            return @"Heavy Rain";
        case ScatteredSnowShowers1:                         // 41
            return @"Scattered Snow Showers";
        case HeavySnow:                                     // 42
            return @"Heavy Snow";
        case Blizzard:                                      // 43
            return @"Blizzard";
        case NotAvailable:                                  // 44
            return @"Not Available";
        case ScatteredShowers2:                             // 45
            return @"Scattered Showers";
        case ScatteredSnowShowers2:                         // 46
            return @"Scattered Snow Showers";
        case IsolatedThundershowers:                        // 47
            return @"Isolated Thundershowers";
        default:
            return [NSString stringWithFormat:@"Unknown (%ld)", self.currentCity.conditionCode];
    }
}

- (UIImage *)conditionImage {
    //debug_log("conditionImage");

    // Check if location services are enabled
    if (![self locationServicesEnabled])
        return nil;

    // Check for severe weather condition if enabled
    if (self.conditionIncludesSevereWeather) {
        if (self.currentCity.severeWeatherEvents.count > 0) {
            WFSevereWeatherEvent *severeWeatherEvent = self.currentCity.severeWeatherEvents[0];
            // TODO: Add severe weather condition images
        }
    }

    // Check for regular weather condition
    switch (self.currentCity.conditionCode) {
        case Tornado:                                                                   // 0
            return [UIImage systemImageNamed:@"tornado"];
        case TropicalStorm:                                                             // 1
            return [UIImage systemImageNamed:@"tropicalstorm"];
        case Hurricane:                                                                 // 2
            return [UIImage systemImageNamed:@"hurricane"];
        case SevereThunderstorms:                                                       // 3
            return [UIImage systemImageNamed:@"cloud.bolt.rain.fill"];
        case Thunderstorms:                                                             // 4
            return [UIImage systemImageNamed:@"cloud.bolt.fill"];
        case MixedRainAndSnow:                                                          // 5
            return [UIImage systemImageNamed:@"cloud.sleet.fill"];
        case MixedRainAndSleet:                                                         // 6
            return [UIImage systemImageNamed:@"cloud.sleet.fill"];
        case MixedSnowAndSleet:                                                         // 7
            return [UIImage systemImageNamed:@"cloud.sleet.fill"];
        case FreezingDrizzle:                                                           // 8
            return [UIImage systemImageNamed:@"cloud.sleet.fill"];
        case Drizzle:                                                                   // 9
            return [UIImage systemImageNamed:@"cloud.drizzle.fill"];
        case FreezingRain:                                                              // 10
            return [UIImage systemImageNamed:@"thermometer.snowflake"];
        case Showers:                                                                   // 11
            return [UIImage systemImageNamed:@"cloud.rain.fill"];
        case Rain:                                                                      // 12
            return [UIImage systemImageNamed:@"cloud.rain.fill"];
        case SnowFlurries:                                                              // 13
            return [UIImage systemImageNamed:@"snow"];
        case LightSnowShowers:                                                          // 14
            return [UIImage systemImageNamed:@"snow"];
        case BlowingSnow:                                                               // 15
            return [UIImage systemImageNamed:@"wind.snow"];
        case Snow:                                                                      // 16
            return [UIImage systemImageNamed:@"snow"];
        case Hail:                                                                      // 17
            return [UIImage systemImageNamed:@"cloud.hail.fill"];
        case Sleet:                                                                     // 18
            return [UIImage systemImageNamed:@"cloud.sleet.fill"];
        case Dust:                                                                      // 19
            return [UIImage systemImageNamed:@"sun.dust.fill"];
        case Foggy:                                                                     // 20
            return [UIImage systemImageNamed:@"cloud.fog.fill"];
        case Haze:                                                                      // 21
            return [UIImage systemImageNamed:@"sun.haze.fill"];
        case Smokey:                                                                    // 22
            return [UIImage systemImageNamed:@"smoke.fill"];
        case Breezy:                                                                    // 23
            return [UIImage systemImageNamed:@"wind"];
        case Windy:                                                                     // 24
            return [UIImage systemImageNamed:@"wind"];
        case Frigid:                                                                    // 25
            return [UIImage systemImageNamed:@"thermometer.snowflake"];
        case Cloudy:                                                                    // 26
            return [UIImage systemImageNamed:@"cloud.fill"];
        case MostlyCloudyNight:                                                         // 27
            return [UIImage systemImageNamed:@"cloud.fill"];
        case MostlyCloudy:                                                              // 28
            return [UIImage systemImageNamed:@"cloud.fill"];
        case PartlyCloudyNight:                                                         // 29
            return [UIImage systemImageNamed:@"cloud.moon.fill"];
        case PartlyCloudy:                                                              // 30
            return [UIImage systemImageNamed:@"cloud.sun.fill"];
        case ClearNight:                                                                // 31
            return [UIImage systemImageNamed:@"moon.stars.fill"];
        case Sunny:                                                                     // 32
            return [UIImage systemImageNamed:@"sun.max.fill"];
        case MostlySunnyNight:                                                          // 33
            return [UIImage systemImageNamed:@"moon.stars.fill"];
        case MostlySunny:                                                               // 34
            return [UIImage systemImageNamed:@"sun.max.fill"];
        case MixedRainFall:                                                             // 35
            return [UIImage systemImageNamed:@"cloud.hail.fill"];
        case Hot:                                                                       // 36
            return [UIImage systemImageNamed:@"thermometer.sun"];
        case IsolatedThunderstorms:                                                     // 37
            return [UIImage systemImageNamed:@"cloud.bolt.rain.fill"];
        case ScatteredThunderstorms:                                                    // 38
            return [UIImage systemImageNamed:@"cloud.bolt.fill"];
        case ScatteredShowers1:                                                         // 39
            return [UIImage systemImageNamed:@"cloud.rain.fill"];
        case HeavyRain:                                                                 // 40
            return [UIImage systemImageNamed:@"cloud.heavyrain.fill"];
        case ScatteredSnowShowers1:                                                     // 41
            return [UIImage systemImageNamed:@"cloud.snow.fill"];
        case HeavySnow:                                                                 // 42
            return [UIImage systemImageNamed:@"cloud.snow.fill"];
        case Blizzard:                                                                  // 43
            return [UIImage systemImageNamed:@"cloud.snow.fill"];
        case NotAvailable:                                                              // 44
            return [UIImage systemImageNamed:@"questionmark.circle.fill"];
        case ScatteredShowers2:                                                         // 45
            return [UIImage systemImageNamed:@"cloud.bolt.fill"];
        case ScatteredSnowShowers2:                                                     // 46
            return [UIImage systemImageNamed:@"cloud.snow.fill"];
        case IsolatedThundershowers:                                                    // 47
            return [UIImage systemImageNamed:@"cloud.bolt.rain.fill"];
        default:
            return [UIImage systemImageNamed:@"questionmark.circle.fill"];
    }
}

- (NSString *)cityString {
    //debug_log("cityString");

    // Check if location services are enabled
    if (![self locationServicesEnabled])
        return @"City Not Available";

    return self.currentCity.name;
}

#pragma mark CLLocationManagerDelegate methods

- (void)locationManager:(CLLocationManager *)manager didUpdateLocations:(NSArray*)locations {
    //debug_log("didUpdateLocations");
    if (locations.count > 0) {
        CLLocation *newestLocation = [locations lastObject];
        //debug_log("Newest location: %f, %f", newestLocation.coordinate.latitude, newestLocation.coordinate.longitude);
        
        // Check if the location has changed
        if (newestLocation.coordinate.latitude == self.currentCity.latitude && newestLocation.coordinate.longitude == self.currentCity.longitude)
            // TODO: Figure out a better way to check this
            return;

        // Get an update for this change!
        [self _refreshWeatherWithLocation:newestLocation];
    }
}

#pragma mark City delegate methods

-(void)cityDidStartWeatherUpdate:(id)city {
    // Nothing to do here currently.
    //debug_log("cityDidStartWeatherUpdate");
}

-(void)cityDidFinishWeatherUpdate:(City*)city {
    //debug_log("cityDidFinishWeatherUpdate");

    //NSLog(@"[LDCW_DEBUG] currentCity: %@", self.currentCity);
    //NSLog(@"[LDCW_DEBUG] currentCity.location: %@", self.currentCity.location);
    //NSLog(@"[LDCW_DEBUG] currentCity.locationID: %@", self.currentCity.locationID);
    //NSLog(@"[LDCW_DEBUG] city: %@", city);
    //NSLog(@"[LDCW_DEBUG] city.location: %@", city.location);
    //NSLog(@"[LDCW_DEBUG] city.locationID: %@", city.locationID);

    if ([self.currentCity isEqual:city] || [self.currentCity.locationID isEqualToString:city.locationID])
        return;

    // New data, so update!
    self.currentCity = city;

    [[NSNotificationCenter defaultCenter] postNotificationName:LOCATION_CHANGE_NOTIFICATION object:self];
}

@end