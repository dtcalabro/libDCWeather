// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFWEATHERHISTORICAL1DAYPARSERV2_H
#define WFWEATHERHISTORICAL1DAYPARSERV2_H

@class NSString;

#import <Foundation/Foundation.h>

#import "WFForecastDataParser-Protocol.h"

@interface WFWeatherHistorical1DayParserV2 : NSObject <WFForecastDataParser>



@property (readonly, copy) NSString *debugDescription;
@property (readonly, copy) NSString *description;
@property (readonly) NSUInteger hash;
@property (readonly) Class superclass;


-(id)parseForecastConditionsFromObservations:(id)arg0 ;
-(id)parseForecastData:(id)arg0 types:(NSUInteger)arg1 location:(id)arg2 locale:(id)arg3 date:(id)arg4 error:(id*)arg5 ;
-(id)parseForecastData:(id)arg0 types:(NSUInteger)arg1 location:(id)arg2 locale:(id)arg3 date:(id)arg4 error:(id*)arg5 rules:(id)arg6 ;
-(id)parseHistoricalForecast:(id)arg0 location:(id)arg1 date:(id)arg2 error:(id*)arg3 ;
-(id)parseHistoricalForecastConditionsFromObservations:(id)arg0 forDate:(id)arg1 ;


@end


#endif