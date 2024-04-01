// DCTemperature.m
#import "DCTemperature.h"
#import <objc/runtime.h>
#import <Weather/WeatherPreferences.h>

@implementation DCTemperature

- (instancetype)init:(CGFloat)temperature {
    self = [super init];
    if (self) {
        self.temperature = temperature;
    }
    return self;
}

- (double)temperatureInUserUnit {
    return [[objc_getClass("WeatherPreferences") sharedPreferences] isCelsius] ? [self temperatureInCelsius] : [self temperatureInFahrenheit];
}

- (double)temperatureInCelsius {
    return round((self.temperature - 32) * 5.0 / 9.0);
}

- (double)temperatureInFahrenheit {
    return round(self.temperature);
}

@end