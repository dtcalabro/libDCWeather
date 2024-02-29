// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WEATHERVIEW_H
#define WEATHERVIEW_H

@class UIView, NSLocale, NSString;


#import "City.h"
#import "CityUpdateObserver-Protocol.h"

@interface WeatherView : UIView <CityUpdateObserver>

 {
    BOOL _showingDay;
    BOOL _showWind;
    UIView *_windView;
    NSLocale *_lastLocale;
}


@property (retain, nonatomic, setter=showCity:) City *city; // ivar: _city
@property (readonly, copy) NSString *debugDescription;
@property (readonly, copy) NSString *description;
@property (readonly) NSUInteger hash;
@property (readonly) Class superclass;


-(BOOL)_setCity:(City *)city associateAsDelegate:(BOOL)arg1 ;
-(BOOL)updateWeatherDisplayForCity:(City *)city ;
-(id)bundle;
-(id)initWithFrame:(struct CGRect )arg0 ;
-(void)cityDidFinishWeatherUpdate:(id)arg0 ;
-(void)cityDidStartWeatherUpdate:(id)arg0 ;
-(void)cleanupWindView;
-(void)dealloc;
-(void)refreshLocalization;
-(void)resetLocale:(id)arg0 ;
-(void)showCity:(City *)city ;


@end


#endif