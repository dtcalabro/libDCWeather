// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFREMOTEAPPSETTINGS_H
#define WFREMOTEAPPSETTINGS_H

@class NSString, NSURL, NSSet, NSDictionary, NSDate;

#import <Foundation/Foundation.h>

#import "WFWeatherEventsConfig.h"
#import "WFSettings-Protocol.h"

@interface WFRemoteAppSettings : NSObject <WFSettings>



@property (readonly, nonatomic) NSUInteger apiConfigMaxRange; // ivar: _apiConfigMaxRange
@property (readonly, nonatomic) NSUInteger apiConfigMinRange; // ivar: _apiConfigMinRange
@property (readonly, nonatomic) NSUInteger apiConfigModdedHash; // ivar: _apiConfigModdedHash
@property (readonly, nonatomic) NSString *apiVersion; // ivar: _apiVersion
@property (readonly, nonatomic) NSString *apiVersionFallback; // ivar: _apiVersionFallback
@property (readonly, nonatomic) NSURL *appAnalyticsEndpointUrl; // ivar: _appAnalyticsEndpointUrl
@property (readonly, nonatomic) NSInteger appConfigRefreshRate; // ivar: _appConfigRefreshRate
@property (readonly, nonatomic) NSSet *aqiEnabledCountryCodes; // ivar: _aqiEnabledCountryCodes
@property (readonly, nonatomic) NSString *bundleID; // ivar: _bundleID
@property (readonly, nonatomic) CGFloat cachedGeocodeLocationExpirationTimeInterval; // ivar: _cachedGeocodeLocationExpirationTimeInterval
@property (readonly, nonatomic) NSDictionary *config; // ivar: _config
@property (readonly, nonatomic) NSString *countryCode; // ivar: _countryCode
@property (readonly, nonatomic) float dataSamplingRate; // ivar: _dataSamplingRate
@property (readonly, copy) NSString *debugDescription;
@property (readonly, copy) NSString *description;
@property (readonly, nonatomic) BOOL disableForecastRequestCancelation; // ivar: _disableForecastRequestCancelation
@property (readonly, nonatomic) BOOL disableLimitReverseGeocoding; // ivar: _disableLimitReverseGeocoding
@property (readonly, nonatomic) BOOL disablePriorityForecastRequestQueue; // ivar: _disablePriorityForecastRequestQueue
@property (readonly) NSUInteger hash;
@property (readonly, nonatomic) BOOL isExpired;
@property (readonly, nonatomic) NSDate *lastModificationDate; // ivar: _lastModificationDate
@property (readonly, nonatomic) BOOL loadSavedCitiesFromKVSOnly; // ivar: _loadSavedCitiesFromKVSOnly
@property (readonly, nonatomic) float locationGeocodingSamplingRate; // ivar: _locationGeocodingSamplingRate
@property (readonly, nonatomic) NSUInteger locationNumDecimalsOfPrecision; // ivar: _locationNumDecimalsOfPrecision
@property (readonly, nonatomic) CGFloat locationUpdateMinDistance; // ivar: _locationUpdateMinDistance
@property (readonly, nonatomic) CGFloat locationUpdateMinTimeInterval; // ivar: _locationUpdateMinTimeInterval
@property (readonly, nonatomic) NSUInteger networkFailedAttemptsLimit; // ivar: _networkFailedAttemptsLimit
@property (readonly, nonatomic) NSUInteger networkSwitchExpirationTimeInSeconds; // ivar: _networkSwitchExpirationTimeInSeconds
@property (readonly, nonatomic) CGFloat privateUserIdentifierResetTimeInterval; // ivar: _privateUserIdentifierResetTimeInterval
@property (readonly) Class superclass;
@property (readonly, nonatomic) float telemetrySamplingRate; // ivar: _telemetrySamplingRate
@property (readonly, nonatomic) CGFloat userIdentifierResetTimeInterval; // ivar: _userIdentifierResetTimeInterval
@property (readonly, nonatomic) WFWeatherEventsConfig *weatherEventsConfig; // ivar: _weatherEventsConfig
@property (readonly, nonatomic) NSDictionary *widgetRefreshPolicy; // ivar: _widgetRefreshPolicy


+(BOOL)useInternalBundleID;
+(BOOL)wfInternalBuild;
+(BOOL)wfSeedBuild;
+(id)bundleIDsListFor:(id)arg0 useInternalBundleID:(BOOL)arg1 useSeedBundleID:(BOOL)arg2 ;
+(id)configurationWithData:(id)arg0 bundleIDs:(id)arg1 country:(id)arg2 userID:(id)arg3 error:(id*)arg4 ;
+(id)configurationWithData:(id)arg0 userID:(id)arg1 error:(id*)arg2 ;
+(id)defaultSettings;
-(BOOL)aqiEnabledForCountryCode:(id)arg0 ;
-(BOOL)shouldUseAPIVersionFromDictionary:(id)arg0 userID:(id)arg1 ;
-(id)copyWithZone:(struct _NSZone *)arg0 ;
-(id)getAPIVersionFromDictionary:(id)arg0 userID:(id)arg1 ;
-(id)getEnvironmentSpecificConfigDictionaryFromDictionary:(id)arg0 bundleIDs:(id)arg1 country:(id)arg2 ;
-(id)getSpecificConfigFromConfigs:(id)arg0 configSpecifiers:(id)arg1 specifierKey:(id)arg2 ;
-(id)initWithConfigDictionary:(id)arg0 bundleIDs:(id)arg1 country:(id)arg2 userID:(id)arg3 ;


@end


#endif