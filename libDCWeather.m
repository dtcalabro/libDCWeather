// libDCWeather.m
#import "libDCWeather.h"
#import <os/log.h>
#import <dlfcn.h>
#import <objc/runtime.h>

#define DEGREE_SYMBOL @"\u00B0"

// external
#define TEMPERATURE_CHANGE_NOTIFICATION             @"kDCWeatherTemperatureChange"
#define FEELS_LIKE_TEMPERATURE_CHANGE_NOTIFICATION  @"kDCWeatherFeelsLikeTemperatureChange"
#define LOCATION_CHANGE_NOTIFICATION                @"kDCWeatherLocationChange"
#define CONDITION_CHANGE_NOTIFICATION               @"kDCWeatherConditionChange"

// internal
#define DEVICE_WAKE_NOTIFICATION                    @"kDCWeatherDeviceWake"

#define debug_log(fmt, ...) do { \
    if (LDCW_DEBUG) { \
        char *str = NULL; \
        asprintf(&str, fmt, ##__VA_ARGS__); \
        if (str) { \
            os_log(OS_LOG_DEFAULT, "[LDCW_DEBUG] %s", str); \
            free(str); \
        } \
    } \
} while (0)

#define method_log(fmt, ...) do { \
    if (LDCW_DEBUG) { \
        NSLog((@"[LDCW_DEBUG] %s => " fmt), __PRETTY_FUNCTION__, ##__VA_ARGS__); \
    } \
} while (0)

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

@implementation DCWeather

+ (instancetype)sharedInstance {
    method_log();

	static dispatch_once_t p = 0;
	static __strong DCWeather *_sharedSelf = nil;
	dispatch_once(&p, ^{
        // Initialize the shared instance here
		_sharedSelf = [[DCWeather alloc] init];
        [_sharedSelf conditionIncludesSevereWeather:NO];                            // Default to not include severe weather
        [_sharedSelf setAutoUpdateInvervalInMinutes:5];                             // Default to update every 5 minutes
        [_sharedSelf setDistanceThresholdToConsiderLocationChangeInMiles:1];        // Default to 1 mile
        [_sharedSelf setTemperatureUnit:[_sharedSelf userTemperatureUnit]];         // Default to the user's temperature unit
        [_sharedSelf setSpeedUnit:[_sharedSelf userSpeedUnit]];                     // Default to the user's speed unit
	});
	return _sharedSelf;
}

- (instancetype)init {
    method_log();

    self = [super init];
    if (self) {
        // Initialization code here
        [self conditionIncludesSevereWeather:NO];                                   // Default to not include severe weather
        [self setAutoUpdateInvervalInMinutes:5];                                    // Default to update every 5 minutes
        [self setDistanceThresholdToConsiderLocationChangeInMiles:1];               // Default to 1 mile
        [self setTemperatureUnit:[self userTemperatureUnit]];                       // Default to the user's temperature unit
        [self setSpeedUnit:[self userSpeedUnit]];                                   // Default to the user's speed unit

        // Initialize the WeatherLocationManager
        self.weatherLocationManager = [objc_getClass("WeatherLocationManager") sharedWeatherLocationManager];
        [self.weatherLocationManager setDelegate:self];
        self.weatherLocationManager.updateInterval = [self.updateInterval seconds];
        self.weatherLocationManager.locationUpdatesEnabled = YES;
        self.weatherLocationManager.locationTrackingIsReady = YES;
        [self.weatherLocationManager setLocationTrackingActive:YES];

        // Start location tracking in Weather.framework
        if ([self.weatherLocationManager respondsToSelector:@selector(setLocationTrackingReady:activelyTracking:watchKitExtension:)])
            [self.weatherLocationManager setLocationTrackingReady:YES activelyTracking:NO watchKitExtension:NO];

        // Refresh the location and weather, plus add observers
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0), ^{
            // Force a new location update if possible
            [self.weatherLocationManager forceLocationUpdate];

            // Get the local weather city and update it
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
                forKeyPath:@"feelsLike"
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

            // Add observer for device wake notification
            [[NSNotificationCenter defaultCenter] addObserver:self
                                                selector:@selector(handleDeviceWakeNotification:)
                                                name:DEVICE_WAKE_NOTIFICATION
                                                object:nil];
            
            // Refresh the weather
            [self requestRefresh];
        });

        // Start the update timer with the full interval
        [self _restartTimerWithInterval:[self.updateInterval seconds]];
    }
    return self;
}

- (void)dealloc {
    // Remove observers
    [self.currentCity removeObserver:self forKeyPath:@"temperature"];
    [self.currentCity removeObserver:self forKeyPath:@"feelsLike"];
    [self.currentCity removeObserver:self forKeyPath:@"location"];
    [self.currentCity removeObserver:self forKeyPath:@"conditionCode"];
    [[NSNotificationCenter defaultCenter] removeObserver:self name:DEVICE_WAKE_NOTIFICATION object:nil];
}

- (BOOL)locationServicesEnabled {
    method_log();

    // Check if local weather is enabled and location services are enabled
    if (![[WeatherPreferences sharedPreferences] isLocalWeatherEnabled] || ![CLLocationManager locationServicesEnabled]) {
        //debug_log("Location services are not enabled");
        return NO;
    }
    //debug_log("Location services are enabled");
    return YES;
}

- (BOOL)locationAuthorizationAlways {
    method_log();

    // Check if location services are enabled
    if (![self locationServicesEnabled])
        return NO;

    // Check if location services are authorized
    if ([objc_getClass("CLLocationManager") authorizationStatusForBundleIdentifier:@"com.apple.weather"] == kCLAuthorizationStatusAuthorizedAlways) {
        //debug_log("Location services are authorized");
        return YES;
    }
    //debug_log("Location services are not authorized");
    return NO;
}

- (void)conditionIncludesSevereWeather:(BOOL)conditionIncludesSevereWeather {
    // Set the conditionIncludesSevereWeather property
    method_log(@"conditionIncludesSevereWeather: %d", conditionIncludesSevereWeather);
    _conditionIncludesSevereWeather = conditionIncludesSevereWeather;
}

- (void)setAutoUpdateInvervalInSeconds:(NSInteger)seconds {
    // Set the update interval in seconds
    method_log(@"seconds: %ld", seconds);
    self.updateInterval = [[DCTime alloc] initWithSeconds:seconds];
    self.weatherLocationManager.updateInterval = [self.updateInterval seconds];
    [self _restartTimerWithInterval:[self.updateInterval seconds]];
}

- (void)setAutoUpdateInvervalInMinutes:(NSInteger)minutes {
    // Set the update interval in minutes
    method_log(@"minutes: %ld", minutes);
    self.updateInterval = [[DCTime alloc] initWithMinutes:minutes];
    self.weatherLocationManager.updateInterval = [self.updateInterval seconds];
    [self _restartTimerWithInterval:[self.updateInterval seconds]];
}

- (void)setAutoUpdateInvervalInHours:(NSInteger)hours {
    // Set the update interval in hours
    method_log(@"hours: %ld", hours);
    self.updateInterval = [[DCTime alloc] initWithHours:hours];
    self.weatherLocationManager.updateInterval = [self.updateInterval seconds];
    [self _restartTimerWithInterval:[self.updateInterval seconds]];
}

- (void)setDistanceThresholdToConsiderLocationChangeInMeters:(double)distanceThreshold {
    // Set the distance threshold in meters
    method_log(@"distanceThreshold: %f", distanceThreshold);
    self.distanceThreshold = [[DCDistance alloc] initWithMeters:distanceThreshold];
}

- (void)setDistanceThresholdToConsiderLocationChangeInKilometers:(double)distanceThreshold {
    // Set the distance threshold in kilometers
    method_log(@"distanceThreshold: %f", distanceThreshold);
    self.distanceThreshold = [[DCDistance alloc] initWithKilometers:distanceThreshold];
}

- (void)setDistanceThresholdToConsiderLocationChangeInFeet:(double)distanceThreshold {
    // Set the distance threshold in feet
    method_log(@"distanceThreshold: %f", distanceThreshold);
    self.distanceThreshold = [[DCDistance alloc] initWithFeet:distanceThreshold];
}

- (void)setDistanceThresholdToConsiderLocationChangeInYards:(double)distanceThreshold {
    // Set the distance threshold in yards
    method_log(@"distanceThreshold: %f", distanceThreshold);
    self.distanceThreshold = [[DCDistance alloc] initWithYards:distanceThreshold];
}

- (void)setDistanceThresholdToConsiderLocationChangeInMiles:(double)distanceThreshold {
    // Set the distance threshold in miles
    method_log(@"distanceThreshold: %f", distanceThreshold);
    self.distanceThreshold = [[DCDistance alloc] initWithMiles:distanceThreshold];
}

- (enum TemperatureUnit)userTemperatureUnit {
    // Get the user's temperature unit
    method_log();
    if ([[objc_getClass("WeatherPreferences") sharedPreferences] isCelsius])
        return Celsius;
    return Fahrenheit;
}

- (void)setTemperatureUnit:(enum TemperatureUnit)unit {
    // Set the temperature unit
    method_log(@"unit: %d", unit);
    _temperatureUnit = unit;
}

- (enum SpeedUnit)userSpeedUnit {
    // Get the user's speed unit
    method_log();
    if ([[[[[objc_getClass("WeatherWindSpeedFormatter") alloc] init] locale] objectForKey:NSLocaleUsesMetricSystem] boolValue])
        return KiloMetersPerHour;
    return MilesPerHour;
}

- (void)setSpeedUnit:(enum SpeedUnit)unit {
    // Set the speed unit
    method_log(@"unit: %d", unit);
    _speedUnit = unit;
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
        [[NSNotificationCenter defaultCenter] postNotificationName:TEMPERATURE_CHANGE_NOTIFICATION object:self];
    } else if ([keyPath isEqualToString:@"feelsLike"]) {
        // The feelsLike temperature has changed
        [[NSNotificationCenter defaultCenter] postNotificationName:FEELS_LIKE_TEMPERATURE_CHANGE_NOTIFICATION object:self];
    } else if ([keyPath isEqualToString:@"location"]) {
        // The location has changed
        [[NSNotificationCenter defaultCenter] postNotificationName:LOCATION_CHANGE_NOTIFICATION object:self];
    } else if ([keyPath isEqualToString:@"conditionCode"]) {
        // The conditionCode has changed
        [[NSNotificationCenter defaultCenter] postNotificationName:CONDITION_CHANGE_NOTIFICATION object:self];
    }
}

- (void)requestRefresh {
    method_log();

    // Force a new location update if possible
    if (self.weatherLocationManager)
        [self.weatherLocationManager forceLocationUpdate];

    // Refresh the weather
    [self _refreshWeather];
    
    // And restart the update timer with the full interval
    [self _restartTimerWithInterval:[self.updateInterval seconds]];
}

- (void)_restartTimerWithInterval:(NSTimeInterval)interval {
    method_log(@"interval: %f", interval);

    // Invalidate the current timer
    if (self.updateTimer)
        [self.updateTimer invalidate];
    
    // Schedule a new timer
    self.updateTimer = [NSTimer scheduledTimerWithTimeInterval:interval
                                                        target:self
                                                      selector:@selector(_updateTimerEnded:)
                                                      userInfo:nil
                                                       repeats:NO];
    
    // Set the next update time
    self.nextUpdateTime = [[NSDate date] dateByAddingTimeInterval:interval];
}

- (void)_updateTimerEnded:(NSTimer*)timer {
    method_log(@"timer: %@", timer);

    [self requestRefresh];
}

- (void)_refreshWeather {
    method_log();

    // Refresh the weather
    [self _refreshWeatherWithLocation:self.currentCity.location];
}

- (void)_refreshWeatherWithLocation:(CLLocation*)location {
    method_log(@"location: %@", location);

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

- (void)handleDeviceWakeNotification:(NSNotification *)notification {
    BOOL screenIsWaking = [notification.userInfo[@"screenIsWaking"] boolValue];

    if (screenIsWaking && self.isSleeping) {
        self.isSleeping = NO;

        // Restarting timer as needed.
        NSTimeInterval nextUpdateTime = [self.nextUpdateTime timeIntervalSinceDate:[NSDate date]];
        
        // Restart the timer with the next update time
        [self _restartTimerWithInterval:nextUpdateTime];
    } else if (!screenIsWaking && !self.isSleeping) {
        self.isSleeping = YES;

        // Stop update timer when device is sleeping because it's not needed
        [self.updateTimer invalidate];
    }
}

- (NSString *)temperatureString {
    method_log();

    // Check if location services are enabled
    if (![self locationServicesEnabled])
        return @"Temperature Not Available";

    // Check if the temperature is 0 and the condition is Tornado, which indicates that the temperature is not available
    if (self.currentCity.temperature.fahrenheit == 0 && self.currentCity.conditionCode == Tornado)
        return @"Temperature Not Available";

    // Create a DCTemperature object and return the temperature in the user's unit
    DCTemperature *temperature = [[DCTemperature alloc] init:[self.currentCity temperature].fahrenheit];
    return [NSString stringWithFormat:@"%.0f%@", [temperature temperatureInUnit:self.temperatureUnit], DEGREE_SYMBOL];
}

- (double)temperature {
    method_log();

    // Check if location services are enabled
    if (![self locationServicesEnabled])
        return 0;

    // Check if the temperature is 0 and the condition is Tornado, which indicates that the temperature is not available
    if (self.currentCity.temperature.fahrenheit == 0 && self.currentCity.conditionCode == Tornado)
        return 0;

    // Create a DCTemperature object and return the temperature in the user's unit
    DCTemperature *temperature = [[DCTemperature alloc] init:[self.currentCity temperature].fahrenheit];
    return [temperature temperatureInUnit:self.temperatureUnit];
}

- (NSString *)feelsLikeTemperatureString {
    method_log();

    // Check if location services are enabled
    if (![self locationServicesEnabled])
        return @"Feels Like Temperature Not Available";

    // Check if the temperature is 0 and the condition is Tornado, which indicates that the feels like temperature is not available
    if (self.currentCity.temperature.fahrenheit == 0 && self.currentCity.conditionCode == Tornado)
        return @"Feels Like Temperature Not Available";

    // Create a DCTemperature object and return the feelsLike temperature in the user's unit
    DCTemperature *temperature = [[DCTemperature alloc] init:[self.currentCity feelsLike].fahrenheit];
    return [NSString stringWithFormat:@"%.0f%@", [temperature temperatureInUnit:self.temperatureUnit], DEGREE_SYMBOL];
}

- (double)feelsLikeTemperature {
    method_log();

    // Check if location services are enabled
    if (![self locationServicesEnabled])
        return 0;

    // Check if the temperature is 0 and the condition is Tornado, which indicates that the feels like temperature is not available
    if (self.currentCity.temperature.fahrenheit == 0 && self.currentCity.conditionCode == Tornado)
        return 0;

    // Create a DCTemperature object and return the feelsLike temperature in the user's unit
    DCTemperature *temperature = [[DCTemperature alloc] init:[self.currentCity feelsLike].fahrenheit];
    return [temperature temperatureInUnit:self.temperatureUnit];
}

- (NSString *)conditionString {
    method_log();

    // Check if location services are enabled
    if (![self locationServicesEnabled])
        return @"Condition Not Available";

    // Check if the condition is Tornado and the temperature is 0 , which indicates that the condition is not available
    if (self.currentCity.conditionCode == Tornado && self.currentCity.temperature.fahrenheit == 0)
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
    method_log();

    // Check if location services are enabled
    if (![self locationServicesEnabled])
        return nil;

    // Check if the condition is Tornado and the temperature is 0 , which indicates that the condition is not available
    if (self.currentCity.conditionCode == Tornado && self.currentCity.temperature.fahrenheit == 0)
        return [UIImage systemImageNamed:@"questionmark.circle.fill"];

    // Check for severe weather condition if enabled
    if (self.conditionIncludesSevereWeather) {
        if (self.currentCity.severeWeatherEvents.count > 0) {
            // Currently only checking the first severe weather event, but I may change this in the future since there can be multiple events
            // Check the importance of the severe weather event, as that determines whether or not to return the severe weather icon
            WFSevereWeatherEvent *severeWeatherEvent = self.currentCity.severeWeatherEvents[0];
            if (severeWeatherEvent.importance != 0) {
                // Return a severe weather icon for severe weather events with importance other than 0
                return [UIImage systemImageNamed:@"exclamationmark.triangle.fill"];
            }
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

- (NSString *)windSpeedString {
    method_log();

    // Check if location services are enabled
    if (![self locationServicesEnabled])
        return @"Wind Speed Not Available";

    // Check if the temperature is 0 and the condition is Tornado, which indicates that the wind speed is not available
    if (self.currentCity.temperature.fahrenheit == 0 && self.currentCity.conditionCode == Tornado)
        return @"Wind Speed Not Available";

    DCWindSpeed *windSpeed = [[DCWindSpeed alloc] init:self.currentCity.windSpeed];
    return [windSpeed windSpeedInUnitString:self.speedUnit];
}

- (float)windSpeed {
    method_log();

    // Check if location services are enabled
    if (![self locationServicesEnabled])
        return 0;

    // Check if the temperature is 0 and the condition is Tornado, which indicates that the temperature is not available
    if (self.currentCity.temperature.fahrenheit == 0 && self.currentCity.conditionCode == Tornado)
        return 0;

    DCWindSpeed *windSpeed = [[DCWindSpeed alloc] init:self.currentCity.windSpeed];
    return [windSpeed windSpeedInUnit:self.speedUnit];
}

- (NSString *)windDirectionString {
    method_log();

    // Check if location services are enabled
    if (![self locationServicesEnabled])
        return @"Wind Direction Not Available";

    // Check if the temperature is 0 and the condition is Tornado, which indicates that the temperature is not available
    if (self.currentCity.temperature.fahrenheit == 0 && self.currentCity.conditionCode == Tornado)
        return @"Wind Direction Not Available";

    return [self.currentCity windDirectionAsString:self.currentCity.windDirection];
}

- (NSString *)cityString {
    method_log();

    // Check if location services are enabled
    if (![self locationServicesEnabled])
        return @"City Not Available";

    return self.currentCity.name;
}

#pragma mark CLLocationManagerDelegate methods

- (void)locationManager:(CLLocationManager *)manager didUpdateLocations:(NSArray*)locations {
    method_log(@"manager: %@, locations: %@", manager, locations);

    if (locations.count > 0) {
        CLLocation *newestLocation = [locations lastObject]; // Get the newest location
        
        // Check if the location has changed
        if (self.currentLocation == nil) {
            // First time getting a location, so save location and update weather
            self.currentLocation = newestLocation;
        } else {
            DCDistance *distance = [[DCDistance alloc] initWithMeters:[newestLocation distanceFromLocation:self.currentLocation]];
            debug_log("Distance from newestLocation to self.currentLocation: %.2f meters", [distance meters]);
            if ([distance meters] < [self.distanceThreshold meters]) { // less than threshold, not considered a new location
                debug_log("Distance is less than threshold, not considered a new location");
                return;
            } else {
                debug_log("Distance is greater than threshold, considered a new location");
                self.currentLocation = newestLocation; // greater than threshold, so save location and update weather
            }
        }

        // Refresh the weather with the new location
        [self _refreshWeatherWithLocation:newestLocation];
    }
}

#pragma mark City delegate methods

- (void)cityDidFinishWeatherUpdate:(City*)city {
    method_log(@"city: %@", city);

    // New city, so update the saved current city
    self.currentCity = city;

    // Post notification of location change
    [[NSNotificationCenter defaultCenter] postNotificationName:LOCATION_CHANGE_NOTIFICATION object:self];
}

@end

// Needed to swizzle SBScreenWakeAnimationController in order to know when the screen sleeps/wakes so we can stop/start the update timer
@implementation SBScreenWakeAnimationController (Swizzling)

+ (void)load {
    // Swizzle the _handleAnimationCompletionIfNecessaryForWaking: method
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        Class class = [self class];

        SEL originalSelector = @selector(_handleAnimationCompletionIfNecessaryForWaking:);
        SEL swizzledSelector = @selector(swizzled_handleAnimationCompletionIfNecessaryForWaking:);

        Method originalMethod = class_getInstanceMethod(class, originalSelector);
        Method swizzledMethod = class_getInstanceMethod(class, swizzledSelector);

        BOOL didAddMethod = class_addMethod(class,
                                            originalSelector,
                                            method_getImplementation(swizzledMethod),
                                            method_getTypeEncoding(swizzledMethod));

        if (didAddMethod) {
            class_replaceMethod(class,
                                swizzledSelector,
                                method_getImplementation(originalMethod),
                                method_getTypeEncoding(originalMethod));
        } else {
            method_exchangeImplementations(originalMethod, swizzledMethod);
        }
    });
}

- (void)swizzled_handleAnimationCompletionIfNecessaryForWaking:(BOOL)arg1 {
    // Call the original implementation
    [self swizzled_handleAnimationCompletionIfNecessaryForWaking:arg1];

    // Post a notification so DCWeather can be notified of the change
    [[NSNotificationCenter defaultCenter] postNotificationName:DEVICE_WAKE_NOTIFICATION
                                          object:nil
                                          userInfo:@{@"screenIsWaking": @(arg1)}];
}

@end