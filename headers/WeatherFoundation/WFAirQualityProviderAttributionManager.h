// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFAIRQUALITYPROVIDERATTRIBUTIONMANAGER_H
#define WFAIRQUALITYPROVIDERATTRIBUTIONMANAGER_H

@class NSMutableDictionary;

#import <Foundation/Foundation.h>

#import "WFAirQualityProviderAttribution.h"

@interface WFAirQualityProviderAttributionManager : NSObject

@property (retain, nonatomic) NSMutableDictionary *attributionCache; // ivar: _attributionCache
@property (nonatomic) os_unfair_lock_s dataSynchronizationLock; // ivar: _dataSynchronizationLock
@property (readonly, nonatomic) WFAirQualityProviderAttribution *defaultProviderAttribution;


+(id)sharedManager;
-(id)cachedAttributionForProvider:(id)arg0 ;
-(id)init;
-(id)p_archivedDataForProviderAttribution:(id)arg0 ;
-(void)loadAttributionForProvider:(id)arg0 completion:(id)arg1 ;
-(void)p_updateCacheWithProviderAttribution:(id)arg0 ;
-(void)registerProviderAttribution:(id)arg0 ;


@end


#endif