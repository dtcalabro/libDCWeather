// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFTASKIDENTIFIER_H
#define WFTASKIDENTIFIER_H

@class NSUUID, NSString;

#import <Foundation/Foundation.h>

#import "NSCopying-Protocol.h"
#import "NSSecureCoding-Protocol.h"

@interface WFTaskIdentifier : NSObject <NSCopying, NSSecureCoding>



@property (readonly, nonatomic) NSUUID *UUID; // ivar: _UUID
@property (readonly, nonatomic) int pid; // ivar: _pid
@property (readonly, nonatomic) NSString *processName; // ivar: _processName


+(BOOL)supportsSecureCoding;
+(id)defaultIdentifier;
-(BOOL)isEqual:(id)arg0 ;
-(NSUInteger)hash;
-(id)copyWithZone:(struct _NSZone *)arg0 ;
-(id)description;
-(id)init;
-(id)initWithCoder:(id)arg0 ;
-(void)encodeWithCoder:(id)arg0 ;


@end


#endif