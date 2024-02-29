// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WEATHERDEVICELOOKUP_H
#define WEATHERDEVICELOOKUP_H

@class ACAccountStore;

#import <Foundation/Foundation.h>
#import "Weather-Structs.h"

@interface WeatherDeviceLookup : NSObject

@property (readonly, nonatomic) ACAccountStore *accountStore; // ivar: _accountStore


-(id)init;
-(void)checkAllDevicesRunningMinimumiOSVersion:(struct huh)arg0 macOSVersion:(struct huh)arg1 orInactiveForTimeInterval:(CGFloat)arg2 completionHandler:(id)arg3 ;


@end


#endif