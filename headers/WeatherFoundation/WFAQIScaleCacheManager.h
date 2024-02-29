// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFAQISCALECACHEMANAGER_H
#define WFAQISCALECACHEMANAGER_H

@class NSMutableDictionary;

#import <Foundation/Foundation.h>

#import "WFAQIScale.h"

@interface WFAQIScaleCacheManager : NSObject

@property (readonly, nonatomic) NSMutableDictionary *aqiScaleCache; // ivar: _aqiScaleCache
@property (readonly, nonatomic) os_unfair_lock_s dataSynchronizationLock; // ivar: _dataSynchronizationLock
@property (readonly, nonatomic) WFAQIScale *defaultScale; // ivar: _defaultScale


+(id)sharedManager;
-(id)_persistedInfoFromDisk;
-(id)_persistedInfoURL;
-(id)cachedScaleFromIdentifier:(id)arg0 ;
-(id)init;
-(void)_persistInfoToDisk;
-(void)clearCache;
-(void)updateCacheWithScale:(id)arg0 identifier:(id)arg1 ;


@end


#endif