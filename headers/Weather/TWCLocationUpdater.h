// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef TWCLOCATIONUPDATER_H
#define TWCLOCATIONUPDATER_H

@class CLGeocoder;

#import "Weather-Structs.h"
#import "TWCCityUpdater.h"
#import "City.h"

@interface TWCLocationUpdater : TWCCityUpdater

@property (retain, nonatomic) City *currentCity; // ivar: _currentCity
@property (nonatomic) struct ct_green_tea_logger_s* greenTeaLogger; // ivar: _greenTeaLogger
@property (retain, nonatomic) CLGeocoder *reverseGeocoder; // ivar: _reverseGeocoder


+(id)sharedLocationUpdater;
-(id)init;
-(void)_completeReverseGeocodeForLocation:(id)arg0 currentCity:(id)arg1 geocodeError:(id)arg2 completionHandler:(id)arg3 ;
-(void)_geocodeLocation:(id)arg0 currentCity:(id)arg1 completionHandler:(id)arg2 ;
-(void)_updateWeatherForLocation:(id)arg0 city:(id)arg1 completionHandler:(id)arg2 ;
-(void)dealloc;
-(void)enableProgressIndicator:(BOOL)arg0 ;
-(void)parsedResultCity:(id)arg0 ;
-(void)updateWeatherForCities:(id)arg0 withCompletionHandler:(id)arg1 ;
-(void)updateWeatherForCity:(id)arg0 ;
-(void)updateWeatherForLocation:(id)arg0 city:(id)arg1 ;
-(void)updateWeatherForLocation:(id)arg0 city:(id)arg1 isFromFrameworkClient:(BOOL)arg2 withCompletionHandler:(id)arg3 ;


@end


#endif