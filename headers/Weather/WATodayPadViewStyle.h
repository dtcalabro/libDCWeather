// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WATODAYPADVIEWSTYLE_H
#define WATODAYPADVIEWSTYLE_H

@class UIFont;

#import <Foundation/Foundation.h>

#import "NSCopying-Protocol.h"

@interface WATodayPadViewStyle : NSObject <NSCopying>



@property (copy, nonatomic) UIFont *conditionsFont; // ivar: _conditionsFont
@property (nonatomic) CGFloat conditionsImageLeadingMargin; // ivar: _conditionsImageLeadingMargin
@property (nonatomic) CGFloat conditionsLabelBaselineToBottom; // ivar: _conditionsLabelBaselineToBottom
@property (nonatomic) CGFloat conditionsLabelBaselineToLocationLabelBaseline; // ivar: _conditionsLabelBaselineToLocationLabelBaseline
@property (nonatomic) NSUInteger format; // ivar: _format
@property (nonatomic) CGFloat labelLeadingMargin; // ivar: _labelLeadingMargin
@property (copy, nonatomic) UIFont *locationFont; // ivar: _locationFont
@property (nonatomic) CGFloat locationLabelBaselineToTemperatureLabelBaseline; // ivar: _locationLabelBaselineToTemperatureLabelBaseline
@property (nonatomic) NSInteger orientation; // ivar: _orientation
@property (copy, nonatomic) UIFont *temperatureFont; // ivar: _temperatureFont
@property (nonatomic) CGFloat temperatureLabelBaselineToConditionsImageViewBottom; // ivar: _temperatureLabelBaselineToConditionsImageViewBottom


+(id)styleForScreenWithSize:(struct CGSize )arg0 orientation:(NSInteger)arg1 ;
-(id)copyWithZone:(struct _NSZone *)arg0 ;
-(id)init;
-(id)initWithFormat:(NSUInteger)arg0 orientation:(NSInteger)arg1 ;
-(void)_setupForDefaultWithOrientation:(NSInteger)arg0 ;
-(void)_setupForGigantorWithOrientation:(NSInteger)arg0 ;


@end


#endif