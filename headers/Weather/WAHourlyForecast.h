// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WAHOURLYFORECAST_H
#define WAHOURLYFORECAST_H

@class NSString, WFTemperature;

#import <Foundation/Foundation.h>

#import "NSCopying-Protocol.h"

@interface WAHourlyForecast : NSObject <NSCopying>



@property (nonatomic) NSInteger conditionCode; // ivar: _conditionCode
@property (nonatomic) NSUInteger eventType; // ivar: _eventType
@property (copy, nonatomic) NSString *forecastDetail; // ivar: _forecastDetail
@property (nonatomic) NSInteger hourIndex; // ivar: _hourIndex
@property (nonatomic) CGFloat percentPrecipitation; // ivar: _percentPrecipitation
@property (retain, nonatomic) WFTemperature *temperature; // ivar: _temperature
@property (copy, nonatomic) NSString *time; // ivar: _time


+(NSInteger)TimeValueFromString:(id)arg0 ;
+(id)hourlyForecastForLocation:(id)arg0 conditions:(id)arg1 sunriseDateComponents:(id)arg2 sunsetDateComponents:(id)arg3 ;
-(BOOL)isEqual:(id)arg0 ;
-(NSUInteger)hash;
-(id)copyWithZone:(struct _NSZone *)arg0 ;
-(id)description;


@end


#endif