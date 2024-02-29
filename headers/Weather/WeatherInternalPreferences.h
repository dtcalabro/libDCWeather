// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WEATHERINTERNALPREFERENCES_H
#define WEATHERINTERNALPREFERENCES_H

@class NSUserDefaults;


#import "WeatherPreferencesPersistence-Protocol.h"

@interface WeatherInternalPreferences : NSUserDefaults

@property (readonly, nonatomic) NSUInteger deviceInactivityThreshold;
@property (readonly, nonatomic) BOOL isInternalInstall;
@property (readonly, nonatomic) BOOL isV3Enabled;
@property (retain) NSObject<WeatherPreferencesPersistence> *persistence; // ivar: _persistence
@property (readonly, nonatomic) BOOL shouldShowUpdateTimestamp;


+(id)sharedInternalPreferences;


@end


#endif