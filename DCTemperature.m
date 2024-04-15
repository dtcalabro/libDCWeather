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

- (double)temperatureInUnit:(enum TemperatureUnit)unit {
    switch (unit) {
        case SystemTemperatureUnit:
            return [self temperatureInUserUnit];
        case Celsius:
            return [self temperatureInCelsius];
        case Fahrenheit:
            return [self temperatureInFahrenheit];
        case Kelvin:
            return [self temperatureInKelvin];
    }
}

- (double)temperatureInCelsius {
    return round((self.temperature - 32) * 5.0 / 9.0);
}

- (double)temperatureInFahrenheit {
    return round(self.temperature);
}

- (double)temperatureInKelvin {
    return round((self.temperature - 32) * 5.0 / 9.0 + 273.15);
}

@end