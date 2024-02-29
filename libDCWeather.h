// libDCWeather.h
#import <Foundation/Foundation.h>
#import <Weather/Weather.h>
#import <WeatherFoundation/WeatherFoundation.h>

@interface libDCWeather : NSObject

@property (nonatomic) BOOL conditionIncludesSevereWeather;
@property (nonatomic, retain) City *localWeatherCity;

+ (instancetype)sharedInstance;
- (void)conditionIncludesSevereWeather:(BOOL)conditionIncludesSevereWeather;
- (void)refreshLocation;
- (NSString *)temperatureString;
- (NSString *)conditionString;
- (UIImage *)conditionImage;
- (NSString *)cityString;

@end