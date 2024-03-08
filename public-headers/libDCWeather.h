// public libDCWeather.h
#import <Foundation/Foundation.h>

@interface DCWeather : NSObject
+ (instancetype)sharedInstance;
- (void)requestRefresh;
- (void)setAutoUpdateInvervalInSeconds:(NSInteger)interval;
- (void)setAutoUpdateInvervalInMinutes:(NSInteger)interval;
- (void)setAutoUpdateInvervalInHours:(NSInteger)interval;
- (void)conditionIncludesSevereWeather:(BOOL)conditionIncludesSevereWeather;
- (NSString *)temperatureString;
- (NSString *)conditionString;
- (UIImage *)conditionImage;
- (NSString *)cityString;
@end