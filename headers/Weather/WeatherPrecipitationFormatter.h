// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WEATHERPRECIPITATIONFORMATTER_H
#define WEATHERPRECIPITATIONFORMATTER_H

@class NSLengthFormatter, NSLocale;



@interface WeatherPrecipitationFormatter : NSLengthFormatter

@property (retain, nonatomic) NSLocale *locale; // ivar: _locale


+(id)convenienceFormatter;
-(CGFloat)convertDistanceInImperial:(CGFloat)arg0 to:(NSInteger)arg1 ;
-(CGFloat)convertDistanceInMetric:(CGFloat)arg0 to:(NSInteger)arg1 ;
-(NSInteger)precipitationUnit;
-(id)init;
-(id)stringForObjectValue:(id)arg0 ;
-(id)stringFromCentimeters:(CGFloat)arg0 ;
-(id)stringFromDistance:(CGFloat)arg0 isDataMetric:(BOOL)arg1 ;
-(id)stringFromInches:(CGFloat)arg0 ;


@end


#endif