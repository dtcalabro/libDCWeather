// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFPARSEDFORECASTDATA_H
#define WFPARSEDFORECASTDATA_H

@class NSArray, NSData;

#import <Foundation/Foundation.h>

#import "WFAirQualityConditions.h"
#import "WFWeatherConditions.h"
#import "WFNextHourPrecipitation.h"

@interface WFParsedForecastData : NSObject

@property (retain, nonatomic) WFAirQualityConditions *airQualityObservations; // ivar: _airQualityObservations
@property (retain, nonatomic) NSArray *changeForecasts; // ivar: _changeForecasts
@property (retain, nonatomic) WFWeatherConditions *currentConditions; // ivar: _currentConditions
@property (retain, nonatomic) NSArray *dailyForecasts; // ivar: _dailyForecasts
@property (retain, nonatomic) NSArray *hourlyForecasts; // ivar: _hourlyForecasts
@property (retain, nonatomic) NSArray *lastTwentyFourHoursOfObservations; // ivar: _lastTwentyFourHoursOfObservations
@property (retain, nonatomic) WFNextHourPrecipitation *nextHourPrecipitation; // ivar: _nextHourPrecipitation
@property (retain, nonatomic) NSArray *pollenForecasts; // ivar: _pollenForecasts
@property (retain, nonatomic) NSData *rawData; // ivar: _rawData
@property (retain, nonatomic) NSArray *severeWeatherEvents; // ivar: _severeWeatherEvents


-(id)objectForForecastType:(NSUInteger)arg0 ;


@end


#endif