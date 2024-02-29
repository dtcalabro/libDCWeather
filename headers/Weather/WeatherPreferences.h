// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WEATHERPREFERENCES_H
#define WEATHERPREFERENCES_H

@class NSString, NSArray, NSDate;

#import <Foundation/Foundation.h>

#import "WeatherCloudPreferences.h"
#import "City.h"
#import "WFTemperatureUnitObserver-Protocol.h"
#import "NSURLConnectionDelegate-Protocol.h"
#import "WeatherPreferencesPersistence-Protocol.h"
#import "SynchronizedDefaultsDelegate-Protocol.h"

@interface WeatherPreferences : NSObject <WFTemperatureUnitObserver, NSURLConnectionDelegate>
{
    NSString *_UUID;
    BOOL _serviceDebugging;
    NSArray *_lastUbiquitousWrittenDefaults;
    __strong id<WeatherPreferencesPersistence> *_persistence;
    NSString *_cacheDirectoryPath;
    BOOL _logUnitsAndLocale;
}

@property (retain) WeatherCloudPreferences *cloudPreferences; // ivar: _cloudPreferences
@property (readonly, copy) NSString *debugDescription;
@property (readonly, copy) NSString *description;
@property (readonly) NSUInteger hash;
@property (nonatomic, getter=isLocalWeatherEnabled, setter=setLocalWeatherEnabled:) BOOL isLocalWeatherEnabled;
@property (readonly, weak, nonatomic) NSDate *lastUpdated;
@property (readonly, nonatomic) City *localWeatherCity;
@property (readonly) Class superclass;
@property (weak, nonatomic) NSObject<SynchronizedDefaultsDelegate> *syncDelegate; // ivar: _syncDelegate
@property (nonatomic) BOOL userGroupPrefsLockedWhenInit; // ivar: _userGroupPrefsLockedWhenInit
@property (readonly) int userTemperatureUnit;

+(BOOL)performUpgradeOfPersistence:(id)arg0 fileManager:(id)arg1 error:(id*)arg2 ;
+(id)preferencesWithPersistence:(id)arg0 ;
+(id)readInternalDefaultValueForKey:(id)arg0 ;
+(id)serviceDebuggingPath;
+(id)sharedPreferences;
+(id)userDefaultsPersistence;
-(BOOL)_defaultsAreValid;
-(BOOL)_defaultsCurrent;
-(BOOL)areCitiesDefault:(id)arg0 ;
-(BOOL)ensureValidSelectedCityID;
-(BOOL)isCelsius;
-(BOOL)readTemperatureUnits;
-(BOOL)serviceDebugging;
-(id)UUID;
-(id)_cacheDirectoryPath;
-(id)_defaultCities;
-(id)citiesByConsolidatingDuplicates:(id)arg0 originalOrder:(id)arg1 ;
-(id)citiesByConsolidatingDuplicatesInBucket:(id)arg0 ;
-(id)cityFromPreferencesDictionary:(id)arg0 ;
-(id)init;
-(id)initWithPersistence:(id)arg0 ;
-(id)loadDefaultSelectedCityID;
-(id)loadSavedCities;
-(id)preferencesDictionaryForCity:(id)arg0 ;
-(id)readDefaultValueForKey:(id)arg0 ;
-(id)readInternalDefaultValueForKey:(id)arg0 ;
-(id)twcLogoURL;
-(id)twcLogoURL:(id)arg0 ;
-(int)loadActiveCity;
-(int)loadDefaultSelectedCity;
-(void)_clearCachedObjects;
-(void)adjustPrefsForLocalWeatherEnabled:(BOOL)arg0 ;
-(void)forceSyncCloudPreferences;
-(void)registerTemperatureUnits;
-(void)resetLocale;
-(void)saveToDiskWithCities:(id)arg0 ;
-(void)saveToDiskWithCities:(id)arg0 activeCity:(NSUInteger)arg1 ;
-(void)saveToDiskWithCity:(id)arg0 forActiveIndex:(NSUInteger)arg1 ;
-(void)saveToDiskWithLocalWeatherCity:(id)arg0 ;
-(void)saveToUbiquitousStore;
-(void)setActiveCity:(NSUInteger)arg0 ;
-(void)setCelsius:(BOOL)arg0 ;
-(void)setDefaultCities:(id)arg0 ;
-(void)setDefaultSelectedCity:(NSUInteger)arg0 ;
-(void)setDefaultSelectedCityID:(id)arg0 ;
-(void)setupUbiquitousStoreIfNeeded;
-(void)synchronizeStateToDisk;
-(void)synchronizeStateToDiskDoNotify:(BOOL)arg0 ;
-(void)temperatureUnitObserver:(id)arg0 didChangeTemperatureUnitTo:(int)arg1 ;
-(void)writeDefaultValue:(id)arg0 forKey:(id)arg1 ;

@end

#endif