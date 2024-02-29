// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WEATHERPRESSUREFORMATTER_H
#define WEATHERPRESSUREFORMATTER_H

@class NSFormatter, NSLocale;



@interface WeatherPressureFormatter : NSFormatter

@property (retain, nonatomic) NSLocale *locale; // ivar: _locale


+(id)convenienceFormatter;
-(void*)createNumberFormatter;
-(BOOL)getObjectValue:(id*)arg0 forString:(id)arg1 errorDescription:(id*)arg2 ;
-(float)convertInchesHGPressure:(float)arg0 toUnit:(int)arg1 ;
-(float)convertMBarPressure:(float)arg0 toUnit:(int)arg1 ;
-(id)fallbackStringForPressure:(float)arg0 ;
-(id)formatStringForPressure:(float)arg0 inUnit:(int)arg1 ;
-(id)init;
-(id)stringForObjectValue:(id)arg0 ;
-(id)stringFromInchesHG:(float)arg0 ;
-(id)stringFromMillibars:(float)arg0 ;
-(id)stringFromPressure:(float)arg0 isDataMetric:(BOOL)arg1 ;
-(int)pressureUnit;
-(void)dealloc;
-(void)resetFormatter;


@end


#endif