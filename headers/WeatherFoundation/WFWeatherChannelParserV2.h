// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFWEATHERCHANNELPARSERV2_H
#define WFWEATHERCHANNELPARSERV2_H

@class NSCalendar, NSString;

#import <Foundation/Foundation.h>

#import "WFForecastDataParser-Protocol.h"

@interface WFWeatherChannelParserV2 : NSObject <WFForecastDataParser>



@property (retain, nonatomic) NSCalendar *calendar; // ivar: _calendar
@property (readonly, copy) NSString *debugDescription;
@property (readonly, copy) NSString *description;
@property (readonly) NSUInteger hash;
@property (readonly) Class superclass;


+(NSUInteger)expectedDailyForecastCount;
+(NSUInteger)expectedHourlyForecastCount;
+(id)componentsForCurrentForecast;
+(id)componentsForDailyForecasts;
+(id)componentsForHourlyForecasts;
-(NSUInteger)_pressureTrendFromWeatherChannelCode:(id)arg0 ;
-(id)init;
-(id)parseAirQualityData:(id)arg0 location:(id)arg1 error:(id*)arg2 ;
-(id)parseCurrentCondition:(id)arg0 ;
-(id)parseDailyForecasts:(id)arg0 ;
-(id)parseForecastData:(id)arg0 types:(NSUInteger)arg1 location:(id)arg2 locale:(id)arg3 date:(id)arg4 error:(id*)arg5 ;
-(id)parseForecastData:(id)arg0 types:(NSUInteger)arg1 location:(id)arg2 locale:(id)arg3 date:(id)arg4 error:(id*)arg5 rules:(id)arg6 ;
-(id)parseHourlyForecasts:(id)arg0 ;
-(void)parseCommonComponents:(id)arg0 data:(id)arg1 ;


@end


#endif