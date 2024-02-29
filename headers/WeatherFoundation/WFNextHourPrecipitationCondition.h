// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFNEXTHOURPRECIPITATIONCONDITION_H
#define WFNEXTHOURPRECIPITATIONCONDITION_H

@class NSDate;

#import <Foundation/Foundation.h>

#import "NSCopying-Protocol.h"
#import "NSSecureCoding-Protocol.h"

@interface WFNextHourPrecipitationCondition : NSObject <NSCopying, NSSecureCoding>



@property (readonly, nonatomic) CGFloat intensity; // ivar: _intensity
@property (readonly, nonatomic) CGFloat probability; // ivar: _probability
@property (readonly, nonatomic) NSUInteger type; // ivar: _type
@property (readonly, nonatomic) NSDate *validUntil; // ivar: _validUntil


+(BOOL)supportsSecureCoding;
-(NSUInteger)typeForString:(id)arg0 ;
-(id)_stringForType:(NSUInteger)arg0 ;
-(id)copyWithZone:(struct _NSZone *)arg0 ;
-(id)initWithCoder:(id)arg0 ;
-(id)initWithType:(id)arg0 intensity:(CGFloat)arg1 probability:(CGFloat)arg2 validUntil:(id)arg3 ;
-(void)encodeWithCoder:(id)arg0 ;


@end


#endif