// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef TWCCITYUPDATER_H
#define TWCCITYUPDATER_H

@class NSLocale, WALocationPrivacySampler, NSString;
@protocol WeatherUpdaterDelegate;

#import <Foundation/Foundation.h>

#import "WAForecastModelController.h"

@interface TWCCityUpdater : NSObject

@property (weak, nonatomic) NSObject<WeatherUpdaterDelegate> *delegate; // ivar: _delegate
@property (retain, nonatomic) WAForecastModelController *forecastModelController; // ivar: _forecastModelController
@property (retain, nonatomic) NSLocale *locale; // ivar: _locale
@property (readonly, nonatomic) WALocationPrivacySampler *locationGeocodingSampler; // ivar: _locationGeocodingSampler
@property (retain, nonatomic) NSString *trackingParameter;


+(id)sharedCityUpdater;
-(BOOL)isUpdatingCity:(id)arg0 ;
-(id)init;
-(void)cancel;
-(void)configureWithLocationGeocodingSampler:(id)arg0 ;
-(void)updateWeatherForCities:(id)arg0 ;
-(void)updateWeatherForCities:(id)arg0 withCompletionHandler:(id)arg1 ;
-(void)updateWeatherForCity:(id)arg0 ;


@end


#endif