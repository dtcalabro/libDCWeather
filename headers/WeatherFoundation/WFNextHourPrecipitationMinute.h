// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFNEXTHOURPRECIPITATIONMINUTE_H
#define WFNEXTHOURPRECIPITATIONMINUTE_H

@class NSDate;

#import <Foundation/Foundation.h>

#import "NSCopying-Protocol.h"
#import "NSSecureCoding-Protocol.h"

@interface WFNextHourPrecipitationMinute : NSObject <NSCopying, NSSecureCoding>



@property (readonly, nonatomic) CGFloat chance; // ivar: _chance
@property (readonly, nonatomic) NSDate *date; // ivar: _date
@property (readonly, nonatomic) CGFloat intensity; // ivar: _intensity
@property (readonly, nonatomic) CGFloat perceivedIntensity; // ivar: _perceivedIntensity


+(BOOL)supportsSecureCoding;
-(id)copyWithZone:(struct _NSZone *)arg0 ;
-(id)initWithCoder:(id)arg0 ;
-(id)initWithIntensity:(CGFloat)arg0 chance:(CGFloat)arg1 perceivedIntensity:(CGFloat)arg2 date:(id)arg3 ;
-(void)encodeWithCoder:(id)arg0 ;


@end


#endif