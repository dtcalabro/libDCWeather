// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef CITYPERSISTENCECONVERSIONS_H
#define CITYPERSISTENCECONVERSIONS_H


#import <Foundation/Foundation.h>


@interface CityPersistenceConversions : NSObject



+(BOOL)cityDictionaryHasValidCoordinates:(id)arg0 ;
+(BOOL)isCityValid:(id)arg0 ;
+(id)cityFromALCity:(id)arg0 ;
+(id)cityFromCloudDictionary:(id)arg0 ;
+(id)cityFromDictionary:(id)arg0 ;
+(id)cloudDictionaryRepresentationOfALCity:(id)arg0 ;
+(id)cloudDictionaryRepresentationOfCity:(id)arg0 ;
+(id)dayForecastDictionariesFromCity:(id)arg0 ;
+(id)dictionaryRepresentationOfCity:(id)arg0 ;
+(id)dictionaryRepresentationOfScaleCategory:(id)arg0 ;
+(id)dictionaryRepresentationOfTemperature:(id)arg0 ;
+(id)hourlyForecastDictionariesFromCity:(id)arg0 ;
+(id)scaleCategoryFromDictionaryRepresentation:(id)arg0 ;
+(id)temperatureFromDictionaryRepresentation:(id)arg0 ;
+(id)weatherDetailsDictionaryFromCity:(id)arg0 ;
+(void)populateCity:(id)arg0 withDayForecastDictionaries:(id)arg1 ;
+(void)populateCity:(id)arg0 withHourlyForecastDictionaries:(id)arg1 ;


@end


#endif