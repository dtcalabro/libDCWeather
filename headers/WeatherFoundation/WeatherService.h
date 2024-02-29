// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WEATHERSERVICE_H
#define WEATHERSERVICE_H

@class NSMutableArray, NSMapTable, NSArray, NSString;
@protocol OS_dispatch_queue;

#import <Foundation/Foundation.h>

#import "WFWeatherStoreService.h"
#import "WFQueryDispatcher.h"
#import "WFTemperatureUnitProvider.h"
#import "WeatherServiceProtocol-Protocol.h"
#import "WeatherServicePrivateProtocol-Protocol.h"

@interface WeatherService : NSObject <WeatherServiceProtocol, WeatherServicePrivateProtocol>

 {
    NSMutableArray *_clients;
    NSObject<OS_dispatch_queue> *_clientQueue;
}


@property (retain) NSMapTable *clientDictionary; // ivar: _clientDictionary
@property (readonly, nonatomic) NSArray *clients;
@property (readonly, copy) NSString *debugDescription;
@property (readonly, copy) NSString *description;
@property (readonly) NSUInteger hash;
@property (retain) WFWeatherStoreService *internalService; // ivar: _internalService
@property (retain) WFQueryDispatcher *queryDispatcher; // ivar: _queryDispatcher
@property (readonly) Class superclass;
@property (retain, nonatomic) WFTemperatureUnitProvider *temperatureUnitProvider; // ivar: _temperatureUnitProvider


+(id)sharedService;
-(id)clientForPid:(int)arg0 ;
-(id)init;
-(id)initWithStore:(id)arg0 ;
-(void)addClient:(id)arg0 ;
-(void)addClient:(id)arg0 forPid:(int)arg1 ;
-(void)airQualityForLocation:(id)arg0 locale:(id)arg1 options:(id)arg2 taskIdentifier:(id)arg3 ;
-(void)cancelTaskWithIdentifier:(id)arg0 ;
-(void)dailyForecastForLocation:(id)arg0 locale:(id)arg1 taskIdentifier:(id)arg2 ;
-(void)fetchFavoriteLocationsWithTaskIdentifier:(id)arg0 ;
-(void)forecast:(NSUInteger)arg0 forLocation:(id)arg1 locale:(id)arg2 taskIdentifier:(id)arg3 ;
-(void)forecast:(NSUInteger)arg0 forLocation:(id)arg1 withUnits:(int)arg2 locale:(id)arg3 taskIdentifier:(id)arg4 ;
-(void)forecast:(NSUInteger)arg0 forLocation:(id)arg1 withUnits:(int)arg2 locale:(id)arg3 taskIdentifier:(id)arg4 requestOptions:(id)arg5 ;
-(void)forecastForLocation:(id)arg0 locale:(id)arg1 onDate:(id)arg2 options:(id)arg3 taskIdentifier:(id)arg4 ;
-(void)hourlyForecastForLocation:(id)arg0 locale:(id)arg1 taskIdentifier:(id)arg2 ;
-(void)invalidateCache:(id)arg0 ;
-(void)locationForCoordinate:(struct CLLocationCoordinate2D )arg0 taskIdentifier:(id)arg1 ;
-(void)locationForSearchCompletion:(id)arg0 taskIdentifier:(id)arg1 ;
-(void)locationForString:(id)arg0 taskIdentifier:(id)arg1 ;
-(void)performMigrationWithCompletion:(id)arg0 ;
-(void)queryDispatcherDidReceiveResponse:(id)arg0 identifier:(id)arg1 ;
-(void)reachabilityConfigurationForIdentifier:(id)arg0 ;
-(void)removeClient:(id)arg0 ;
-(void)replaceTemperatureUnitWith:(int)arg0 identifier:(id)arg1 ;
-(void)temperatureUnitWithIdentifier:(id)arg0 ;


@end


#endif