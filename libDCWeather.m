// libDCWeather.m
#import "libDCWeather.h"
#import <os/log.h>
#include <dlfcn.h>
#import <CoreLocation/CoreLocation.h>

#define DEGREE_SYMBOL @"\u00B0"

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
		_sharedSelf = [[libDCWeather alloc] init];
        [_sharedSelf refreshLocation];
	});
	return _sharedSelf;
}

- (instancetype)init {
    self = [super init];
    if (self) {
        // Initialization code here
        self.conditionIncludesSevereWeather = NO;
        [self refreshLocation];
    }
    return self;
}

- (void)refreshLocation {
    //debug_log("refreshLocation");
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        WeatherPreferences *weatherPreferences = [WeatherPreferences sharedPreferences];
        debug_log("isLocalWeatherEnabled: %d", [weatherPreferences isLocalWeatherEnabled]);
        _localWeatherCity = [weatherPreferences localWeatherCity];
        [_localWeatherCity update];
        debug_log("locationServicesEnabled: %d", [CLLocationManager locationServicesEnabled]);
    });
}

- (BOOL)locationServicesEnabled {
    //debug_log("locationServicesEnabled");
    if (![[WeatherPreferences sharedPreferences] isLocalWeatherEnabled] || ![CLLocationManager locationServicesEnabled]) {
        return NO;
    }
    return YES;
}

- (void)conditionIncludesSevereWeather:(BOOL)conditionIncludesSevereWeather {
    //debug_log("conditionIncludesSevereWeather");
    _conditionIncludesSevereWeather = conditionIncludesSevereWeather;
}

- (NSString *)temperatureString {
    //debug_log("temperatureString");

    if (![self locationServicesEnabled]) {
        return @"Temperature Not Available";
    }

    WFTemperature *temperature = [_localWeatherCity temperature];
    debug_log("City: %s, Temperature: %f %.0f%s", [_localWeatherCity.name UTF8String], temperature.fahrenheit, temperature.fahrenheit, [DEGREE_SYMBOL UTF8String]);
    return [NSString stringWithFormat:@"%.0f%@", temperature.fahrenheit, DEGREE_SYMBOL];

}

- (NSString *)conditionString {
    //debug_log("conditionString");

    if (![self locationServicesEnabled]) {
        return @"Condition Not Available";
    }

    // Check for severe weather condition if enabled
    if (self.conditionIncludesSevereWeather) {
        if (_localWeatherCity.severeWeatherEvents.count > 0) {
            WFSevereWeatherEvent *severeWeatherEvent = _localWeatherCity.severeWeatherEvents[0];
            return severeWeatherEvent.eventDescription;
        }
    }

    //debug_log("%s", [[_localWeatherCity naturalLanguageDescription] UTF8String]);

    //debug_log("wind speed: %f", _localWeatherCity.windSpeed);

    // Manually check wind speed for windy condition
    if (_localWeatherCity.windSpeed > 15) {
        //return @"Windy";
    }

    /*
    NSString *(*NSStringFromWeatherConditionCode)(int code);

    void *handle = dlopen("/System/Library/PrivateFrameworks/Weather.framework/Weather", RTLD_LAZY);
    if (handle) {
        NSStringFromWeatherConditionCode = dlsym(handle, "NSStringFromWeatherConditionCode");
        if (NSStringFromWeatherConditionCode) {
            for (int i = 0; i < 195; i++) {
                NSString *conditionString = NSStringFromWeatherConditionCode(i);
                debug_log("%i - conditionString: %s", i, [conditionString UTF8String]);
            }
        }
    }
    */

    // Check for regular weather condition
    switch (_localWeatherCity.conditionCode) {
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
            return @"Mostly Sunny";
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
            return [NSString stringWithFormat:@"Unknown (%ld)", _localWeatherCity.conditionCode];
    }
}

- (UIImage *)conditionImage {
    //debug_log("conditionImage");

    if (![self locationServicesEnabled]) {
        return nil;
    }

    // Check for severe weather condition if enabled
    if (self.conditionIncludesSevereWeather) {
        if (_localWeatherCity.severeWeatherEvents.count > 0) {
            WFSevereWeatherEvent *severeWeatherEvent = _localWeatherCity.severeWeatherEvents[0];
            // TODO: Add severe weather condition images
        }
    }

    /*
    // Manually check wind speed for windy condition
    if (_localWeatherCity.windSpeed > 15) {
        return [UIImage systemImageNamed:@"wind"];
    }
    */

    // Check for regular weather condition
    switch (_localWeatherCity.conditionCode) {
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

    if (![self locationServicesEnabled]) {
        return @"City Not Available";
    }

    return _localWeatherCity.name;
}

@end