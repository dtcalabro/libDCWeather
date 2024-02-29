// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFWEATHERDATASERVICEREQUESTFORMATTERV1_H
#define WFWEATHERDATASERVICEREQUESTFORMATTERV1_H

@class NSString;

#import <Foundation/Foundation.h>

#import "WFForecastRequestFormatter-Protocol.h"
#import "WFForecastRequestFormatterMultiHost-Protocol.h"

@interface WFWeatherDataServiceRequestFormatterV1 : NSObject <WFForecastRequestFormatter, WFForecastRequestFormatterMultiHost>



@property (readonly, copy) NSString *debugDescription;
@property (readonly, copy) NSString *description;
@property (readonly) NSUInteger hash;
@property (readonly) Class superclass;


+(id)aqiRequestForScaleNamed:(id)arg0 language:(id)arg1 ;
+(id)forecastRequest:(NSUInteger)arg0 forLocation:(id)arg1 locale:(id)arg2 date:(id)arg3 ;
+(id)forecastRequest:(NSUInteger)arg0 forLocation:(id)arg1 withUnits:(int)arg2 locale:(id)arg3 date:(id)arg4 rules:(id)arg5 options:(id)arg6 ;
+(id)geocodePathForLocation:(id)arg0 rules:(id)arg1 ;
+(id)hostURLForEnvironment:(id)arg0 ;
+(id)hostURLForService;
+(id)languagePathForLocale:(id)arg0 ;


@end


#endif