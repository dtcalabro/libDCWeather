// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WAFORECASTMODEL_H
#define WAFORECASTMODEL_H

@class WFAirQualityConditions, NSArray, NSURL, WFLocation, WFNextHourPrecipitation, NSDate, WFWeatherConditions;

#import <Foundation/Foundation.h>

#import "City.h"
#import "WACurrentForecast.h"
#import "NSCopying-Protocol.h"

@interface WAForecastModel : NSObject <NSCopying>



@property (retain, nonatomic) WFAirQualityConditions *airQualityConditions; // ivar: _airQualityConditions
@property (copy, nonatomic) NSArray *changeForecasts; // ivar: _changeForecasts
@property (retain, nonatomic) City *city; // ivar: _city
@property (retain, nonatomic) WACurrentForecast *currentConditions; // ivar: _currentConditions
@property (copy, nonatomic) NSArray *dailyForecasts; // ivar: _dailyForecasts
@property (retain, nonatomic) NSURL *deepLink; // ivar: _deepLink
@property (copy, nonatomic) NSArray *hourlyForecasts; // ivar: _hourlyForecasts
@property (readonly, nonatomic) BOOL isPopulated;
@property (retain, nonatomic) NSURL *link; // ivar: _link
@property (retain, nonatomic) WFLocation *location; // ivar: _location
@property (copy, nonatomic) WFNextHourPrecipitation *nextHourPrecipitation; // ivar: _nextHourPrecipitation
@property (copy, nonatomic) NSArray *severeWeatherEvents; // ivar: _severeWeatherEvents
@property (retain, nonatomic) NSDate *sunrise; // ivar: _sunrise
@property (retain, nonatomic) NSDate *sunset; // ivar: _sunset
@property (retain, nonatomic) WFWeatherConditions *underlyingCurrentConditions; // ivar: _underlyingCurrentConditions
@property (retain, nonatomic) NSArray *underlyingDailyConditions; // ivar: _underlyingDailyConditions
@property (retain, nonatomic) NSArray *underlyingHourlyConditions; // ivar: _underlyingHourlyConditions
@property (nonatomic) int unit; // ivar: _unit


-(BOOL)isEqual:(id)arg0 ;
-(NSUInteger)hash;
-(id)copyWithZone:(struct _NSZone *)arg0 ;
-(id)description;


@end


#endif