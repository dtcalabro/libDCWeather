// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0

#ifndef CITY_H
#define CITY_H

@class NSString, WFGeocodeRequest, NSNumber, WFAQIScaleCategory, NSURL, WFAQIScale, NSTimer, NSHashTable, NSArray, WFTemperature, NSError, CLLocation, WFNextHourPrecipitation, NSTimeZone, NSDate, NSDictionary, WFLocation;

#import <Foundation/Foundation.h>

#import "WeatherAQIAttribution.h"
#import "WAIdentifiable-Protocol.h"

@interface City : NSObject <WAIdentifiable>

@property (copy, nonatomic) NSString *ISO3166CountryAbbreviation; // ivar: _ISO3166CountryAbbreviation
@property (retain, nonatomic) WFGeocodeRequest *activeGeocodeRequest; // ivar: _activeGeocodeRequest
@property (retain, nonatomic) WeatherAQIAttribution *airQualityAttribution; // ivar: _airQualityAttribution
@property (retain, nonatomic) NSNumber *airQualityCategory; // ivar: _airQualityCategory
@property (retain, nonatomic) NSNumber *airQualityCategoryOverride; // ivar: _airQualityCategoryOverride
@property (retain, nonatomic) WFAQIScaleCategory *airQualityCurrentScaleCategory; // ivar: _airQualityCurrentScaleCategory
@property (readonly, nonatomic) BOOL airQualityForceHideRecommendation;
@property (retain, nonatomic) NSNumber *airQualityIdx; // ivar: _airQualityIdx
@property (retain, nonatomic) NSNumber *airQualityIdxOverride; // ivar: _airQualityIdxOverride
@property (copy, nonatomic) NSURL *airQualityLearnMoreURL; // ivar: _airQualityLearnMoreURL
@property (copy, nonatomic) NSString *airQualityRecommendation; // ivar: _airQualityRecommendation
@property (retain, nonatomic) WFAQIScale *airQualityScale; // ivar: _airQualityScale
@property (retain, nonatomic) WFAQIScaleCategory *airQualityScaleCategory; // ivar: _airQualityScaleCategory
@property (copy, nonatomic) NSString *airQualityScaleIdentifier; // ivar: _airQualityScaleIdentifier
@property (readonly, nonatomic) BOOL airQualityScaleIsAscending;
@property (readonly, nonatomic) BOOL airQualityScaleIsNumerical;
@property (nonatomic) NSUInteger airQualitySignificance; // ivar: _airQualitySignificance
@property (nonatomic) NSUInteger airQualitySignificanceOverride; // ivar: _airQualitySignificanceOverride
@property (nonatomic) BOOL airQualityTemporarilyUnavailable; // ivar: _airQualityTemporarilyUnavailable
@property (readonly, nonatomic) NSUInteger aqiDataAvailabilityStatus;
@property (nonatomic) NSUInteger aqiDataAvailabilityStatusOverride; // ivar: _aqiDataAvailabilityStatusOverride
@property (nonatomic) BOOL autoUpdate; // ivar: _autoUpdate
@property (retain, nonatomic) NSTimer *autoUpdateTimer; // ivar: _autoUpdateTimer
@property (retain, nonatomic) NSHashTable *cityUpdateObservers; // ivar: _cityUpdateObservers
@property (nonatomic) NSInteger conditionCode; // ivar: _conditionCode
@property (readonly, nonatomic) NSString *countryCode;
@property (copy, nonatomic) NSArray *dayForecasts; // ivar: _dayForecasts
@property (readonly, copy) NSString *debugDescription;
@property (copy, nonatomic) NSURL *deeplink; // ivar: _deeplink
@property (readonly, copy) NSString *description;
@property (nonatomic) float dewPoint; // ivar: _dewPoint
@property (retain, nonatomic) WFTemperature *feelsLike; // ivar: _feelsLike
@property (copy, nonatomic) NSString *fullName; // ivar: _fullName
@property (readonly) NSUInteger hash;
@property (nonatomic) float heatIndex; // ivar: _heatIndex
@property (copy, nonatomic) NSArray *hourlyForecasts; // ivar: _hourlyForecasts
@property (nonatomic) float humidity; // ivar: _humidity
@property (readonly, nonatomic) NSString *identifier;
@property (nonatomic) BOOL isDay; // ivar: _isDay
@property (nonatomic) BOOL isLocalWeatherCity; // ivar: _isLocalWeatherCity
@property (nonatomic) BOOL isRequestedByFrameworkClient; // ivar: _isRequestedByFrameworkClient
@property (nonatomic) BOOL isUpdating; // ivar: _isUpdating
@property (retain, nonatomic) NSError *lastUpdateError; // ivar: _lastUpdateError
@property (nonatomic) NSUInteger lastUpdateStatus; // ivar: _lastUpdateStatus
@property (nonatomic) CGFloat latitude;
@property (copy, nonatomic) NSURL *link; // ivar: _link
@property (copy) CLLocation *location; // ivar: _location
@property (readonly, nonatomic) NSString *locationID;
@property (nonatomic) BOOL lockedForDemoMode; // ivar: _lockedForDemoMode
@property (nonatomic) CGFloat longitude;
@property (nonatomic) NSUInteger moonPhase; // ivar: _moonPhase
@property (copy, nonatomic) NSString *name; // ivar: _name
@property (copy, nonatomic) WFNextHourPrecipitation *nextHourPrecipitation; // ivar: _nextHourPrecipitation
@property (nonatomic) NSUInteger observationTime; // ivar: _observationTime
@property (nonatomic) CGFloat precipitationPast24Hours; // ivar: _precipitationPast24Hours
@property (nonatomic) float pressure; // ivar: _pressure
@property (nonatomic) NSUInteger pressureRising; // ivar: _pressureRising
@property (copy, nonatomic) NSString *searchSubtitle; // ivar: _searchSubtitle
@property (copy, nonatomic) NSString *searchTitle; // ivar: _searchTitle
@property (copy, nonatomic) NSURL *severeWeatherEventLearnMoreURL; // ivar: _severeWeatherEventLearnMoreURL
@property (copy, nonatomic) NSArray *severeWeatherEvents; // ivar: _severeWeatherEvents
@property (copy, nonatomic) NSString *state; // ivar: _state
@property (nonatomic) NSUInteger sunriseTime; // ivar: _sunriseTime
@property (nonatomic) NSUInteger sunsetTime; // ivar: _sunsetTime
@property (readonly) Class superclass;
@property (retain, nonatomic) WFTemperature *temperature; // ivar: _temperature
@property (retain, nonatomic) NSTimeZone *timeZone; // ivar: _timeZone
@property (readonly, nonatomic) BOOL timeZoneIsFresh;
@property (retain, nonatomic) NSDate *timeZoneUpdateDate; // ivar: _timeZoneUpdateDate
@property (nonatomic, getter=isTransient) BOOL transient; // ivar: _transient
@property (nonatomic) NSInteger updateInterval; // ivar: _updateInterval
@property (retain, nonatomic) NSDate *updateTime; // ivar: _updateTime
@property (copy, nonatomic) NSString *updateTimeString; // ivar: _updateTimeString
@property (readonly) NSDictionary *urlComponents;
@property (nonatomic, setter=setUVIndex:) NSUInteger uvIndex; // ivar: _uvIndex
@property (nonatomic) float visibility; // ivar: _visibility
@property (copy, nonatomic) NSString *weatherDisplayName; // ivar: _weatherDisplayName
@property (readonly, nonatomic) NSString *weatherLocationCitationName;
@property (copy, nonatomic) NSString *weatherLocationName; // ivar: _weatherLocationName
@property (retain, nonatomic) WFLocation *wfLocation; // ivar: _wfLocation
@property (nonatomic) float windChill; // ivar: _windChill
@property (nonatomic) float windDirection; // ivar: _windDirection
@property (nonatomic) float windSpeed; // ivar: _windSpeed
@property (copy, nonatomic) NSString *woeid; // ivar: _woeid

+(id)_ISO8601Calendar;
+(id)cityContainingLocation:(id)arg0 expectedName:(id)arg1 fromCities:(id)arg2 ;
-(BOOL)_dataIsValid;
-(BOOL)_isValidLearnMoreURLForSevereEvent:(id)arg0 ;
-(BOOL)airQualityCanUseDefaultAttribution;
-(BOOL)containsLatitude:(CGFloat)arg0 longitude:(CGFloat)arg1 ;
-(BOOL)isDuplicateOfCity:(id)arg0 ;
-(BOOL)isEqual:(id)arg0 ;
-(BOOL)populateWithDataFromCity:(id)arg0 ;
-(BOOL)update;
-(CGFloat)distanceToLatitude:(CGFloat)arg0 longitude:(CGFloat)arg1 ;
-(CGFloat)distanceToLocation:(id)arg0 ;
-(NSInteger)locationOfTime:(NSInteger)arg0 ;
-(NSInteger)primaryConditionForRange:(struct _NSRange )arg0 ;
-(NSInteger)timeDigit;
-(NSUInteger)precipitationForecast;
-(NSUInteger)weatherDataAge;
-(id)cityAndState;
-(id)detailedDescription;
-(id)dictionaryRepresentation;
-(id)displayName;
-(id)getName;
-(id)init;
-(id)initWithDictionaryRepresentation:(id)arg0 ;
-(id)naturalLanguageDescription;
-(id)naturalLanguageDescriptionWithDescribedCondition:(NSInteger*)arg0 ;
-(id)windDirectionAsString:(CGFloat)arg0 ;
-(struct CLLocationCoordinate2D )coordinate;
-(void)_clearAutoUpdateTimer;
-(void)_generateLocalizableStrings;
-(void)_notifyDidStartWeatherUpdate;
-(void)addUpdateObserver:(id)arg0 ;
-(void)cityDidFinishUpdatingWithError:(id)arg0 ;
-(void)clearForecasts;
-(void)dealloc;
-(void)discardDataIfNeeded;
-(void)localWeatherDidBeginUpdate;
-(void)removeUpdateObserver:(id)arg0 ;
-(void)setCoordinate:(struct CLLocationCoordinate2D )arg0 ;
-(void)updateCityForModel:(id)arg0 ;
-(void)updateCityForSevereWeatherEvents:(id)arg0 ;
-(void)updateTimeZoneWithCompletionBlock:(id)arg0 ;

@end

#endif