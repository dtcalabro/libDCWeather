// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFAQISCALEGRADIENT_H
#define WFAQISCALEGRADIENT_H

@class NSArray;

#import <Foundation/Foundation.h>

#import "NSCopying-Protocol.h"
#import "NSSecureCoding-Protocol.h"

@interface WFAQIScaleGradient : NSObject <NSCopying, NSSecureCoding>



@property (readonly, nonatomic) NSArray *stops; // ivar: _stops


+(BOOL)supportsSecureCoding;
-(BOOL)isEqual:(id)arg0 ;
-(BOOL)isEqualToScaleGradient:(id)arg0 ;
-(id)copyWithZone:(struct _NSZone *)arg0 ;
-(id)description;
-(id)initWithCoder:(id)arg0 ;
-(id)initWithStops:(id)arg0 ;
-(void)encodeWithCoder:(id)arg0 ;


@end


#endif