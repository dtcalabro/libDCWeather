// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WATODAYHOURLYFORECASTVIEW_H
#define WATODAYHOURLYFORECASTVIEW_H

@class UIView, UIImage, UIImageView, NSArray, NSAttributedString, UILabel, UIVisualEffectView;



@interface WATodayHourlyForecastView : UIView

@property (retain, nonatomic) UIImage *conditionsImage;
@property (retain, nonatomic) UIImageView *conditionsImageView; // ivar: _conditionsImageView
@property (retain, nonatomic) NSArray *constraints; // ivar: _constraints
@property (copy, nonatomic) NSAttributedString *temperature;
@property (retain, nonatomic) UILabel *temperatureLabel; // ivar: _temperatureLabel
@property (retain, nonatomic) UIVisualEffectView *temperatureLabelVisualEffectView; // ivar: _temperatureLabelVisualEffectView
@property (copy, nonatomic) NSAttributedString *time;
@property (retain, nonatomic) UILabel *timeLabel; // ivar: _timeLabel
@property (retain, nonatomic) UIVisualEffectView *timeLabelVisualEffectView; // ivar: _timeLabelVisualEffectView


-(id)initWithFrame:(struct CGRect )arg0 ;
-(void)_setupConstraints;
-(void)applyVibrancyToTimeWithEffect:(id)arg0 ;


@end


#endif