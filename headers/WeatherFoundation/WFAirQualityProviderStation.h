// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFAIRQUALITYPROVIDERSTATION_H
#define WFAIRQUALITYPROVIDERSTATION_H

@class NSDate, CLLocation;

#import <Foundation/Foundation.h>


@interface WFAirQualityProviderStation : NSObject

@property (readonly, nonatomic) NSDate *lastReadDate; // ivar: _lastReadDate
@property (readonly, nonatomic) CLLocation *location; // ivar: _location


-(id)description;
-(id)initWithLocation:(id)arg0 lastReadDate:(id)arg1 ;


@end


#endif