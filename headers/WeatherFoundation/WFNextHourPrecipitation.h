// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFNEXTHOURPRECIPITATION_H
#define WFNEXTHOURPRECIPITATION_H

@class NSArray, NSDate;

#import <Foundation/Foundation.h>

#import "WFNextHourPrecipitationDescription.h"
#import "NSCopying-Protocol.h"
#import "NSSecureCoding-Protocol.h"

@interface WFNextHourPrecipitation : NSObject <NSCopying, NSSecureCoding>



@property (readonly, nonatomic) NSArray *activeMinutes;
@property (readonly, copy, nonatomic) NSArray *conditions; // ivar: _conditions
@property (readonly, nonatomic) WFNextHourPrecipitationDescription *currentDescription;
@property (readonly, copy, nonatomic) NSDate *expirationDate; // ivar: _expirationDate
@property (readonly, nonatomic) BOOL isRelevant;
@property (readonly, copy, nonatomic) NSArray *minutes; // ivar: _minutes
@property (readonly, copy, nonatomic) NSArray *precipitationDescriptions; // ivar: _precipitationDescriptions
@property (readonly, copy, nonatomic) NSDate *readDate; // ivar: _readDate
@property (readonly, copy, nonatomic) NSDate *startDate; // ivar: _startDate


+(BOOL)supportsSecureCoding;
-(BOOL)isEqual:(id)arg0 ;
-(NSUInteger)hash;
-(id)copyWithZone:(struct _NSZone *)arg0 ;
-(id)description;
-(id)initWithCoder:(id)arg0 ;
-(id)initWithReadDate:(id)arg0 startDate:(id)arg1 expirationDate:(id)arg2 minutes:(id)arg3 conditions:(id)arg4 descriptions:(id)arg5 ;
-(void)encodeWithCoder:(id)arg0 ;


@end


#endif