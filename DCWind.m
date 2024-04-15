// DCWind.m
#import "DCWind.h"
#import <objc/runtime.h>
#import <Weather/WeatherWindSpeedFormatter.h>

@implementation DCWindSpeed

- (instancetype)init:(CGFloat)windSpeed {
    self = [super init];
    if (self) {
        self.windSpeed = windSpeed;
    }
    return self;
}

- (BOOL)usesMetricSystem {
    return [[[[[objc_getClass("WeatherWindSpeedFormatter") alloc] init] locale] objectForKey:NSLocaleMeasurementSystem] isEqualToString:@"Metric"];
}

- (double)windSpeedInUserUnit {
    return [self usesMetricSystem] ? [self windSpeedInKiloMetersPerHour] : [self windSpeedInMilesPerHour];
}

- (NSString *)windSpeedInUserUnitString {
    return [self usesMetricSystem] ? [self windSpeedInKiloMetersPerHourString] : [self windSpeedInMilesPerHourString];
}

- (double)windSpeedInUnit:(enum SpeedUnit)unit {
    switch (unit) {
        case SystemSpeedUnit:
            return [self windSpeedInUserUnit];
        case KiloMetersPerHour:
            return [self windSpeedInKiloMetersPerHour];
        case MilesPerHour:
            return [self windSpeedInMilesPerHour];
    }
}

- (NSString *)windSpeedInUnitString:(enum SpeedUnit)unit {
    switch (unit) {
        case SystemSpeedUnit:
            return [self windSpeedInUserUnitString];
        case KiloMetersPerHour:
            return [self windSpeedInKiloMetersPerHourString];
        case MilesPerHour:
            return [self windSpeedInMilesPerHourString];
    }
}

- (double)windSpeedInKiloMetersPerHour {
    return round(self.windSpeed);
}

- (NSString *)windSpeedInKiloMetersPerHourString {
    return [NSString stringWithFormat:@"%.0f %@", [self windSpeedInKiloMetersPerHour], @"km/h"];
}

- (double)windSpeedInMilesPerHour {
    return round((self.windSpeed * 0.62137119223733));
}

- (NSString *)windSpeedInMilesPerHourString {
    return [NSString stringWithFormat:@"%.0f %@", [self windSpeedInMilesPerHour], @"mph"];
}

@end