// DCTime.h
#import <Foundation/Foundation.h>

@interface DCTime : NSObject
@property (nonatomic) double time;
- (instancetype)initWithSeconds:(double)seconds;
- (instancetype)initWithMinutes:(double)minutes;
- (instancetype)initWithHours:(double)hours;
- (instancetype)initWithDays:(double)days;
- (instancetype)initWithMonths:(double)months;
- (double)seconds;
- (double)minutes;
- (double)hours;
- (double)days;
- (double)months;
@end