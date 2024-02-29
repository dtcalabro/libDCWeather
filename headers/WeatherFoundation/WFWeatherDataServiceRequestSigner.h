// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFWEATHERDATASERVICEREQUESTSIGNER_H
#define WFWEATHERDATASERVICEREQUESTSIGNER_H


#import <Foundation/Foundation.h>


@interface WFWeatherDataServiceRequestSigner : NSObject



+(id)buildAuthHeader:(id)arg0 withSecret:(id)arg1 andDate:(id)arg2 ;
+(id)roundDate:(id)arg0 toMinutes:(NSUInteger)arg1 ;
+(void)signRequest:(id)arg0 withDate:(id)arg1 ;
+(void)signRequest:(id)arg0 withSecret:(id)arg1 andDate:(id)arg2 ;


@end


#endif