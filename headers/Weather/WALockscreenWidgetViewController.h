// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WALOCKSCREENWIDGETVIEWCONTROLLER_H
#define WALOCKSCREENWIDGETVIEWCONTROLLER_H

@class UIViewController, NSString, NSDate, NSTimer;
@protocol WAWidgetDelegate;


#import "WAForecastModel.h"
#import "WATodayModel.h"
#import "WATodayPadView.h"
#import "WATodayModelObserver-Protocol.h"

@interface WALockscreenWidgetViewController : UIViewController <WATodayModelObserver>



@property (copy, nonatomic) WAForecastModel *currentForecastModel; // ivar: _currentForecastModel
@property (readonly, copy) NSString *debugDescription;
@property (weak, nonatomic) NSObject<WAWidgetDelegate> *delegate; // ivar: _delegate
@property (readonly, copy) NSString *description;
@property (readonly) NSUInteger hash;
@property (nonatomic) BOOL locationServicesActive; // ivar: _locationServicesActive
@property (readonly) Class superclass;
@property (retain, nonatomic) WATodayModel *todayModel; // ivar: _todayModel
@property (retain, nonatomic) WATodayPadView *todayView; // ivar: _todayView
@property (readonly, nonatomic) BOOL todayViewIsVisible;
@property (nonatomic) CGFloat updateInterval; // ivar: _updateInterval
@property (copy, nonatomic) NSDate *updateLastCompletionDate; // ivar: _updateLastCompletionDate
@property (retain, nonatomic) NSTimer *updateTimer; // ivar: _updateTimer


+(id)sharedInstanceIfExists;
-(BOOL)shouldFakeWeather;
-(id)_conditionsImage;
-(id)_conditionsLine;
-(id)_locationName;
-(id)_temperature;
-(id)init;
-(void)_delegateUpdateDidFailWithError:(id)arg0 ;
-(void)_scheduleNewTimer;
-(void)_setupWeatherModel;
-(void)_teardownTimer;
-(void)_teardownWeatherModel;
-(void)_updateTimerFired:(id)arg0 ;
-(void)_updateTodayView;
-(void)_updateWithReason:(id)arg0 ;
-(void)getLocationServicesAuthorizationStatus:(id)arg0 ;
-(void)todayModel:(id)arg0 forecastWasUpdated:(id)arg1 ;
-(void)todayModelWantsUpdate:(id)arg0 ;
-(void)updateForChangedSettings:(id)arg0 ;
-(void)updateWeather;
-(void)viewDidAppear:(BOOL)arg0 ;
-(void)viewDidDisappear:(BOOL)arg0 ;
-(void)viewDidLoad;
-(void)viewWillAppear:(BOOL)arg0 ;
-(void)viewWillTransitionToSize:(struct CGSize )arg0 withTransitionCoordinator:(id)arg1 ;


@end


#endif