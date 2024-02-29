// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFAIRPOLLUTANT_H
#define WFAIRPOLLUTANT_H

@class NSString;

#import <Foundation/Foundation.h>

#import "NSCopying-Protocol.h"
#import "NSSecureCoding-Protocol.h"

@interface WFAirPollutant : NSObject <NSCopying, NSSecureCoding>



@property (nonatomic) CGFloat amount; // ivar: _amount
@property (nonatomic) NSUInteger categoryIndex; // ivar: _categoryIndex
@property (nonatomic) NSUInteger index; // ivar: _index
@property (retain, nonatomic) NSString *localizedCategoryDescription; // ivar: _localizedCategoryDescription
@property (copy, nonatomic) NSString *localizedDescription; // ivar: _localizedDescription
@property (copy, nonatomic) NSString *localizedName; // ivar: _localizedName
@property (retain, nonatomic) NSString *unit; // ivar: _unit


+(BOOL)supportsSecureCoding;
-(id)copyWithZone:(struct _NSZone *)arg0 ;
-(id)description;
-(id)initWithCoder:(id)arg0 ;
-(void)encodeWithCoder:(id)arg0 ;


@end


#endif