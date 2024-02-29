// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFFORECASTRESPONSE_H
#define WFFORECASTRESPONSE_H

@class NSData;


#import "WFResponse.h"
#import "WFWeatherConditions.h"
#import "NSSecureCoding-Protocol.h"

@interface WFForecastResponse : WFResponse <NSSecureCoding>



@property (retain, nonatomic) WFWeatherConditions *forecast; // ivar: _forecast
@property (nonatomic) NSUInteger forecastType; // ivar: _forecastType
@property (retain, nonatomic) NSData *rawAPIData; // ivar: _rawAPIData
@property (nonatomic) BOOL responseWasFromCache; // ivar: _responseWasFromCache


+(BOOL)supportsSecureCoding;
-(id)initWithCoder:(id)arg0 ;
-(void)encodeWithCoder:(id)arg0 ;


@end


#endif