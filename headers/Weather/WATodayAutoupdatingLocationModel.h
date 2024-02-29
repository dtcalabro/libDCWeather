// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WATODAYAUTOUPDATINGLOCATIONMODEL_H
#define WATODAYAUTOUPDATINGLOCATIONMODEL_H

@class NSString, WFGeocodeRequest, NSDate;


#import "WATodayModel.h"
#import "WeatherLocationManager.h"
#import "WeatherPreferences.h"
#import "CLLocationManagerDelegate-Protocol.h"
#import "SynchronizedDefaultsDelegate-Protocol.h"

@interface WATodayAutoupdatingLocationModel : WATodayModel <CLLocationManagerDelegate, SynchronizedDefaultsDelegate>



//@property (copy, nonatomic) id *WeatherLocationManagerGenerator; // ivar: _WeatherLocationManagerGenerator
@property (nonatomic) NSUInteger citySource; // ivar: _citySource
@property (readonly, copy) NSString *debugDescription;
@property (readonly, copy) NSString *description;
@property (nonatomic) NSUInteger fallbackCitySource; // ivar: _fallbackCitySource
@property (retain, nonatomic) WFGeocodeRequest *geocodeRequest; // ivar: _geocodeRequest
@property (readonly) NSUInteger hash;
@property (nonatomic) BOOL isLocationTrackingEnabled; // ivar: _isLocationTrackingEnabled
@property (retain, nonatomic) NSDate *lastLocationUpdateDate; // ivar: _lastLocationUpdateDate
@property (retain, nonatomic) WeatherLocationManager *locationManager; // ivar: _locationManager
@property (nonatomic) BOOL locationServicesActive; // ivar: _locationServicesActive
@property (readonly, nonatomic) CGFloat minDistanceChangeInMeters; // ivar: _minDistanceChangeInMeters
@property (readonly, nonatomic) CGFloat minTimeBetweenUpdates; // ivar: _minTimeBetweenUpdates
@property (retain, nonatomic) WeatherPreferences *preferences; // ivar: _preferences
@property (nonatomic) BOOL stopUpdateIfNeeded; // ivar: _stopUpdateIfNeeded
@property (readonly) Class superclass;


-(BOOL)_reloadForecastData:(BOOL)arg0 ;
-(BOOL)shouldNotUseUpdatedLocation;
-(BOOL)shouldUseNewLocation:(id)arg0 oldLocation:(id)arg1 ;
-(BOOL)updateLocationTrackingStatus;
-(id)forecastModel;
-(id)init;
-(id)initWithPreferences:(id)arg0 effectiveBundleIdentifier:(id)arg1 ;
-(void)_executeLocationUpdateForFirstWeatherCityWithCompletion:(id)arg0 ;
-(void)_executeLocationUpdateForLocalWeatherCityWithCompletion:(id)arg0 ;
-(void)_executeLocationUpdateWithCompletion:(id)arg0 ;
-(void)_kickstartLocationManager;
-(void)_persistStateWithModel:(id)arg0 ;
-(void)_teardownLocationManager;
-(void)_willDeliverForecastModel:(id)arg0 ;
-(void)checkIfNeedsToUpdate;
-(void)clearLocationUpdateState;
-(void)configureWithInitialCitySource:(NSUInteger)arg0 locationServicesActive:(BOOL)arg1 ;
-(void)configureWithLocationServicesActive:(BOOL)arg0 ;
-(void)dealloc;
-(void)locationManager:(id)arg0 didChangeAuthorizationStatus:(int)arg1 ;
-(void)locationManager:(id)arg0 didUpdateLocations:(id)arg1 ;
-(void)syncLastUpdateTime;
-(void)ubiquitousDefaultsDidChange:(id)arg0 ;
-(void)weatherPreferencesWereSynchronized;


@end


#endif