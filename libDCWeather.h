// libDCWeather.h
#import <Foundation/Foundation.h>
#import <Weather/Weather.h>
#import <WeatherFoundation/WeatherFoundation.h>
#import <CoreLocation/CoreLocation.h>
#import "DCDistance.h"
#import "DCTime.h"

@interface DCWeather : NSObject <CLLocationManagerDelegate, CityUpdateObserver>
@property (nonatomic, strong) City *currentCity;
@property (nonatomic, strong) CLLocation *currentLocation; 
@property (nonatomic, strong) WeatherLocationManager* weatherLocationManager;
@property (nonatomic, strong) NSTimer *updateTimer;
@property (nonatomic, retain) NSDate *nextUpdateTime;
@property (nonatomic) BOOL conditionIncludesSevereWeather;
@property (nonatomic) DCTime *updateInterval;
@property (nonatomic) DCDistance *distanceThreshold;
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
- (NSString *)temperatureString;
- (NSString *)conditionString;
- (UIImage *)conditionImage;
- (NSString *)cityString;
@end

@interface CLLocationManager (Private)
- (id)appsUsingLocation;
+ (void)setAuthorizationStatus:(bool)arg1 forBundle:(id)arg2;
+ (void)setAuthorizationStatus:(bool)arg1 forBundleIdentifier:(id)arg2;
+ (void)setAuthorizationStatusByType:(int)arg1 forBundle:(id)arg2;
+ (void)setAuthorizationStatusByType:(int)arg1 forBundleIdentifier:(id)arg2;
+ (void)setBackgroundIndicatorEnabled:(bool)arg1 forBundle:(id)arg2;
+ (void)setBackgroundIndicatorEnabled:(bool)arg1 forBundleIdentifier:(id)arg2;
+ (void)setBackgroundIndicatorEnabled:(bool)arg1 forLocationDictionary:(id)arg2;
@end

@interface CLApproved : CLLocationManager
+ (int)authorizationStatusForBundleIdentifier:(id)arg1;
@end