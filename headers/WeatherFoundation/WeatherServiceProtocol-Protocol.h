// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0



@protocol WeatherServiceProtocol


-(void)airQualityForLocation:(id)arg0 locale:(id)arg1 options:(id)arg2 taskIdentifier:(id)arg3 ;
-(void)cancelTaskWithIdentifier:(id)arg0 ;
-(void)dailyForecastForLocation:(id)arg0 locale:(id)arg1 taskIdentifier:(id)arg2 ;
-(void)forecast:(NSUInteger)arg0 forLocation:(id)arg1 locale:(id)arg2 taskIdentifier:(id)arg3 ;
-(void)forecast:(NSUInteger)arg0 forLocation:(id)arg1 withUnits:(int)arg2 locale:(id)arg3 taskIdentifier:(id)arg4 ;
-(void)forecast:(NSUInteger)arg0 forLocation:(id)arg1 withUnits:(int)arg2 locale:(id)arg3 taskIdentifier:(id)arg4 requestOptions:(id)arg5 ;
-(void)forecastForLocation:(id)arg0 locale:(id)arg1 onDate:(id)arg2 options:(id)arg3 taskIdentifier:(id)arg4 ;
-(void)hourlyForecastForLocation:(id)arg0 locale:(id)arg1 taskIdentifier:(id)arg2 ;
-(void)invalidateCache:(id)arg0 ;
-(void)locationForCoordinate:(struct CLLocationCoordinate2D )arg0 taskIdentifier:(id)arg1 ;
-(void)locationForSearchCompletion:(id)arg0 taskIdentifier:(id)arg1 ;
-(void)locationForString:(id)arg0 taskIdentifier:(id)arg1 ;
-(void)reachabilityConfigurationForIdentifier:(id)arg0 ;
-(void)replaceTemperatureUnitWith:(int)arg0 identifier:(id)arg1 ;
-(void)temperatureUnitWithIdentifier:(id)arg0 ;

@end

