// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFAIRQUALITYRESPONSE_H
#define WFAIRQUALITYRESPONSE_H

@class NSData;


#import "WFResponse.h"
#import "WFAirQualityConditions.h"
#import "NSSecureCoding-Protocol.h"

@interface WFAirQualityResponse : WFResponse <NSSecureCoding>



@property (retain, nonatomic) WFAirQualityConditions *airQualityConditions; // ivar: _airQualityConditions
@property (retain, nonatomic) NSData *rawAPIData; // ivar: _rawAPIData
@property (nonatomic) BOOL responseWasFromCache; // ivar: _responseWasFromCache


+(BOOL)supportsSecureCoding;
-(id)initWithCoder:(id)arg0 ;
-(void)encodeWithCoder:(id)arg0 ;


@end


#endif