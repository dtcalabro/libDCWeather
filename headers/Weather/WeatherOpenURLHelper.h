// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WEATHEROPENURLHELPER_H
#define WEATHEROPENURLHELPER_H


#import <Foundation/Foundation.h>


@interface WeatherOpenURLHelper : NSObject



+(BOOL)handleOpenURL:(id)arg0 withContainerViewController:(id)arg1 ;
+(BOOL)handleOpenURL:(id)arg0 withContainerViewController:(id)arg1 completion:(id)arg2 ;
+(id)URLForCity:(id)arg0 ;
+(id)URLForWeatherCityComponents:(id)arg0 ;
+(id)cityFromURL:(id)arg0 withContainerViewController:(id)arg1 ;
+(id)cityFromURLComponents:(id)arg0 listedCities:(id)arg1 ;
+(id)transientCityFromURLComponents:(id)arg0 ;
+(void)displayCity:(id)arg0 usingController:(id)arg1 completion:(id)arg2 ;
+(void)presentAddTransientCityDialog:(id)arg0 usingController:(id)arg1 ;


@end


#endif