// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFWEATHERSTORECALLBACKWRAPPER_H
#define WFWEATHERSTORECALLBACKWRAPPER_H


#import <Foundation/Foundation.h>


@interface WFWeatherStoreCallbackWrapper : NSObject

@property (copy, nonatomic) id aqiScaleRetrievalCompletionBlock; // ivar: _aqiScaleRetrievalCompletionBlock
@property (readonly, nonatomic) BOOL executedCompletionBlock; // ivar: _executedCompletionBlock
@property (copy, nonatomic) id forecastRetrievalCompletionBlock; // ivar: _forecastRetrievalCompletionBlock
@property (nonatomic) os_unfair_lock_s lock; // ivar: _lock
@property (nonatomic) NSUInteger requestType; // ivar: _requestType


-(id)initWithAQIScaleRetrievalBlock:(id)arg0 ;
-(id)initWithForecastRetrievalBlock:(id)arg0 ;
-(void)executeCallbackwithResponse:(id)arg0 error:(id)arg1 ;


@end


#endif