// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WATODAYPADVIEW_H
#define WATODAYPADVIEW_H

@class UIView, UIImage, UIImageView, NSString, NSArray, _UILegibilitySettings;


#import "WALegibilityLabel.h"
#import "WATodayPadViewStyle.h"

@interface WATodayPadView : UIView

@property (copy, nonatomic) UIImage *conditionsImage;
@property (retain, nonatomic) UIImageView *conditionsImageView; // ivar: _conditionsImageView
@property (retain, nonatomic) WALegibilityLabel *conditionsLabel; // ivar: _conditionsLabel
@property (copy, nonatomic) NSString *conditionsLine;
@property (retain, nonatomic) NSArray *constraints; // ivar: _constraints
@property (retain, nonatomic) _UILegibilitySettings *legibilitySettings; // ivar: _legibilitySettings
@property (retain, nonatomic) WALegibilityLabel *locationLabel; // ivar: _locationLabel
@property (copy, nonatomic) NSString *locationName;
@property (copy, nonatomic) WATodayPadViewStyle *style; // ivar: _style
@property (copy, nonatomic) NSString *temperature;
@property (retain, nonatomic) WALegibilityLabel *temperatureLabel; // ivar: _temperatureLabel


+(BOOL)requiresConstraintBasedLayout;
-(id)initWithFrame:(struct CGRect )arg0 ;
-(void)_setupConstraintsForViews;
-(void)sizeToFit;
-(void)updateForChangedSettings:(id)arg0 ;
-(void)willMoveToWindow:(id)arg0 ;


@end


#endif