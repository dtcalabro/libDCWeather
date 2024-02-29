// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WAFORECASTMODELCONTROLLER_H
#define WAFORECASTMODELCONTROLLER_H

@class NSMutableDictionary, WFServiceConnection, NSOperationQueue, WALocationPrivacySampler, NSMutableSet, WFWeatherStoreService, NSString;
@protocol OS_dispatch_queue;

#import <Foundation/Foundation.h>
#import "Weather-Structs.h"

@interface WAForecastModelController : NSObject

@property (retain) NSObject<OS_dispatch_queue> *completionHandlerQueue; // ivar: _completionHandlerQueue
@property (retain) NSMutableDictionary *completionHandlersForCity; // ivar: _completionHandlersForCity
@property (retain, nonatomic) WFServiceConnection *connection; // ivar: _connection
@property (retain) NSOperationQueue *forecastOperationQueue; // ivar: _forecastOperationQueue
@property (nonatomic) ct_green_tea_logger_sRef greenTeaLogger; // ivar: _greenTeaLogger
@property (retain) NSObject<OS_dispatch_queue> *incomingRequestQueue; // ivar: _incomingRequestQueue
@property (retain, nonatomic) WALocationPrivacySampler *locationGeocodingSampler; // ivar: _locationGeocodingSampler
@property (retain) NSMutableDictionary *priorityCompletionHandlersForCity; // ivar: _priorityCompletionHandlersForCity
@property (retain) NSOperationQueue *priorityForecastOperationQueue; // ivar: _priorityForecastOperationQueue
@property (retain) NSMutableSet *priorityUpdatingCities; // ivar: _priorityUpdatingCities
@property (readonly) WFWeatherStoreService *store; // ivar: _store
@property (copy) NSString *trackingParameter; // ivar: _trackingParameter
@property (retain) NSMutableSet *updatingCities; // ivar: _updatingCities


-(BOOL)fetchForecastForCities:(id)arg0 completion:(id)arg1 ;
-(BOOL)fetchForecastForCity:(id)arg0 completion:(id)arg1 ;
-(BOOL)fetchForecastForCity:(id)arg0 withUnits:(int)arg1 completion:(id)arg2 ;
-(BOOL)fetchForecastForCity:(id)arg0 withUnits:(int)arg1 requestOptions:(id)arg2 completion:(id)arg3 ;
-(BOOL)isCityBeingUpdated:(id)arg0 ;
-(BOOL)isPriorityCity:(id)arg0 ;
-(BOOL)isPriorityCityBeingUpdated:(id)arg0 ;
-(BOOL)isPriorityForecastOperationsEnabled;
-(id)_commaSeparatedNamesForUpdatingCities:(id)arg0 ;
-(id)_commaSeparatedPriorityUpdatingCitiesNames;
-(id)_commaSeparatedUpdatingCitiesNames;
-(id)_queue_executeFetchForCity:(id)arg0 completion:(id)arg1 ;
-(id)_queue_executeFetchForCity:(id)arg0 withUnits:(int)arg1 requestOptions:(id)arg2 completion:(id)arg3 ;
// -(id)_queue_executeFetchForCity:(id)arg0 withUnits:(int)arg1 requestOptions:(id)arg2 completion:(id)arg3 completionHandlersForCity:(unk)arg4 updatingCities:(id)arg5  ;
-(id)init;
-(void)_handleForecastOperationCompletion:(id)arg0 ;
-(void)cancelAllFetchRequests;
-(void)dealloc;


@end


#endif