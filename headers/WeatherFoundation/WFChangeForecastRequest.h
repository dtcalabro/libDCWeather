// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFCHANGEFORECASTREQUEST_H
#define WFCHANGEFORECASTREQUEST_H



#import "WFTask.h"
#import "WFLocation.h"

@interface WFChangeForecastRequest : WFTask

@property (readonly, nonatomic) id completionHandler; // ivar: _completionHandler
@property (readonly, copy, nonatomic) WFLocation *location; // ivar: _location


-(id)initWithLocation:(id)arg0 completionHandler:(id)arg1 ;
-(void)handleError:(id)arg0 forResponseIdentifier:(id)arg1 ;
-(void)handleResponse:(id)arg0 ;
-(void)startWithService:(id)arg0 ;


@end


#endif