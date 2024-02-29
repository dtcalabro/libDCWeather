// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFLOCATION_H
#define WFLOCATION_H

@class NSString, NSDate, CLLocation, NSTimeZone;

#import <Foundation/Foundation.h>

#import "NSSecureCoding-Protocol.h"
#import "NSCopying-Protocol.h"

@interface WFLocation : NSObject <NSSecureCoding, NSCopying>



@property NSInteger archiveVersion; // ivar: _archiveVersion
@property (copy, nonatomic) NSString *city; // ivar: _city
@property (copy, nonatomic) NSString *country; // ivar: _country
@property (copy, nonatomic) NSString *countryAbbreviation; // ivar: _countryAbbreviation
@property (copy, nonatomic) NSString *county; // ivar: _county
@property (retain, nonatomic) NSDate *creationDate; // ivar: _creationDate
@property (copy, nonatomic) NSString *displayName; // ivar: _displayName
@property (copy, nonatomic) CLLocation *geoLocation; // ivar: _geoLocation
@property (copy, nonatomic) NSString *locationID; // ivar: _locationID
@property (readonly, nonatomic) BOOL needsGeocoding;
@property (readonly, nonatomic) BOOL shouldQueryForAirQualityData;
@property (copy, nonatomic) NSString *state; // ivar: _state
@property (copy, nonatomic) NSString *stateAbbreviation; // ivar: _stateAbbreviation
@property (retain, nonatomic) NSTimeZone *timeZone; // ivar: _timeZone
@property (copy, nonatomic) NSString *weatherDisplayName; // ivar: _weatherDisplayName
@property (copy, nonatomic) NSString *weatherLocationName; // ivar: _weatherLocationName
@property (readonly, nonatomic) NSString *wf_weatherChannelGeocodeValue;


+(BOOL)supportsSecureCoding;
+(NSInteger)currentArchiveVersion;
+(id)knownKeys;
+(id)locationsByConsolidatingDuplicates:(id)arg0 originalOrder:(id)arg1 ;
+(id)locationsByConsolidatingDuplicatesInBucket:(id)arg0 ;
+(id)locationsByFilteringDuplicates:(id)arg0 ;
-(BOOL)isDay;
-(BOOL)isDayForDate:(id)arg0 ;
-(BOOL)isEqual:(id)arg0 ;
-(NSUInteger)hash;
-(id)_sunAlmanacForDate:(id)arg0 ;
-(id)cloudDictionaryRepresentation;
-(id)copyWithZone:(struct _NSZone *)arg0 ;
-(id)description;
-(id)initWithCloudDictionaryRepresentation:(id)arg0 ;
-(id)initWithCoder:(id)arg0 ;
-(id)initWithLocalDataRepresentation:(id)arg0 ;
-(id)initWithMapItem:(id)arg0 ;
-(id)initWithMapItem:(id)arg0 isCurrentLocation:(BOOL)arg1 ;
-(id)initWithPlacemark:(id)arg0 ;
-(id)initWithSearchResponse:(id)arg0 ;
-(id)localDataRepresentation;
-(id)summary;
-(id)summaryThatIsCompact:(BOOL)arg0 ;
-(id)sunriseForDate:(id)arg0 ;
-(id)sunsetForDate:(id)arg0 ;
-(void)encodeWithCoder:(id)arg0 ;
-(void)sunrise:(id*)arg0 andSunset:(id*)arg1 forDate:(id)arg2 ;


@end


#endif