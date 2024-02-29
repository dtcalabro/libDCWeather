// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFWEATHERCHANNELPARSERV3_H
#define WFWEATHERCHANNELPARSERV3_H

@class NSCalendar, NSString;

#import <Foundation/Foundation.h>

#import "WFForecastDataParser-Protocol.h"

@interface WFWeatherChannelParserV3 : NSObject <WFForecastDataParser>



@property (readonly, nonatomic) NSCalendar *calendar; // ivar: _calendar
@property (readonly, copy) NSString *debugDescription;
@property (readonly, copy) NSString *description;
@property (readonly) NSUInteger hash;
@property (readonly) Class superclass;


-(id)_parseCurrentConditions:(id)arg0 ;
-(id)_parseDailyForecastedConditions:(id)arg0 ;
-(id)_parseDailyPollenForecastedConditions:(id)arg0 ;
// -(id)_parseForecastedConditions:(id)arg0 individualForecastProcessingBlock:(id)arg1 uniqueParsingBlock:(unk)arg2  ;
-(id)_parseHourlyForecastedConditions:(id)arg0 ;
-(id)_parseLastTwentyFourHoursOfObservations:(id)arg0 ;
-(id)_parsePollutants:(id)arg0 ;
-(id)init;
-(id)parseAirQualityData:(id)arg0 location:(id)arg1 locale:(id)arg2 error:(id*)arg3 ;
-(id)parseForecastData:(id)arg0 types:(NSUInteger)arg1 location:(id)arg2 locale:(id)arg3 date:(id)arg4 error:(id*)arg5 ;
-(id)parseForecastData:(id)arg0 types:(NSUInteger)arg1 location:(id)arg2 locale:(id)arg3 date:(id)arg4 error:(id*)arg5 rules:(id)arg6 ;
-(void)_parseCommonComponents:(id)arg0 intoConditions:(id)arg1 ;
-(void)_parseWebLinks:(id)arg0 intoWeatherConditions:(id)arg1 ;


@end


#endif