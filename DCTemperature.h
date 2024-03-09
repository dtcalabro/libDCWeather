// DCTemperature.h
#import <Foundation/Foundation.h>
#import <WeatherFoundation/WFTemperature.h>

@interface DCTemperature : NSObject
@property (nonatomic) CGFloat temperature;
- (instancetype)init:(CGFloat)temperature;
- (double)temperatureInUserUnit;
- (double)temperatureInCelsius;
- (double)temperatureInFahrenheit;
@end