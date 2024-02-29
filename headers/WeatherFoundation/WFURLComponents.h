// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFURLCOMPONENTS_H
#define WFURLCOMPONENTS_H

@class NSURL, NSLocale, CLLocation, NSString;

#import <Foundation/Foundation.h>

#import "NSSecureCoding-Protocol.h"
#import "NSCopying-Protocol.h"

@interface WFURLComponents : NSObject <NSSecureCoding, NSCopying>



@property (readonly, copy) NSURL *URL;
@property NSUInteger cityIndex; // ivar: _cityIndex
@property NSUInteger destination; // ivar: _destination
@property BOOL isLocalWeatherCity; // ivar: _isLocalWeatherCity
@property (retain) NSLocale *locale; // ivar: _locale
@property (copy) CLLocation *location; // ivar: _location
@property (copy) NSString *locationName; // ivar: _locationName
@property (retain) NSString *platform; // ivar: _platform
@property BOOL showHourlyWeatherOnly; // ivar: _showHourlyWeatherOnly


+(BOOL)supportsSecureCoding;
+(id)componentsForLocation:(id)arg0 ;
+(id)componentsForURL:(id)arg0 ;
+(void)locationForURL:(id)arg0 completion:(id)arg1 ;
+(void)locationForURLComponents:(id)arg0 completion:(id)arg1 ;
-(BOOL)isEqual:(id)arg0 ;
-(BOOL)isEqualToComponents:(id)arg0 ;
-(NSUInteger)hash;
-(id)copyWithZone:(struct _NSZone *)arg0 ;
-(id)init;
-(id)initWithCoder:(id)arg0 ;
-(id)initWithLocation:(id)arg0 ;
-(void)encodeWithCoder:(id)arg0 ;


@end


#endif