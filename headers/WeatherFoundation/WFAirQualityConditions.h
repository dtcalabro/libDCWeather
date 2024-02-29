// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFAIRQUALITYCONDITIONS_H
#define WFAIRQUALITYCONDITIONS_H

@class NSString, NSDate, NSURL, NSLocale, NSArray;

#import <Foundation/Foundation.h>

#import "WFAQIScaleCategory.h"
#import "WFLocation.h"
#import "WFAirPollutant.h"
#import "WFAirQualityProviderAttribution.h"
#import "WFAQIScale.h"
#import "NSSecureCoding-Protocol.h"
#import "NSCopying-Protocol.h"

@interface WFAirQualityConditions : NSObject <NSSecureCoding, NSCopying>



@property (nonatomic) NSUInteger airQualityIndex; // ivar: _airQualityIndex
@property (copy, nonatomic) NSString *airQualityScale; // ivar: _airQualityScale
@property (nonatomic) NSUInteger category; // ivar: _category
@property (nonatomic) NSUInteger currentCategoryIndex; // ivar: _currentCategoryIndex
@property (retain, nonatomic) WFAQIScaleCategory *currentScaleCategory; // ivar: _currentScaleCategory
@property (copy, nonatomic) NSDate *date; // ivar: _date
@property (copy, nonatomic) NSDate *expirationDate; // ivar: _expirationDate
@property (readonly, nonatomic, getter=isExpired) BOOL expired;
@property (copy, nonatomic) NSURL *learnMoreURL; // ivar: _learnMoreURL
@property (copy, nonatomic) NSLocale *locale; // ivar: _locale
@property (copy, nonatomic) NSString *localizedAirQualityCategory; // ivar: _localizedAirQualityCategory
@property (nonatomic) NSUInteger localizedAirQualityIndex; // ivar: _localizedAirQualityIndex
@property (retain, nonatomic) WFAQIScaleCategory *localizedAirQualityScaleCategory; // ivar: _localizedAirQualityScaleCategory
@property (copy, nonatomic) NSString *localizedDisclaimer; // ivar: _localizedDisclaimer
@property (copy, nonatomic) NSString *localizedRecommendation; // ivar: _localizedRecommendation
@property (retain, nonatomic) WFLocation *location; // ivar: _location
@property (retain, nonatomic) NSArray *pollutants; // ivar: _pollutants
@property (retain, nonatomic) WFAirPollutant *primaryPollutant; // ivar: _primaryPollutant
@property (copy, nonatomic) NSString *provider; // ivar: _provider
@property (retain, nonatomic) WFAirQualityProviderAttribution *providerAttribution; // ivar: _providerAttribution
@property (retain, nonatomic) WFAQIScale *scale; // ivar: _scale
@property (copy, nonatomic) NSString *scaleIdentifier; // ivar: _scaleIdentifier
@property (nonatomic) NSUInteger significance; // ivar: _significance
@property (nonatomic) BOOL temporarilyUnavailable; // ivar: _temporarilyUnavailable


+(BOOL)supportsSecureCoding;
-(id)copyWithZone:(struct _NSZone *)arg0 ;
-(id)debugDescription;
-(id)description;
-(id)initWithCoder:(id)arg0 ;
-(void)encodeWithCoder:(id)arg0 ;


@end


#endif