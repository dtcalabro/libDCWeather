// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WEATHERLOCATIONMANAGER_H
#define WEATHERLOCATIONMANAGER_H

@class NSTimer, NSString, NSDate, CLLocationManager;

#import <Foundation/Foundation.h>

#import "WeatherPreferences.h"
#import "CLLocationManagerDelegate-Protocol.h"
#import "CLLocationManagerDelegate-Protocol.h"

@interface WeatherLocationManager : NSObject <CLLocationManagerDelegate>



@property (retain, nonatomic) NSTimer *accuracyFallbackTimer; // ivar: _accuracyFallbackTimer
@property (nonatomic) int authorizationStatus; // ivar: _authorizationStatus
@property (readonly, copy) NSString *debugDescription;
@property (retain, nonatomic) NSTimer *delayedUpdateTimer; // ivar: _delayedUpdateTimer
@property (weak, nonatomic) NSObject<CLLocationManagerDelegate> *delegate; // ivar: _delegate
@property (readonly, copy) NSString *description;
@property (readonly, nonatomic) CGFloat distanceFilter;
@property (readonly, copy, nonatomic) NSString *effectiveBundleIdentifier; // ivar: _effectiveBundleIdentifier
@property (readonly) NSUInteger hash;
@property (nonatomic) BOOL isInternalBuild; // ivar: _isInternalBuild
@property (nonatomic) float lastLocationAccuracy; // ivar: _lastLocationAccuracy
@property (nonatomic) struct CLLocationCoordinate2D lastLocationCoord; // ivar: _lastLocationCoord
@property (copy, nonatomic) NSDate *lastLocationTimeStamp; // ivar: _lastLocationTimeStamp
@property (nonatomic) CGFloat lastLocationUpdateTime; // ivar: _lastLocationUpdateTime
@property (readonly, nonatomic) BOOL limitsPrecision;
@property (retain, nonatomic) CLLocationManager *locationManager; // ivar: _locationManager
@property (nonatomic) BOOL locationTrackingIsReady; // ivar: _locationTrackingIsReady
@property (nonatomic) BOOL locationUpdatesEnabled; // ivar: _locationUpdatesEnabled
@property (nonatomic) CGFloat nextPlannedUpdate; // ivar: _nextPlannedUpdate
@property (nonatomic) CGFloat oldestAllowedUpdateTime; // ivar: _oldestAllowedUpdateTime
@property (retain, nonatomic) WeatherPreferences *preferences; // ivar: _preferences
@property (readonly) Class superclass;
@property (nonatomic) NSUInteger updateInterval; // ivar: _updateInterval


+(id)sharedWeatherLocationManager;
+(int)locationManagerAuthorizationWithEffectiveBundleId:(id)arg0 ;
+(void)clearSharedLocationManager;
-(BOOL)hasCrossedHourBoundary;
-(BOOL)isCacheOutOfDate;
-(BOOL)isLocalStaleOrOutOfDate;
-(BOOL)isLocationWithInRange:(id)arg0 ;
-(BOOL)localWeatherAuthorized;
-(id)init;
-(id)initWithPreferences:(id)arg0 ;
-(id)initWithPreferences:(id)arg0 effectiveBundleIdentifier:(id)arg1 ;
-(id)location;
-(int)forceLoadingAuthorizationStatus;
-(void)accuracyFallbackTimerDidFire:(id)arg0 ;
-(void)askForLocationManagerAuthorization;
-(void)cancelAccuracyFallbackTimer;
-(void)cancelDelayedUpdateTimer;
-(void)clearLastLocationUpdateTime;
-(void)clearLocalWeatherUpdateState;
-(void)dealloc;
-(void)delayedUpdateTimerDidFire:(id)arg0 ;
-(void)forceLocationManagerAuthorization;
-(void)forceLocationUpdate;
-(void)locationManager:(id)arg0 didChangeAuthorizationStatus:(int)arg1 ;
-(void)locationManager:(id)arg0 didFailWithError:(id)arg1 ;
-(void)locationManager:(id)arg0 didUpdateLocations:(id)arg1 ;
-(void)monitorLocationAuthorization;
-(void)scheduleDelayedUpdate:(CGFloat)arg0 ;
-(void)setLocationTrackingActive:(BOOL)arg0 ;
-(void)setLocationTrackingReady:(BOOL)arg0 activelyTracking:(BOOL)arg1 watchKitExtension:(BOOL)arg2 ;
-(void)setLocationTrackingReady:(BOOL)arg0 activelyTracking:(BOOL)arg1 watchKitExtension:(BOOL)arg2 shouldRequestAuthorization:(BOOL)arg3 ;
-(void)stopLocationUpdate;
-(void)updateLocation:(id)arg0 ;
-(void)updateLocationWithNoConditionCheck;


@end


#endif