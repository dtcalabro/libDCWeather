// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFWEATHERDATASERVICEPARSERV1_H
#define WFWEATHERDATASERVICEPARSERV1_H

@class NSString;

#import <Foundation/Foundation.h>

#import "WFForecastDataParser-Protocol.h"

@interface WFWeatherDataServiceParserV1 : NSObject <WFForecastDataParser>



@property (readonly, copy) NSString *debugDescription;
@property (readonly, copy) NSString *description;
@property (readonly) NSUInteger hash;
@property (readonly) Class superclass;


+(id)dateFormatter;
+(id)dateFormatter;
-(BOOL)isProviderAttribution:(id)arg0 stillValidWithMetadata:(id)arg1 ;
-(id)airQualityDictFromData:(id)arg0 types:(NSUInteger)arg1 ;
-(id)changeForecastDictFromData:(id)arg0 types:(NSUInteger)arg1 ;
-(id)currentObservationsDictFromData:(id)arg0 types:(NSUInteger)arg1 ;
-(id)dailyAlmanacDictFromData:(id)arg0 types:(NSUInteger)arg1 ;
-(id)dailyForecastDictFromData:(id)arg0 types:(NSUInteger)arg1 ;
-(id)dailyHistoryDictFromData:(id)arg0 types:(NSUInteger)arg1 ;
-(id)hourlyForecastDictFromData:(id)arg0 types:(NSUInteger)arg1 ;
-(id)hourlyHistoryDictFromData:(id)arg0 types:(NSUInteger)arg1 ;
-(id)nextHourPrecipitationEventDictFromData:(id)arg0 types:(NSUInteger)arg1 ;
-(id)nowLinksDictFromData:(id)arg0 types:(NSUInteger)arg1 ;
-(id)parseAQIScaleNamed:(id)arg0 data:(id)arg1 error:(id*)arg2 ;
-(id)parseAirQualityFromData:(id)arg0 locale:(id)arg1 ;
-(id)parseAlmanacFromData:(id)arg0 withUnit:(int)arg1 ;
-(id)parseChangeForecastFromData:(id)arg0 withUnit:(int)arg1 ;
-(id)parseCurrentObservationsFromData:(id)arg0 withUnit:(int)arg1 ;
-(id)parseDailyForecastFromData:(id)arg0 withUnit:(int)arg1 ;
-(id)parseDailyHistoryFromData:(id)arg0 withUnit:(int)arg1 ;
-(id)parseForecastData:(id)arg0 types:(NSUInteger)arg1 location:(id)arg2 locale:(id)arg3 date:(id)arg4 error:(id*)arg5 ;
-(id)parseForecastData:(id)arg0 types:(NSUInteger)arg1 location:(id)arg2 locale:(id)arg3 date:(id)arg4 error:(id*)arg5 rules:(id)arg6 ;
-(id)parseForecastData:(id)arg0 types:(NSUInteger)arg1 location:(id)arg2 units:(int)arg3 locale:(id)arg4 date:(id)arg5 error:(id*)arg6 rules:(id)arg7 ;
-(id)parseForecastDataFromDict:(id)arg0 types:(NSUInteger)arg1 location:(id)arg2 units:(int)arg3 locale:(id)arg4 date:(id)arg5 error:(id*)arg6 rules:(id)arg7 ;
-(id)parseHourlyForecastFromData:(id)arg0 withUnit:(int)arg1 ;
-(id)parseHourlyHistoryFromData:(id)arg0 withUnit:(int)arg1 ;
-(id)parseMetaDataFromData:(id)arg0 ;
-(id)parseNextHourPrecipitationFromData:(id)arg0 withUnit:(int)arg1 ;
-(id)parsePollenFromData:(id)arg0 ;
-(id)parsePollutants:(id)arg0 ;
-(id)parseSevereWeatherEventsFromData:(id)arg0 withUnit:(int)arg1 ;
-(id)parseWeatherComponentsFromData:(id)arg0 withUnit:(int)arg1 ;
-(id)parsedCategoryFromDictionary:(id)arg0 ;
-(id)parsedGradientStopFromDictionary:(id)arg0 ;
-(id)pollenDictFromData:(id)arg0 types:(NSUInteger)arg1 ;
-(id)severeWeatherEventDictFromData:(id)arg0 types:(NSUInteger)arg1 ;
-(void)parseNowLinksFromData:(id)arg0 intoConditions:(id)arg1 ;
-(void)parseWeatherComponentsFromData:(id)arg0 intoConditions:(id)arg1 withUnit:(int)arg2 ;


@end


#endif