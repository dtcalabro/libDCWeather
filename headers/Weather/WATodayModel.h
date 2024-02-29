// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WATODAYMODEL_H
#define WATODAYMODEL_H

@class NSHashTable, NSOperationQueue, WFServiceConnection, NSDate;

#import <Foundation/Foundation.h>

#import "WAForecastModel.h"

@interface WATodayModel : NSObject {
    NSHashTable *_observers;
    NSOperationQueue *_modelOperationQueue;
}


@property (retain, nonatomic) WFServiceConnection *connection; // ivar: _connection
@property (retain, nonatomic) WAForecastModel *forecastModel; // ivar: _forecastModel
@property (nonatomic) struct ct_green_tea_logger_s* greenTeaLogger; // ivar: _greenTeaLogger
@property (nonatomic) BOOL hasPendingUpdates; // ivar: _hasPendingUpdates
@property (retain, nonatomic) NSDate *lastUpdateDate; // ivar: _lastUpdateDate


+(id)autoupdatingLocationModelWithPreferences:(id)arg0 effectiveBundleIdentifier:(id)arg1 ;
+(id)currentLocationModel;
+(id)modelWithLocation:(id)arg0 ;
-(BOOL)executeModelUpdateWithCompletion:(id)arg0 ;
-(BOOL)hasCrossedHourlyBoundary;
-(id)init;
-(id)initWithLocation:(id)arg0 ;
-(id)location;
-(void)_executeForecastRetrievalForLocation:(id)arg0 completion:(id)arg1 ;
-(void)_executeLocationUpdateWithCompletion:(id)arg0 ;
-(void)_fireTodayModelForecastWasUpdated:(id)arg0 ;
-(void)_fireTodayModelWantsUpdate;
-(void)_forecastUpdateCompleted:(id)arg0 forecastModel:(id)arg1 error:(id)arg2 completion:(id)arg3 ;
-(void)_locationUpdateCompleted:(id)arg0 error:(id)arg1 completion:(id)arg2 ;
-(void)_persistStateWithModel:(id)arg0 ;
-(void)_willDeliverForecastModel:(id)arg0 ;
-(void)addObserver:(id)arg0 ;
-(void)checkIfNeedsToUpdate;
-(void)clearLocationUpdateState;
-(void)dealloc;
-(void)performDelayedUpdatesForObserver:(id)arg0 ;
-(void)removeObserver:(id)arg0 ;


@end


#endif