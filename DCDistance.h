// DCDistance.h
#import <Foundation/Foundation.h>

@interface DCDistance : NSObject
@property (nonatomic) double distance;
- (instancetype)initWithMeters:(double)distance;
- (instancetype)initWithKilometers:(double)distance;
- (instancetype)initWithFeet:(double)distance;
- (instancetype)initWithYards:(double)distance;
- (instancetype)initWithMiles:(double)distance;
+ (double)meters:(double)distance;
+ (double)kilometers:(double)distance;
+ (double)feet:(double)distance;
+ (double)yards:(double)distance;
+ (double)miles:(double)distance;
- (double)meters;
- (double)kilometers;
- (double)feet;
- (double)yards;
- (double)miles;
@end