// DCTemperature.h
#import <Foundation/Foundation.h>

enum TemperatureUnit {
    Celsius = 0,
    Fahrenheit = 1,
    Kelvin = 2
};

@interface DCTemperature : NSObject
@property (nonatomic) CGFloat temperature;
- (instancetype)init:(CGFloat)temperature;
- (double)temperatureInUserUnit;
- (double)temperatureInUnit:(enum TemperatureUnit)unit;
- (double)temperatureInCelsius;
- (double)temperatureInFahrenheit;
- (double)temperatureInKelvin;
@end