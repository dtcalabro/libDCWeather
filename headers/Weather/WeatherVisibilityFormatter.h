// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WEATHERVISIBILITYFORMATTER_H
#define WEATHERVISIBILITYFORMATTER_H

@class NSLengthFormatter, NSLocale;



@interface WeatherVisibilityFormatter : NSLengthFormatter

@property (retain, nonatomic) NSLocale *locale; // ivar: _locale


+(id)convenienceFormatter;
-(id)init;
-(id)stringFromDistance:(CGFloat)arg0 isDataMetric:(BOOL)arg1 ;
-(id)stringFromKilometers:(CGFloat)arg0 ;
-(id)stringFromMiles:(CGFloat)arg0 ;


@end


#endif