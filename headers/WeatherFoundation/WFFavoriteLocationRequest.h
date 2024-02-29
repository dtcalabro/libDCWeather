// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFFAVORITELOCATIONREQUEST_H
#define WFFAVORITELOCATIONREQUEST_H



#import "WFTask.h"

@interface WFFavoriteLocationRequest : WFTask

@property (readonly, nonatomic) id resultHandler; // ivar: _resultHandler


-(id)initWithResultHandler:(id)arg0 ;
-(void)handleCancellation;
-(void)handleError:(id)arg0 forResponseIdentifier:(id)arg1 ;
-(void)handleResponse:(id)arg0 ;
-(void)startWithService:(id)arg0 ;


@end


#endif