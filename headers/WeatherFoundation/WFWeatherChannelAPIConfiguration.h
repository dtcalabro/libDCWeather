// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFWEATHERCHANNELAPICONFIGURATION_H
#define WFWEATHERCHANNELAPICONFIGURATION_H

@class NSString, NSMutableDictionary;

#import <Foundation/Foundation.h>

#import "WFAPIConfigurationProtocol-Protocol.h"
#import "WFForecastDataParser-Protocol.h"

@interface WFWeatherChannelAPIConfiguration : NSObject <WFAPIConfigurationProtocol>



@property (readonly, copy) NSString *debugDescription;
@property (retain, nonatomic) NSObject<WFForecastDataParser> *defaultForecastParser; // ivar: _defaultForecastParser
@property (retain, nonatomic) Class defaultForecastRequestFormatterClass; // ivar: _defaultForecastRequestFormatterClass
@property (readonly, copy) NSString *description;
@property (readonly) NSUInteger hash;
@property (readonly, nonatomic) BOOL isValid;
@property (retain, nonatomic) NSMutableDictionary *requestFormatterForForecastType; // ivar: _requestFormatterForForecastType
@property (retain, nonatomic) NSMutableDictionary *requestParserForForecastType; // ivar: _requestParserForForecastType
@property (readonly) Class superclass;


-(id)copyWithZone:(struct _NSZone *)arg0 ;
-(id)forecastRequestForTypes:(NSUInteger)arg0 location:(id)arg1 units:(int)arg2 date:(id)arg3 error:(id*)arg4 rules:(id)arg5 options:(id)arg6 ;
-(id)hostUrl;
-(id)initWithVersion:(id)arg0 ;
-(id)parseForecast:(NSUInteger)arg0 data:(id)arg1 location:(id)arg2 units:(int)arg3 locale:(id)arg4 date:(id)arg5 error:(id*)arg6 rules:(id)arg7 ;
-(void)setDefaultForecastFormatter:(Class)arg0 ;
-(void)setRequestFormatter:(Class)arg0 forForecastType:(NSUInteger)arg1 ;
-(void)setRequestParser:(id)arg0 forForecastType:(NSUInteger)arg1 ;


@end


#endif