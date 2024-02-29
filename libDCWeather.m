// libDCWeather.m
#import "libDCWeather.h"
#import <os/log.h>

#define DEGREE_SYMBOL @"\u00B0"

#define debug_log(...) ({\
	if (LDCW_DEBUG) {\
		char* str; \
		asprintf(&str, __VA_ARGS__); \
		os_log(OS_LOG_DEFAULT, "[LDCW_DEBUG] %s", str); \
	}\
})

enum ConditionCode {
    Showers = 11,
    Rain = 12,
    Cloudy = 26,
    MostlyCloudy = 28,
    Sunny = 32
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
    WeatherPreferences *weatherPreferences = [WeatherPreferences sharedPreferences];
    _localWeatherCity = [weatherPreferences localWeatherCity];
    [_localWeatherCity update];
}

- (void)conditionIncludesSevereWeather:(BOOL)conditionIncludesSevereWeather {
    _conditionIncludesSevereWeather = conditionIncludesSevereWeather;
}

- (NSString *)temperatureString {
    //NSLog(@"[libDCWeather] temperatureString");
    /*
    WeatherPreferences *weatherPreferences = [WeatherPreferences sharedPreferences];
    City *localCity = [weatherPreferences localWeatherCity];
    [localCity update];
    WFTemperature *temperature = [localCity temperature];
    */
    WFTemperature *temperature = [_localWeatherCity temperature];
    //NSLog(@"Temperature: %f", temperature.fahrenheit);
    //return [localCity temperatureString];
    //return @"80";
    debug_log("Temperature: %f %.0f%s", temperature.fahrenheit, temperature.fahrenheit, [DEGREE_SYMBOL UTF8String]);
    return [NSString stringWithFormat:@"%.0f%@", temperature.fahrenheit, DEGREE_SYMBOL];
    //return [NSString stringWithFormat:@"%f", temperature.fahrenheit];
}

- (NSString *)conditionString {
    //NSLog(@"[libDCWeather] conditionString");

    /*
    ATM, the condition codes that I know of are as follows:
    11 - Showers
    12 - Rain     (Showers)
    26 - Cloudy
    28 - Mostly Cloudy
    32 - Sunny
    */

    if (self.conditionIncludesSevereWeather) {
        if (_localWeatherCity.severeWeatherEvents.count > 0) {
            WFSevereWeatherEvent *severeWeatherEvent = _localWeatherCity.severeWeatherEvents[0];
            return severeWeatherEvent.eventDescription;
        }
    }

    /*
    if (_localWeatherCity.conditionCode == 11) {
        return @"Showers (11)";
    } else if (_localWeatherCity.conditionCode == 12) {
        return @"Rain (12)";
    } else if (_localWeatherCity.conditionCode == 26) {
        return @"Cloudy (26)";
    } else if (_localWeatherCity.conditionCode == 28) {
        return @"Mostly Cloudy (28)";
    } else if (_localWeatherCity.conditionCode == 32) {
        return @"Sunny (32)";
    } else {
        return [NSString stringWithFormat:@"Unknown (%ld)", _localWeatherCity.conditionCode];
    }
    */

    switch (_localWeatherCity.conditionCode) {
        case Showers:
            return @"Showers (11)";
        case Rain:
            return @"Rain (12)";
        case Cloudy:
            return @"Cloudy (26)";
        case MostlyCloudy:
            return @"Mostly Cloudy (28)";
        case Sunny:
            return @"Sunny (32)";
        default:
            return [NSString stringWithFormat:@"Unknown (%ld)", _localWeatherCity.conditionCode];
    }
}

- (UIImage *)conditionImage {
    //NSLog(@"[libDCWeather] conditionImage");

    switch (_localWeatherCity.conditionCode) {
        case Showers:
            return [UIImage systemImageNamed:@""];
        case Rain:
            return [UIImage systemImageNamed:@""];
        case Cloudy:
            return [UIImage systemImageNamed:@"cloud.fill"];
        case MostlyCloudy:
            return [UIImage systemImageNamed:@"cloud.fill"];
        case Sunny:
            return [UIImage systemImageNamed:@""];
        default:
            return [UIImage systemImageNamed:@"questionmark.circle.fill"];
    }

    //return _localWeatherCity.conditionImage;
}

- (NSString *)cityString {
    //NSLog(@"[libDCWeather] cityString");
    return _localWeatherCity.name;
}

@end