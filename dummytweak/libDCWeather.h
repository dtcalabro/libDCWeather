// libDCWeather.h
#import <Foundation/Foundation.h>

@interface libDCWeather : NSObject

+ (instancetype)sharedInstance;
- (void)conditionIncludesSevereWeather:(BOOL)conditionIncludesSevereWeather;
- (void)refreshLocation;
- (NSString *)temperatureString;
- (NSString *)conditionString;
- (UIImage *)conditionImage;
- (NSString *)cityString;

@end