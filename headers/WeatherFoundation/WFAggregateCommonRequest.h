// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFAGGREGATECOMMONREQUEST_H
#define WFAGGREGATECOMMONREQUEST_H

@class NSLocale, NSString;


#import "WFTask.h"
#import "WFLocation.h"
#import "WFRequestOptions.h"

@interface WFAggregateCommonRequest : WFTask

@property (readonly, copy, nonatomic) id completionHandler; // ivar: _completionHandler
@property (retain, nonatomic) NSLocale *locale; // ivar: _locale
@property (readonly, nonatomic) WFLocation *location; // ivar: _location
@property (readonly, nonatomic) WFRequestOptions *requestOptions; // ivar: _requestOptions
@property (readonly, nonatomic) NSString *trackingParameter; // ivar: _trackingParameter
@property (readonly, nonatomic) NSUInteger types; // ivar: _types
@property (readonly, nonatomic) int units; // ivar: _units


-(NSUInteger)_supportedForecastTypes:(NSUInteger)arg0 ;
-(id)description;
-(id)initWithLocation:(id)arg0 types:(NSUInteger)arg1 trackingParameter:(id)arg2 completionHandler:(id)arg3 ;
-(id)initWithLocation:(id)arg0 types:(NSUInteger)arg1 units:(int)arg2 requestOptions:(id)arg3 trackingParameter:(id)arg4 completionHandler:(id)arg5 ;
-(id)initWithLocation:(id)arg0 types:(NSUInteger)arg1 units:(int)arg2 trackingParameter:(id)arg3 completionHandler:(id)arg4 ;
-(void)cleanup;
-(void)handleCancellation;
-(void)handleError:(id)arg0 forResponseIdentifier:(id)arg1 ;
-(void)handleResponse:(id)arg0 ;
-(void)startWithService:(id)arg0 ;


@end


#endif