// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFAGGREGATEFORECASTRESPONSE_H
#define WFAGGREGATEFORECASTRESPONSE_H

@class NSArray;


#import "WFResponse.h"
#import "NSCopying-Protocol.h"
#import "NSSecureCoding-Protocol.h"

@interface WFAggregateForecastResponse : WFResponse <NSCopying, NSSecureCoding>



@property (copy, nonatomic) NSArray *forecasts; // ivar: _forecasts
@property (nonatomic) BOOL responseWasFromCache; // ivar: _responseWasFromCache


+(BOOL)supportsSecureCoding;
-(id)copyWithZone:(struct _NSZone *)arg0 ;
-(id)initWithCoder:(id)arg0 ;
-(void)encodeWithCoder:(id)arg0 ;


@end


#endif