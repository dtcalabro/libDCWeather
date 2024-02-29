// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WAFORECASTOPERATION_H
#define WAFORECASTOPERATION_H

@class NSOperation, WFAggregateCommonRequest, WFAirQualityConditions, NSCalendar, NSArray, WFServiceConnection, WFWeatherConditions, NSError, NSDictionary, NSLocale, WFLocation, WFNextHourPrecipitation, NSData, WFRequestOptions, NSDate, NSString;


#import "City.h"
#import "WACurrentForecast.h"
#import "WAForecastModel.h"

@interface WAForecastOperation : NSOperation

@property (retain, nonatomic) WFAggregateCommonRequest *aggregateRequest; // ivar: _aggregateRequest
@property (retain, nonatomic) WFAirQualityConditions *airQualityConditions; // ivar: _airQualityConditions
@property (retain, nonatomic) NSCalendar *calendar; // ivar: _calendar
@property (nonatomic) BOOL canGeocode; // ivar: _canGeocode
@property (retain, nonatomic) NSArray *changeForecasts; // ivar: _changeForecasts
@property (retain, nonatomic) City *city; // ivar: _city
@property (retain, nonatomic) WFServiceConnection *connection; // ivar: _connection
@property (retain, nonatomic) WACurrentForecast *currentConditions; // ivar: _currentConditions
@property (retain, nonatomic) WFWeatherConditions *currentWeatherConditions; // ivar: _currentWeatherConditions
@property (retain, nonatomic) NSArray *dailyForecastConditions; // ivar: _dailyForecastConditions
@property (retain, nonatomic) NSArray *dailyForecasts; // ivar: _dailyForecasts
@property (retain, nonatomic) NSError *error; // ivar: _error
@property (readonly, nonatomic) WAForecastModel *forecastModel;
@property (retain, nonatomic) NSArray *hourlyForecastConditions; // ivar: _hourlyForecastConditions
@property (retain, nonatomic) NSArray *hourlyForecasts; // ivar: _hourlyForecasts
@property (nonatomic) BOOL isDay; // ivar: _isDay
@property (nonatomic) BOOL isLocationInGeocodeSample; // ivar: _isLocationInGeocodeSample
@property (retain, nonatomic) NSDictionary *links; // ivar: _links
@property (retain) NSLocale *locale; // ivar: _locale
@property (retain, nonatomic) WFLocation *location; // ivar: _location
@property (retain, nonatomic) WFNextHourPrecipitation *nextHourPrecipitation; // ivar: _nextHourPrecipitation
@property (retain, nonatomic) NSData *rawAPIData; // ivar: _rawAPIData
@property (retain, nonatomic) WFRequestOptions *requestOptions; // ivar: _requestOptions
@property (retain, nonatomic) NSArray *severeWeatherEvents; // ivar: _severeWeatherEvents
@property (nonatomic) BOOL shouldAttachRawAPIData; // ivar: _shouldAttachRawAPIData
@property (retain, nonatomic) NSDate *sunrise; // ivar: _sunrise
@property (retain, nonatomic) NSDate *sunset; // ivar: _sunset
@property (retain) NSString *trackingParameter; // ivar: _trackingParameter
@property (nonatomic) int units; // ivar: _units


-(BOOL)shouldRequestChangeInConditions;
-(id)initWithCity:(id)arg0 onConnection:(id)arg1 ;
-(id)initWithCity:(id)arg0 withUnits:(int)arg1 canGeocode:(BOOL)arg2 onConnection:(id)arg3 ;
-(id)initWithCity:(id)arg0 withUnits:(int)arg1 onConnection:(id)arg2 ;
-(id)initWithCity:(id)arg0 withUnits:(int)arg1 requestOptions:(id)arg2 canGeocode:(BOOL)arg3 onConnection:(id)arg4 ;
-(id)initWithLocation:(id)arg0 onConnection:(id)arg1 ;
-(void)_determineSunriseAndSunset;
-(void)_failWithError:(id)arg0 ;
-(void)_mapReferralLinks;
-(void)cancel;
-(void)main;


@end


#endif