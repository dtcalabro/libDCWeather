// DCWind.h
#import <Foundation/Foundation.h>

enum SpeedUnit {
    SystemSpeedUnit,
    KiloMetersPerHour,
    MilesPerHour
};

@interface DCWindSpeed : NSObject
@property (nonatomic) CGFloat windSpeed;
- (instancetype)init:(CGFloat)windSpeed;
- (BOOL)usesMetricSystem;
- (double)windSpeedInUserUnit;
- (NSString *)windSpeedInUserUnitString;
- (double)windSpeedInUnit:(enum SpeedUnit)unit;
- (NSString *)windSpeedInUnitString:(enum SpeedUnit)unit;
- (double)windSpeedInKiloMetersPerHour;
- (NSString *)windSpeedInKiloMetersPerHourString;
- (double)windSpeedInMilesPerHour;
- (NSString *)windSpeedInMilesPerHourString;
@end