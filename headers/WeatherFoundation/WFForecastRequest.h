// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFFORECASTREQUEST_H
#define WFFORECASTREQUEST_H

@class NSDateComponents, NSLocale, NSDate, NSData, NSString;


#import "WFTask.h"
#import "WFLocation.h"

@interface WFForecastRequest : WFTask

@property (nonatomic) BOOL attachRawAPIData; // ivar: _attachRawAPIData
@property (copy, nonatomic) id completionHandler; // ivar: _completionHandler
@property (copy, nonatomic) NSDateComponents *date; // ivar: _date
@property (nonatomic) NSUInteger forecastType; // ivar: _forecastType
@property (retain, nonatomic) NSLocale *locale; // ivar: _locale
@property (copy, nonatomic) WFLocation *location; // ivar: _location
@property (readonly, nonatomic) NSDate *onDate; // ivar: _onDate
@property (retain, nonatomic) NSData *rawAPIData; // ivar: _rawAPIData
@property (retain, nonatomic) NSString *trackingParameter; // ivar: _trackingParameter


+(id)forecastRequestForLocation:(id)arg0 completionHandler:(id)arg1 ;
+(id)forecastRequestForLocation:(id)arg0 date:(id)arg1 completionHandler:(id)arg2 ;
+(id)forecastRequestForLocation:(id)arg0 onDate:(id)arg1 completionHandler:(id)arg2 ;
-(id)description;
-(id)initWithLocation:(id)arg0 completionHandler:(id)arg1 ;
-(id)initWithLocation:(id)arg0 date:(id)arg1 completionHandler:(id)arg2 ;
-(id)initWithLocation:(id)arg0 onDate:(id)arg1 completionHandler:(id)arg2 ;
-(void)cleanup;
-(void)handleCancellation;
-(void)handleError:(id)arg0 forResponseIdentifier:(id)arg1 ;
-(void)handleResponse:(id)arg0 ;
-(void)startWithService:(id)arg0 ;


@end


#endif