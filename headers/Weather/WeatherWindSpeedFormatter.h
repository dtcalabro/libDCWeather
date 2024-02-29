// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WEATHERWINDSPEEDFORMATTER_H
#define WEATHERWINDSPEEDFORMATTER_H

@class NSFormatter, NSDictionary, NSLocale;



@interface WeatherWindSpeedFormatter : NSFormatter

@property (retain) NSDictionary *directionSubstringAttributes; // ivar: _directionSubstringAttributes
@property (retain) NSLocale *locale; // ivar: _locale


+(id)convenienceFormatter;
-(BOOL)getObjectValue:(id*)arg0 forString:(id)arg1 errorDescription:(id*)arg2 ;
-(CGFloat)speedByConvertingToUserUnit:(CGFloat)arg0 ;
-(id)attributedFormattedStringForSpeed:(float)arg0 direction:(float)arg1 ;
-(id)fallbackStringForWindSpeed:(float)arg0 ;
-(id)fallbackUnitString;
-(id)formattedStringForSpeed:(float)arg0 direction:(float)arg1 ;
-(id)formattedStringForSpeed:(float)arg0 direction:(float)arg1 shortDescription:(BOOL)arg2 ;
-(id)init;
-(id)speedStringByConvertingToUserUnits:(float)arg0 ;
-(id)stringForObjectValue:(id)arg0 ;
-(id)stringForWindDirection:(float)arg0 shortDescription:(BOOL)arg1 ;
-(id)stringForWindSpeed:(float)arg0 ;
-(id)templateStringForSpeed:(float)arg0 direction:(float)arg1 ;
-(int)windSpeedUnit;


@end


#endif