// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFAQISCALECATEGORY_H
#define WFAQISCALECATEGORY_H

@class NSString;

#import <Foundation/Foundation.h>

#import "NSCopying-Protocol.h"
#import "NSSecureCoding-Protocol.h"

@interface WFAQIScaleCategory : NSObject <NSCopying, NSSecureCoding>



@property (nonatomic) NSUInteger categoryIndex; // ivar: _categoryIndex
@property (copy, nonatomic) NSString *categoryName; // ivar: _categoryName
@property (nonatomic) NSUInteger categoryNumber; // ivar: _categoryNumber
@property (copy, nonatomic) NSString *color; // ivar: _color
@property (copy, nonatomic) NSString *glyph; // ivar: _glyph
@property (copy, nonatomic) NSString *localizedCategoryDescription; // ivar: _localizedCategoryDescription
@property (nonatomic) struct _NSRange range; // ivar: _range
@property (copy, nonatomic) NSString *recommendation; // ivar: _recommendation


+(BOOL)supportsSecureCoding;
-(BOOL)isEqual:(id)arg0 ;
-(BOOL)isEqualToScaleCategory:(id)arg0 ;
-(id)copyWithZone:(struct _NSZone *)arg0 ;
-(id)debugDescription;
-(id)description;
-(id)initWithCategoryIndex:(NSUInteger)arg0 localizedCategoryDescription:(id)arg1 ;
-(id)initWithCoder:(id)arg0 ;
-(void)encodeWithCoder:(id)arg0 ;


@end


#endif