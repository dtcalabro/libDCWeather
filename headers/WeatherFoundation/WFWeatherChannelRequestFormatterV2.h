// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFWEATHERCHANNELREQUESTFORMATTERV2_H
#define WFWEATHERCHANNELREQUESTFORMATTERV2_H

@class NSString;

#import <Foundation/Foundation.h>

#import "WFForecastRequestFormatter-Protocol.h"

@interface WFWeatherChannelRequestFormatterV2 : NSObject <WFForecastRequestFormatter>



@property (readonly, copy) NSString *debugDescription;
@property (readonly, copy) NSString *description;
@property (readonly) NSUInteger hash;
@property (readonly) Class superclass;


+(id)airQualityRequestForLocation:(id)arg0 locale:(id)arg1 ;
+(id)aqiRequestForScaleNamed:(id)arg0 language:(id)arg1 ;
+(id)forecastRequest:(NSUInteger)arg0 forLocation:(id)arg1 locale:(id)arg2 date:(id)arg3 ;
+(id)forecastRequest:(NSUInteger)arg0 forLocation:(id)arg1 withUnits:(int)arg2 locale:(id)arg3 date:(id)arg4 rules:(id)arg5 options:(id)arg6 ;
+(id)forecastRequestForRequest:(id)arg0 queryItems:(id)arg1 forLocation:(id)arg2 rules:(id)arg3 ;
+(id)forecastRequestForURL:(id)arg0 queryItems:(id)arg1 ;
+(id)hostURLForService;


@end


#endif