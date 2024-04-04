// public libDCWeather.h
#import <Foundation/Foundation.h>

typedef enum TemperatureUnit {
    Celsius,
    Fahrenheit,
    Kelvin
} TemperatureUnit;

@interface DCWeather : NSObject
+ (instancetype)sharedInstance;
- (void)requestRefresh;
- (void)setAutoUpdateInvervalInSeconds:(NSInteger)interval;
- (void)setAutoUpdateInvervalInMinutes:(NSInteger)interval;
- (void)setAutoUpdateInvervalInHours:(NSInteger)interval;
- (void)setDistanceThresholdToConsiderLocationChangeInMeters:(double)distanceThreshold;
- (void)setDistanceThresholdToConsiderLocationChangeInKilometers:(double)distanceThreshold;
- (void)setDistanceThresholdToConsiderLocationChangeInFeet:(double)distanceThreshold;
- (void)setDistanceThresholdToConsiderLocationChangeInYards:(double)distanceThreshold;
- (void)setDistanceThresholdToConsiderLocationChangeInMiles:(double)distanceThreshold;
- (void)conditionIncludesSevereWeather:(BOOL)conditionIncludesSevereWeather;
- (void)setTemperatureUnit:(enum TemperatureUnit)unit;
- (NSString *)temperatureString;
- (double)temperature;
- (NSString *)feelsLikeTemperatureString;
- (double)feelsLikeTemperature;
- (NSString *)conditionString;
- (UIImage *)conditionImage;
- (NSString *)cityString;
@end