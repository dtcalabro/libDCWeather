// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFTEMPERATUREFORMATTER_H
#define WFTEMPERATUREFORMATTER_H

@class NSFormatter, NSString, NSLocale;



@interface WFTemperatureFormatter : NSFormatter

@property (copy, nonatomic) NSString *fallbackTemperatureString; // ivar: _fallbackTemperatureString
@property (nonatomic) BOOL includeDegreeSymbol; // ivar: _includeDegreeSymbol
@property (nonatomic) int inputUnit; // ivar: _inputUnit
@property (retain, nonatomic) NSLocale *locale; // ivar: _locale
@property (nonatomic) NSUInteger maximumFractionDigits; // ivar: _maximumFractionDigits
//@property (nonatomic) UAMeasureFormat *measureFormatter; // ivar: _measureFormatter
@property (nonatomic) id measureFormatter; // ivar: _measureFormatter
@property (nonatomic) int outputUnit; // ivar: _outputUnit
@property (nonatomic) NSUInteger roundingMode; // ivar: _roundingMode
@property (nonatomic) int symbolType; // ivar: _symbolType


+(id)temperatureFormatterWithInputUnit:(int)arg0 outputUnit:(int)arg1 ;
-(BOOL)getObjectValue:(id*)arg0 forString:(id)arg1 errorDescription:(id*)arg2 ;
-(id)_formatTemperatureValue:(id)arg0 toUnit:(int)arg1 ;
-(id)copyWithZone:(struct _NSZone *)arg0 ;
-(id)formattedStringFromTemperature:(id)arg0 ;
-(id)formattedTemperatureFromString:(id)arg0 ;
-(id)init;
-(id)stringForObjectValue:(id)arg0 ;
-(void)_localeDidChangeNotification:(id)arg0 ;
-(void)dealloc;


@end


#endif