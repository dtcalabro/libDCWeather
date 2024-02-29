// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFWEATHERUNDERGROUNDPARSER_H
#define WFWEATHERUNDERGROUNDPARSER_H

@class NSString;

#import <Foundation/Foundation.h>

#import "WFForecastDataParser-Protocol.h"

@interface WFWeatherUndergroundParser : NSObject <WFForecastDataParser>



@property (readonly, copy) NSString *debugDescription;
@property (readonly, copy) NSString *description;
@property (readonly) NSUInteger hash;
@property (readonly) Class superclass;


+(NSUInteger)conditionFromWeatherUndergroundPhrase:(id)arg0 ;
+(NSUInteger)expectedDailyForecastCount;
+(NSUInteger)expectedHourlyForecastCount;
+(id)componentsForCurrentForecast;
+(id)componentsForDailyForecasts;
+(id)componentsForHourlyForecasts;
-(id)dateFromUTCDict:(id)arg0 toUnitGranularity:(NSUInteger)arg1 ;
-(id)parseForecastData:(id)arg0 types:(NSUInteger)arg1 location:(id)arg2 locale:(id)arg3 date:(id)arg4 error:(id*)arg5 ;
-(id)parseForecastData:(id)arg0 types:(NSUInteger)arg1 location:(id)arg2 locale:(id)arg3 date:(id)arg4 error:(id*)arg5 rules:(id)arg6 ;
-(id)parseHistoricalForecast:(id)arg0 error:(id*)arg1 ;
-(id)sanitizedNumberForKeyPath:(id)arg0 dict:(id)arg1 ;
-(id)sanitizedTemperatureForCelsiusKeyPath:(id)arg0 fahrenheitKeyPath:(id)arg1 dict:(id)arg2 ;
-(void)logParsingErrorAtKeyPath:(id)arg0 error:(id*)arg1 ;


@end


#endif