// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFWEATHERSTORERESPONSEDATAWRAPPER_H
#define WFWEATHERSTORERESPONSEDATAWRAPPER_H


#import <Foundation/Foundation.h>

#import "WFAQIScale.h"
#import "WFParsedForecastData.h"

@interface WFWeatherStoreResponseDataWrapper : NSObject

@property (retain, nonatomic) WFAQIScale *aqiScale; // ivar: _aqiScale
@property (retain, nonatomic) WFParsedForecastData *forecastData; // ivar: _forecastData
@property (nonatomic) NSUInteger requestType; // ivar: _requestType


-(id)initWithAQIScale:(id)arg0 ;
-(id)initWithForecastData:(id)arg0 ;


@end


#endif