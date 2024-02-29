// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WEATHERAQIATTRIBUTION_H
#define WEATHERAQIATTRIBUTION_H

@class UIImage, WFGeocodeRequest, NSString, NSDate, CLLocation;
@protocol OS_dispatch_queue;

#import <Foundation/Foundation.h>


@interface WeatherAQIAttribution : NSObject

@property (readonly, nonatomic) UIImage *cachedLogoImage; // ivar: _cachedLogoImage
@property (nonatomic) NSInteger dataOrigination; // ivar: _dataOrigination
@property (retain, nonatomic) WFGeocodeRequest *geocodeRequest; // ivar: _geocodeRequest
@property (readonly, nonatomic) BOOL isValid;
@property (retain, nonatomic) NSString *name; // ivar: _name
@property (retain, nonatomic) NSObject<OS_dispatch_queue> *reverseGeocodingQueue; // ivar: _reverseGeocodingQueue
@property (readonly, nonatomic) NSDate *stationLastReadDate; // ivar: _stationLastReadDate
@property (readonly, nonatomic) CLLocation *stationLocation; // ivar: _stationLocation
@property (retain, nonatomic) NSString *stationLocationName; // ivar: _stationLocationName


-(id)initWithFoundationAttribution:(id)arg0 ;
-(void)reverseGeocodeStationLocation:(id)arg0 ;


@end


#endif