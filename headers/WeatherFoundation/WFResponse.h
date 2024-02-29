// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFRESPONSE_H
#define WFRESPONSE_H

@class NSError, NSUUID, NSString;

#import <Foundation/Foundation.h>

#import "NSSecureCoding-Protocol.h"

@interface WFResponse : NSObject <NSSecureCoding>



@property (retain, nonatomic) NSError *error; // ivar: _error
@property (nonatomic) CGFloat executionTime; // ivar: _executionTime
@property (readonly) NSUUID *identifier; // ivar: _identifier
@property (readonly) NSString *type; // ivar: _type


+(BOOL)supportsSecureCoding;
+(id)responseWithIdentifier:(id)arg0 error:(id)arg1 ;
-(id)initWithCoder:(id)arg0 ;
-(id)initWithIdentifier:(id)arg0 ;
-(id)initWithIdentifier:(id)arg0 error:(id)arg1 ;
-(void)encodeWithCoder:(id)arg0 ;


@end


#endif