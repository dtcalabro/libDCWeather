// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFWEATHERDATASERVICEAPICONFIGURATION_H
#define WFWEATHERDATASERVICEAPICONFIGURATION_H

@class NSString;

#import <Foundation/Foundation.h>

#import "WFAPIConfigurationProtocol-Protocol.h"
#import "WFForecastDataParser-Protocol.h"

@interface WFWeatherDataServiceAPIConfiguration : NSObject <WFAPIConfigurationProtocol>



@property (readonly, copy) NSString *debugDescription;
@property (readonly, copy) NSString *description;
@property (readonly, nonatomic) NSString *environment; // ivar: _environment
@property (retain, nonatomic) NSObject<WFForecastDataParser> *forecastParser; // ivar: _forecastParser
@property (retain, nonatomic) Class forecastRequestFormatterClass; // ivar: _forecastRequestFormatterClass
@property (readonly) NSUInteger hash;
@property (readonly, nonatomic) BOOL isValid;
@property (readonly) Class superclass;


-(id)aqiRequestForScaleNamed:(id)arg0 language:(id)arg1 ;
-(id)copyWithZone:(struct _NSZone *)arg0 ;
-(id)forecastRequestForTypes:(NSUInteger)arg0 location:(id)arg1 units:(int)arg2 date:(id)arg3 error:(id*)arg4 rules:(id)arg5 options:(id)arg6 ;
-(id)hostUrl;
-(id)initWithVersion:(id)arg0 environment:(id)arg1 ;
-(id)parseAQIScaleNamed:(id)arg0 data:(id)arg1 error:(id*)arg2 ;
-(id)parseForecast:(NSUInteger)arg0 data:(id)arg1 location:(id)arg2 units:(int)arg3 locale:(id)arg4 date:(id)arg5 error:(id*)arg6 rules:(id)arg7 ;


@end


#endif