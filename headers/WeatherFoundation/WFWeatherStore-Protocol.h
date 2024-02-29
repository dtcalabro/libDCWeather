// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0



@protocol WFWeatherStore


-(void)airQualityForLocation:(id)arg0 locale:(id)arg1 requestIdentifier:(id)arg2 options:(id)arg3 completionHandler:(id)arg4 ;
-(void)cancelTaskWithIdentifier:(id)arg0 ;
-(void)dailyForecastForLocation:(id)arg0 locale:(id)arg1 requestIdentifier:(id)arg2 completionHandler:(id)arg3 ;
-(void)forecast:(NSUInteger)arg0 forLocation:(id)arg1 locale:(id)arg2 requestIdentifier:(id)arg3 completionHandler:(id)arg4 ;
-(void)forecast:(NSUInteger)arg0 forLocation:(id)arg1 withUnits:(int)arg2 locale:(id)arg3 requestIdentifier:(id)arg4 completionHandler:(id)arg5 ;
-(void)forecast:(NSUInteger)arg0 forLocation:(id)arg1 withUnits:(int)arg2 locale:(id)arg3 requestIdentifier:(id)arg4 requestOptions:(id)arg5 completionHandler:(id)arg6 ;
-(void)forecastForLocation:(id)arg0 locale:(id)arg1 onDate:(id)arg2 requestIdentifier:(id)arg3 options:(id)arg4 completionHandler:(id)arg5 ;
-(void)hourlyForecastForLocation:(id)arg0 locale:(id)arg1 requestIdentifier:(id)arg2 completionHandler:(id)arg3 ;

@end

