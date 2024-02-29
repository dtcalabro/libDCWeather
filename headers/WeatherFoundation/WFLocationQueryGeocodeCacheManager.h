// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFLOCATIONQUERYGEOCODECACHEMANAGER_H
#define WFLOCATIONQUERYGEOCODECACHEMANAGER_H

@class NSMutableDictionary;

#import <Foundation/Foundation.h>


@interface WFLocationQueryGeocodeCacheManager : NSObject

@property (readonly, nonatomic) os_unfair_lock_s dataSynchronizationLock; // ivar: _dataSynchronizationLock
@property (readonly, nonatomic) CGFloat expirationTime; // ivar: _expirationTime
@property (readonly, nonatomic) NSMutableDictionary *geocodeCache; // ivar: _geocodeCache


+(id)sharedManager;
-(id)_persistedInfoFromDisk;
-(id)_persistedInfoURL;
-(id)cachedLocationForKey:(id)arg0 ;
-(id)init;
-(void)_discardExpiredLocations;
-(void)_persistInfoToDisk;
-(void)updateCacheForKey:(id)arg0 withLocation:(id)arg1 ;


@end


#endif