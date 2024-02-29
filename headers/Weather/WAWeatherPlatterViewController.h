// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WAWEATHERPLATTERVIEWCONTROLLER_H
#define WAWEATHERPLATTERVIEWCONTROLLER_H

@class UIViewController, WFURLComponents, UIView, NSURL, NSMutableArray, NSString, UIStackView, NSArray;


#import "WAAQIView.h"
#import "City.h"
#import "WATodayHeaderView.h"
#import "WATodayModel.h"
#import "WFTemperatureUnitObserver-Protocol.h"

@interface WAWeatherPlatterViewController : UIViewController <WFTemperatureUnitObserver>



@property (retain, nonatomic) WFURLComponents *URLComponents; // ivar: _URLComponents
@property (retain, nonatomic) UIView *afterAQIDividerLineView; // ivar: _afterAQIDividerLineView
@property (retain, nonatomic) UIView *afterHeaderDividerLineView; // ivar: _afterHeaderDividerLineView
@property (retain, nonatomic) WAAQIView *aqiView; // ivar: _aqiView
@property (retain, nonatomic) UIView *backgroundView; // ivar: _backgroundView
@property (retain, nonatomic) City *city; // ivar: _city
@property (copy, nonatomic) NSURL *commitURL; // ivar: _commitURL
@property (retain, nonatomic) NSMutableArray *constraints; // ivar: _constraints
@property (readonly, copy) NSString *debugDescription;
@property (readonly, copy) NSString *description;
@property (readonly) NSUInteger hash;
@property (retain, nonatomic) WATodayHeaderView *headerView; // ivar: _headerView
@property (retain, nonatomic) UIStackView *hourlyBeltView; // ivar: _hourlyBeltView
@property (retain, nonatomic) NSArray *hourlyForecastViews; // ivar: _hourlyForecastViews
@property (nonatomic) CGRect lastBounds; // ivar: _lastBounds
@property (retain, nonatomic) WATodayModel *model; // ivar: _model
@property (nonatomic) NSInteger status; // ivar: _status
@property (readonly) Class superclass;


+(CGFloat)defaultViewHeight;
-(BOOL)_canShowWhileLocked;
-(BOOL)_showingAQIViewForCity:(id)arg0 ;
-(CGFloat)preferredContentWidth;
-(id)init;
-(id)initWithLocation:(id)arg0 ;
-(id)initWithLocationString:(id)arg0 ;
-(id)initWithURL:(id)arg0 ;
-(id)initWithURLComponents:(id)arg0 ;
-(void)_buildModelForLocation:(id)arg0 ;
-(void)_contentSizeDidUpdate:(id)arg0 ;
-(void)_kickoffLoadingWithLocation:(id)arg0 orPerhapsALocationString:(id)arg1 ;
-(void)_loadAQIDataForLocation:(id)arg0 ;
-(void)_updateStatus:(NSInteger)arg0 ;
-(void)_updateViewContent;
-(void)_updateViewWithAQIFromCity:(id)arg0 ;
-(void)setupAQIView;
-(void)setupAfterAQIDividerView;
-(void)setupAfterHeaderDividerView;
-(void)setupBackgroundView;
-(void)setupConstraints;
-(void)setupHeaderView;
-(void)setupHourlyForecast;
-(void)temperatureUnitObserver:(id)arg0 didChangeTemperatureUnitTo:(int)arg1 ;
-(void)updateViewConstraints;
-(void)viewDidLayoutSubviews;
-(void)viewDidLoad;


@end


#endif