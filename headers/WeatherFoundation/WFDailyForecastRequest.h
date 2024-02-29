// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFDAILYFORECASTREQUEST_H
#define WFDAILYFORECASTREQUEST_H

@class NSLocale;


#import "WFAggregateForecastRequest.h"

@interface WFDailyForecastRequest : WFAggregateForecastRequest

@property (retain, nonatomic) NSLocale *locale; // ivar: _locale


+(BOOL)supportsSecureCoding;
-(id)description;
-(id)initWithLocation:(id)arg0 completionHandler:(id)arg1 ;
-(void)startWithService:(id)arg0 ;


@end


#endif