// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFTEMPERATUREUNITRESPONSE_H
#define WFTEMPERATUREUNITRESPONSE_H



#import "WFResponse.h"
#import "NSSecureCoding-Protocol.h"

@interface WFTemperatureUnitResponse : WFResponse <NSSecureCoding>



@property (nonatomic) int temperatureUnit; // ivar: _temperatureUnit


+(BOOL)supportsSecureCoding;
-(id)initWithCoder:(id)arg0 ;
-(void)encodeWithCoder:(id)arg0 ;


@end


#endif