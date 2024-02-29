// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFAGGREGATECOMMONFORECAST_H
#define WFAGGREGATECOMMONFORECAST_H

@class NSArray;

#import <Foundation/Foundation.h>

#import "WFAirQualityConditions.h"
#import "WFWeatherConditions.h"
#import "WFNextHourPrecipitation.h"

@interface WFAggregateCommonForecast : NSObject

@property (retain, nonatomic) WFAirQualityConditions *airQualityObservations; // ivar: _airQualityObservations
@property (retain, nonatomic) NSArray *changeForecasts; // ivar: _changeForecasts
@property (retain, nonatomic) WFWeatherConditions *currentObservations; // ivar: _currentObservations
@property (retain, nonatomic) NSArray *dailyForecastedConditions; // ivar: _dailyForecastedConditions
@property (retain, nonatomic) NSArray *dailyPollenForecastedConditions; // ivar: _dailyPollenForecastedConditions
@property (retain, nonatomic) NSArray *hourlyForecastedConditions; // ivar: _hourlyForecastedConditions
@property (retain, nonatomic) NSArray *lastTwentyFourHoursOfObservations; // ivar: _lastTwentyFourHoursOfObservations
@property (retain, nonatomic) WFNextHourPrecipitation *nextHourPrecipitation; // ivar: _nextHourPrecipitation
@property (retain, nonatomic) NSArray *severeWeatherEvents; // ivar: _severeWeatherEvents




@end


#endif