// libDCWeather.h
#import <Foundation/Foundation.h>
#import <Weather/Weather.h>
#import <WeatherFoundation/WeatherFoundation.h>

@interface libDCWeather : NSObject

@property (nonatomic) BOOL conditionIncludesSevereWeather;
@property (nonatomic, retain) City *localWeatherCity;

+ (instancetype)sharedInstance;
- (void)refreshLocation;
- (BOOL)locationServicesEnabled;
- (void)conditionIncludesSevereWeather:(BOOL)conditionIncludesSevereWeather;
- (NSString *)temperatureString;
- (NSString *)conditionString;
- (UIImage *)conditionImage;
- (NSString *)cityString;

@end