// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WAGREETINGVIEW_H
#define WAGREETINGVIEW_H

@class UIView, UIImageView, NSMutableArray, NSString, UIColor, UILabel;


#import "WATodayAutoupdatingLocationModel.h"
#import "WATodayModelObserver-Protocol.h"

@interface WAGreetingView : UIView <WATodayModelObserver>



@property (retain, nonatomic) UIImageView *conditionImageView; // ivar: _conditionImageView
@property (retain, nonatomic) NSMutableArray *constraints; // ivar: _constraints
@property (readonly, copy) NSString *debugDescription;
@property (readonly, copy) NSString *description;
@property (readonly) NSUInteger hash;
@property (nonatomic) BOOL isViewCreated; // ivar: _isViewCreated
@property (retain, nonatomic) UIColor *labelColor; // ivar: _labelColor
@property (retain, nonatomic) UILabel *natualLanguageDescriptionLabel; // ivar: _natualLanguageDescriptionLabel
@property (readonly) Class superclass;
@property (retain, nonatomic) UILabel *temperatureLabel; // ivar: _temperatureLabel
@property (retain, nonatomic) WATodayAutoupdatingLocationModel *todayModel; // ivar: _todayModel


-(id)_conditionsImage;
-(id)_temperature;
-(id)init;
-(id)initWithColor:(id)arg0 ;
-(id)initWithFrame:(struct CGRect )arg0 ;
-(void)_setupWeatherModel;
-(void)_teardownWeatherModel;
-(void)createViews;
-(void)dealloc;
-(void)setupConstraints;
-(void)startService;
-(void)todayModel:(id)arg0 forecastWasUpdated:(id)arg1 ;
-(void)todayModelWantsUpdate:(id)arg0 ;
-(void)updateConstraints;
-(void)updateLabelColors;
-(void)updateView;


@end


#endif