// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WEATHERCLOUDPREFERENCES_H
#define WEATHERCLOUDPREFERENCES_H

@class NSString;

#import <Foundation/Foundation.h>

//#import "WeatherPreferences.h"
#import "WeatherCloudPersistenceDelegate-Protocol.h"
#import "WeatherPreferencesPersistence-Protocol.h"
#import "SynchronizedDefaultsDelegate-Protocol.h"

@class WeatherPreferences;

@interface WeatherCloudPreferences : NSObject <WeatherCloudPersistenceDelegate>



@property (retain, nonatomic) NSObject<WeatherPreferencesPersistence> *cloudStore; // ivar: _cloudStore
@property (readonly, copy) NSString *debugDescription;
@property (readonly, copy) NSString *description;
@property (readonly) NSUInteger hash;
@property (retain) WeatherPreferences *localPreferences; // ivar: _localPreferences
@property (readonly) Class superclass;
@property (weak, nonatomic) NSObject<SynchronizedDefaultsDelegate> *syncDelegate; // ivar: _syncDelegate


-(BOOL)areCloudCities:(id)arg0 equalToLocalCities:(id)arg1 ;
-(BOOL)shouldWriteCitiesToCloud:(id)arg0 ;
-(id)citiesByEnforcingSizeLimitOnResults:(id)arg0 ;
-(id)cloudRepresentationFromCities:(id)arg0 ;
-(id)initWithLocalPreferences:(id)arg0 ;
-(id)initWithLocalPreferences:(id)arg0 persistence:(id)arg1 ;
-(id)prepareLocalCitiesForReconciliation:(id)arg0 isInitialSync:(BOOL)arg1 ;
-(id)reconcileCloudCities:(id)arg0 withLocal:(id)arg1 isInitialSync:(BOOL)arg2 ;
-(void)_synchronize:(BOOL)arg0 ;
-(void)cloudCitiesChangedExternally:(id)arg0 ;
-(void)cloudPersistenceDidSynchronize:(id)arg0 ;
-(void)forceSync;
-(void)purgeLegacyCloudCities;
-(void)saveCitiesToCloud:(id)arg0 ;
-(void)updateLocalStoreWithRemoteChanges:(id)arg0 ;


@end


#endif