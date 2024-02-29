// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WATODAYHEADERVIEW_H
#define WATODAYHEADERVIEW_H

@class UIView, UIImage, UIImageView, UILabel, NSString, UIVisualEffectView;



@interface WATodayHeaderView : UIView

@property (copy, nonatomic) UIImage *conditionsImage; // ivar: _conditionsImage
@property (retain, nonatomic) UIImageView *conditionsImageView; // ivar: _conditionsImageView
@property (retain, nonatomic) UILabel *conditionsLabel1; // ivar: _conditionsLabel1
@property (retain, nonatomic) UILabel *conditionsLabel2; // ivar: _conditionsLabel2
@property (copy, nonatomic) NSString *conditionsLine1; // ivar: _conditionsLine1
@property (copy, nonatomic) NSString *conditionsLine2; // ivar: _conditionsLine2
@property (retain, nonatomic) UILabel *locationLabel; // ivar: _locationLabel
@property (copy, nonatomic) NSString *locationName; // ivar: _locationName
@property (nonatomic) CGFloat pageBaselineOffset; // ivar: _pageBaselineOffset
@property (nonatomic) CGFloat pageDegreeFontSize; // ivar: _pageDegreeFontSize
@property (nonatomic) CGFloat pageFontSize; // ivar: _pageFontSize
@property (copy, nonatomic) NSString *temperature; // ivar: _temperature
@property (copy, nonatomic) NSString *temperatureHigh; // ivar: _temperatureHigh
@property (retain, nonatomic) UILabel *temperatureHighLowLabel; // ivar: _temperatureHighLowLabel
@property (retain, nonatomic) UILabel *temperatureLabel; // ivar: _temperatureLabel
@property (copy, nonatomic) NSString *temperatureLow; // ivar: _temperatureLow
@property (retain, nonatomic) UIVisualEffectView *weatherInformationVisualEffectView; // ivar: _weatherInformationVisualEffectView


+(BOOL)requiresConstraintBasedLayout;
-(id)init;
-(void)_setupConstraints;
-(void)_setupSubviews;
-(void)_updateContent;


@end


#endif