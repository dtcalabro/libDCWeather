// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WACURRENTFORECAST_H
#define WACURRENTFORECAST_H

@class WFTemperature, NSString;

#import <Foundation/Foundation.h>

#import "NSCopying-Protocol.h"

@interface WACurrentForecast : NSObject <NSCopying>



@property (nonatomic) NSUInteger UVIndex; // ivar: _UVIndex
@property (nonatomic) NSInteger conditionCode; // ivar: _conditionCode
@property (nonatomic) float dewPoint; // ivar: _dewPoint
@property (retain, nonatomic) WFTemperature *feelsLike; // ivar: _feelsLike
@property (nonatomic) float humidity; // ivar: _humidity
@property (nonatomic) NSUInteger observationTime; // ivar: _observationTime
@property (nonatomic) float precipitationPast24Hours; // ivar: _precipitationPast24Hours
@property (nonatomic) float pressure; // ivar: _pressure
@property (nonatomic) NSUInteger pressureRising; // ivar: _pressureRising
@property (copy, nonatomic) NSString *providerName; // ivar: _providerName
@property (retain, nonatomic) WFTemperature *temperature; // ivar: _temperature
@property (nonatomic) float visibility; // ivar: _visibility
@property (nonatomic) float windDirection; // ivar: _windDirection
@property (nonatomic) float windSpeed; // ivar: _windSpeed


+(id)currentForecastForLocation:(id)arg0 conditions:(id)arg1 ;
-(BOOL)isEqual:(id)arg0 ;
-(NSUInteger)hash;
-(id)copyWithZone:(struct _NSZone *)arg0 ;
-(id)description;


@end


#endif