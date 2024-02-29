// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFAQISCALEGRADIENTSTOP_H
#define WFAQISCALEGRADIENTSTOP_H

@class NSString;

#import <Foundation/Foundation.h>

#import "NSCopying-Protocol.h"
#import "NSSecureCoding-Protocol.h"

@interface WFAQIScaleGradientStop : NSObject <NSCopying, NSSecureCoding>



@property (readonly, nonatomic) NSString *color; // ivar: _color
@property (readonly, nonatomic) float location; // ivar: _location


+(BOOL)supportsSecureCoding;
-(id)copyWithZone:(struct _NSZone *)arg0 ;
-(id)description;
-(id)initWithCoder:(id)arg0 ;
-(id)initWithLocation:(float)arg0 color:(id)arg1 ;
-(void)encodeWithCoder:(id)arg0 ;


@end


#endif