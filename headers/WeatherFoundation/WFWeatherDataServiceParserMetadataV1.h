// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFWEATHERDATASERVICEPARSERMETADATAV1_H
#define WFWEATHERDATASERVICEPARSERMETADATAV1_H

@class NSDate, NSString, NSURL;

#import <Foundation/Foundation.h>

#import "WFLocation.h"

@interface WFWeatherDataServiceParserMetadataV1 : NSObject

@property (nonatomic) NSInteger dataOrigination; // ivar: _dataOrigination
@property (copy, nonatomic) NSDate *expireDate; // ivar: _expireDate
@property (copy, nonatomic) NSString *language; // ivar: _language
@property (retain, nonatomic) WFLocation *location; // ivar: _location
@property (copy, nonatomic) NSURL *providerLogoURL; // ivar: _providerLogoURL
@property (copy, nonatomic) NSString *providerName; // ivar: _providerName
@property (copy, nonatomic) NSDate *readDate; // ivar: _readDate
@property (nonatomic) BOOL temporarilyUnavailable; // ivar: _temporarilyUnavailable
@property (nonatomic) NSUInteger version; // ivar: _version




@end


#endif