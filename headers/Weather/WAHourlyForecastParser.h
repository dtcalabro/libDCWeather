// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WAHOURLYFORECASTPARSER_H
#define WAHOURLYFORECASTPARSER_H


#import <Foundation/Foundation.h>


@interface WAHourlyForecastParser : NSObject



+(id)parseForecasts:(id)arg0 temperature:(id)arg1 currentTime:(NSUInteger)arg2 condition:(NSInteger)arg3 sunrise:(NSUInteger)arg4 sunset:(NSUInteger)arg5 ;
+(id)parseForecasts:(id)arg0 temperature:(id)arg1 hour:(NSInteger)arg2 condition:(NSInteger)arg3 sunrise:(NSUInteger)arg4 sunset:(NSUInteger)arg5 ;
+(void)addSunEventIntoForecasts:(id)arg0 eventType:(NSUInteger)arg1 forecastDetail:(id)arg2 eventTime:(NSUInteger)arg3 currentTime:(NSUInteger)arg4 ;


@end


#endif