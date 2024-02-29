// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFNEXTHOURPRECIPITATIONDESCRIPTION_H
#define WFNEXTHOURPRECIPITATIONDESCRIPTION_H

@class NSString, NSDictionary, NSDate;

#import <Foundation/Foundation.h>

#import "NSCopying-Protocol.h"
#import "NSSecureCoding-Protocol.h"

@interface WFNextHourPrecipitationDescription : NSObject <NSCopying, NSSecureCoding>



@property (readonly, nonatomic) NSString *longDescription;
@property (copy, nonatomic) NSString *longTemplate; // ivar: _longTemplate
@property (copy, nonatomic) NSDictionary *parameters; // ivar: _parameters
@property (readonly, nonatomic) NSString *shortDescription;
@property (copy, nonatomic) NSString *shortTemplate; // ivar: _shortTemplate
@property (copy, nonatomic) NSString *token; // ivar: _token
@property (readonly, copy, nonatomic) NSDate *validUntil; // ivar: _validUntil


+(BOOL)supportsSecureCoding;
-(BOOL)isValidAtDate:(id)arg0 ;
-(id)copyWithZone:(struct _NSZone *)arg0 ;
-(id)fillTemplate:(id)arg0 withDate:(id)arg1 ;
-(id)initWithCoder:(id)arg0 ;
-(id)initWithShortTemplate:(id)arg0 longTemplate:(id)arg1 parameters:(id)arg2 validUntil:(id)arg3 ;
-(id)initWithToken:(id)arg0 shortTemplate:(id)arg1 longTemplate:(id)arg2 parameters:(id)arg3 validUntil:(id)arg4 ;
-(void)encodeWithCoder:(id)arg0 ;


@end


#endif