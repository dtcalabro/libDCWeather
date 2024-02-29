// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFWEATHERSTORESERVICE_H
#define WFWEATHERSTORESERVICE_H

@class NSMutableDictionary, NSString;
@protocol OS_dispatch_queue;

#import <Foundation/Foundation.h>

#import "WFWeatherStoreCache.h"
#import "WFWeatherStoreServiceConfiguration.h"
#import "WFNetworkRetryManager.h"
#import "WFWeatherStore-Protocol.h"

@interface WFWeatherStoreService : NSObject <WFWeatherStore>



@property (retain) NSMutableDictionary *URLToCallbackMap; // ivar: _URLToCallbackMap
@property (retain) NSMutableDictionary *URLToTaskMap; // ivar: _URLToTaskMap
@property (retain) NSMutableDictionary *UUIDToCallbackMap; // ivar: _UUIDToCallbackMap
@property (retain) NSMutableDictionary *UUIDToURLMap; // ivar: _UUIDToURLMap
@property (retain) WFWeatherStoreCache *cache; // ivar: _cache
@property (copy, nonatomic) WFWeatherStoreServiceConfiguration *configuration; // ivar: _configuration
@property (readonly, copy) NSString *debugDescription;
@property (readonly, copy) NSString *description;
@property (copy, nonatomic) id forecastRequestStartingCallback; // ivar: _forecastRequestStartingCallback
@property (readonly) NSUInteger hash;
@property (retain) NSObject<OS_dispatch_queue> *incomingRequestQueue; // ivar: _incomingRequestQueue
@property (copy, nonatomic) id locationGeocodeForCoordinateRequestStartingCallback; // ivar: _locationGeocodeForCoordinateRequestStartingCallback
@property (retain) NSObject<OS_dispatch_queue> *mapQueue; // ivar: _mapQueue
@property (retain) NSObject<OS_dispatch_queue> *parseQueue; // ivar: _parseQueue
@property os_unfair_lock_s retryLock; // ivar: _retryLock
@property (retain, nonatomic) WFNetworkRetryManager *retryManager; // ivar: _retryManager
@property (readonly) Class superclass;


-(BOOL)_cacheParsedForecastData:(id)arg0 types:(NSUInteger)arg1 location:(id)arg2 date:(id)arg3 requestIdentifier:(id)arg4 ;
-(BOOL)_handleDataTaskCompletionWithData:(id)arg0 httpResponse:(id)arg1 apiVersion:(id)arg2 identifier:(id)arg3 requestURL:(id)arg4 dataTask:(id)arg5 dataTaskError:(id)arg6 startDate:(id)arg7 ;
-(BOOL)_isConnectivityAvailableForWeatherHost:(id*)arg0 ;
-(id)_cachedAirQualityConditionsForLocation:(id)arg0 date:(id)arg1 ;
-(id)_cachedChangeForecastForLocation:(id)arg0 date:(id)arg1 ;
-(id)_cachedCurrentObservationsForLocation:(id)arg0 date:(id)arg1 ;
-(id)_cachedDailyForecastedConditionsForLocation:(id)arg0 date:(id)arg1 ;
-(id)_cachedDailyPollenForecastedConditionsForLocation:(id)arg0 date:(id)arg1 ;
-(id)_cachedData:(NSUInteger)arg0 forLocation:(id)arg1 date:(id)arg2 ;
-(id)_cachedHistoricalObservationsForLast24hForLocation:(id)arg0 date:(id)arg1 ;
-(id)_cachedHourlyForecastedConditionsForLocation:(id)arg0 date:(id)arg1 ;
-(id)_cachedNextHourPrecipitationForLocation:(id)arg0 date:(id)arg1 ;
-(id)_cachedSevereWeatherEventsForLocation:(id)arg0 date:(id)arg1 ;
-(id)_currentScaleCategoryForScale:(id)arg0 index:(NSUInteger)arg1 ;
-(id)_taskForURL:(id)arg0 ;
-(id)apiVersionForSettings:(id)arg0 ;
-(id)init;
-(id)initWithConfiguration:(id)arg0 ;
-(id)initWithConfiguration:(id)arg0 error:(id*)arg1 ;
-(id)languageForLocale:(id)arg0 ;
-(void)_addCallback:(id)arg0 requestIdentifier:(id)arg1 forURL:(id)arg2 ;
-(void)_cacheObject:(id)arg0 type:(NSUInteger)arg1 date:(id)arg2 forLocation:(id)arg3 ;
-(void)_cancelWithRequestIdentifier:(id)arg0 ;
-(void)_cleanupCallbacksAndTasksForURL:(id)arg0 ;
-(void)_enumerateForecastTypesIn:(NSUInteger)arg0 usingBlock:(id)arg1 ;
-(void)_executeCallbacksForURL:(id)arg0 responseData:(id)arg1 error:(id)arg2 ;
-(void)_forecastConditionsForTWCAQIAndTypes:(NSUInteger)arg0 location:(id)arg1 locale:(id)arg2 date:(id)arg3 requestIdentifier:(id)arg4 completionHandler:(id)arg5 ;
-(void)_forecastConditionsForTypes:(NSUInteger)arg0 location:(id)arg1 locale:(id)arg2 date:(id)arg3 requestIdentifier:(id)arg4 completionHandler:(id)arg5 ;
-(void)_forecastConditionsForTypes:(NSUInteger)arg0 location:(id)arg1 units:(int)arg2 locale:(id)arg3 date:(id)arg4 requestIdentifier:(id)arg5 requestOptions:(id)arg6 completionHandler:(id)arg7 ;
-(void)_setTask:(id)arg0 requestIdentifier:(id)arg1 callback:(id)arg2 forURL:(id)arg3 ;
-(void)_submitRequest:(id)arg0 withIdentifier:(id)arg1 forLocation:(id)arg2 forecastTypes:(NSUInteger)arg3 configuration:(id)arg4 units:(int)arg5 locale:(id)arg6 date:(id)arg7 apiVersion:(id)arg8 completionHandler:(id)arg9 ;
-(void)_submitRequest:(id)arg0 withIdentifier:(id)arg1 forScaleNamed:(id)arg2 language:(id)arg3 configuration:(id)arg4 apiVersion:(id)arg5 completionHandler:(id)arg6 ;
-(void)airQualityForLocation:(id)arg0 locale:(id)arg1 requestIdentifier:(id)arg2 options:(id)arg3 completionHandler:(id)arg4 ;
-(void)cancelTaskWithIdentifier:(id)arg0 ;
// -(void)completeErroneousForecastRequestWithHandler:(id)arg0 requestIdentifier:(unk)arg1 error:(id)arg2  ;
-(void)dailyForecastForLocation:(id)arg0 locale:(id)arg1 requestIdentifier:(id)arg2 completionHandler:(id)arg3 ;
-(void)dealloc;
-(void)forecast:(NSUInteger)arg0 forLocation:(id)arg1 locale:(id)arg2 requestIdentifier:(id)arg3 completionHandler:(id)arg4 ;
-(void)forecast:(NSUInteger)arg0 forLocation:(id)arg1 withUnits:(int)arg2 locale:(id)arg3 requestIdentifier:(id)arg4 completionHandler:(id)arg5 ;
-(void)forecast:(NSUInteger)arg0 forLocation:(id)arg1 withUnits:(int)arg2 locale:(id)arg3 requestIdentifier:(id)arg4 requestOptions:(id)arg5 completionHandler:(id)arg6 ;
-(void)forecastForLocation:(id)arg0 locale:(id)arg1 onDate:(id)arg2 requestIdentifier:(id)arg3 options:(id)arg4 completionHandler:(id)arg5 ;
-(void)hourlyForecastForLocation:(id)arg0 locale:(id)arg1 requestIdentifier:(id)arg2 completionHandler:(id)arg3 ;
-(void)invalidateCacheWithIdentifier:(id)arg0 ;
-(void)requestFailureForAPIVersion:(id)arg0 error:(id)arg1 ;
-(void)requestSuccessForAPIVersion:(id)arg0 ;


@end


#endif