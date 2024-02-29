// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFAGGREGATEFORECASTREQUEST_H
#define WFAGGREGATEFORECASTREQUEST_H



#import "WFTask.h"
#import "WFLocation.h"

@interface WFAggregateForecastRequest : WFTask

@property (copy, nonatomic) id completionHandler; // ivar: _completionHandler
@property (copy, nonatomic) WFLocation *location; // ivar: _location


-(id)initWithLocation:(id)arg0 completionHandler:(id)arg1 ;
-(void)cleanup;
-(void)handleCancellation;
-(void)handleError:(id)arg0 forResponseIdentifier:(id)arg1 ;
-(void)handleResponse:(id)arg0 ;


@end


#endif