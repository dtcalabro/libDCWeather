// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFAIRQUALITYREQUEST_H
#define WFAIRQUALITYREQUEST_H

@class NSLocale;


#import "WFTask.h"
#import "WFLocation.h"

@interface WFAirQualityRequest : WFTask

@property (nonatomic) BOOL attachRawAPIData; // ivar: _attachRawAPIData
@property (copy, nonatomic) id completionHandler; // ivar: _completionHandler
@property (retain, nonatomic) NSLocale *locale; // ivar: _locale
@property (retain, nonatomic) WFLocation *location; // ivar: _location


+(id)airQualityRequestForLocation:(id)arg0 locale:(id)arg1 completionHandler:(id)arg2 ;
-(id)initWithLocation:(id)arg0 locale:(id)arg1 completionHandler:(id)arg2 ;
-(id)options;
-(void)cleanup;
-(void)handleError:(id)arg0 forResponseIdentifier:(id)arg1 ;
-(void)handleResponse:(id)arg0 ;
-(void)startWithService:(id)arg0 ;


@end


#endif