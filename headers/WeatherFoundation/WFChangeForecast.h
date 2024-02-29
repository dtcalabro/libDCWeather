// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFCHANGEFORECAST_H
#define WFCHANGEFORECAST_H

@class NSDate, NSString;

#import <Foundation/Foundation.h>

#import "NSCopying-Protocol.h"
#import "NSSecureCoding-Protocol.h"

@interface WFChangeForecast : NSObject <NSCopying, NSSecureCoding>



@property (readonly, copy, nonatomic) NSDate *date; // ivar: _date
@property (readonly, nonatomic) NSString *descriptionDifferentTimeZone; // ivar: _descriptionDifferentTimeZone
@property (readonly, nonatomic) NSString *descriptionSameTimeZone; // ivar: _descriptionSameTimeZone


+(BOOL)supportsSecureCoding;
-(id)copyWithZone:(struct _NSZone *)arg0 ;
-(id)initWithCoder:(id)arg0 ;
-(id)initWithDate:(id)arg0 descriptionSameTimeZone:(id)arg1 descriptionDifferentTimeZone:(id)arg2 ;
-(void)encodeWithCoder:(id)arg0 ;


@end


#endif