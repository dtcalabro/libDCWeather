// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFSETTINGSMANAGER_H
#define WFSETTINGSMANAGER_H

@class NSString, NSHashTable;
@protocol OS_dispatch_queue;

#import <Foundation/Foundation.h>

#import "WFRemoteAppSettings.h"
#import "WFUserInfoManager.h"
#import "WFUserInfoManagerDelegate-Protocol.h"

@interface WFSettingsManager : NSObject <WFUserInfoManagerDelegate>



@property (readonly, nonatomic) NSString *APIVersion;
@property (readonly, copy) NSString *debugDescription;
@property (readonly, copy) NSString *description;
@property (readonly) NSUInteger hash;
@property (readonly, nonatomic) NSHashTable *observers; // ivar: _observers
@property (retain, nonatomic) NSObject<OS_dispatch_queue> *requestSerialQueue; // ivar: _requestSerialQueue
@property (retain, nonatomic) WFRemoteAppSettings *settings; // ivar: _settings
@property (nonatomic) os_unfair_lock_s settingsLock; // ivar: _settingsLock
@property (readonly) Class superclass;
@property (readonly, nonatomic) BOOL useFallback; // ivar: _useFallback
@property (retain, nonatomic) WFUserInfoManager *userInfoManager; // ivar: _userInfoManager


+(id)sharedInstance;
+(id)userIdentifier;
+(void)setUserIdentifier:(id)arg0 ;
-(BOOL)clearConfigCacheOnLaunchIfRequested;
-(BOOL)shouldReroutePermanentURLsForContainerIdentifier:(id)arg0 ;
-(NSUInteger)debugEnvironmentFromOverride:(id)arg0 ;
-(char)containerIDForContainerIdentifier:(id)arg0 ;
-(id)containerIdentifier;
-(id)debugOverrides;
-(id)init;
-(id)permanentURLForRecordID:(id)arg0 containerIdentifier:(id)arg1 ;
-(id)urlSafeBase64EncodedStringWithData:(id)arg0 options:(NSUInteger)arg1 ;
-(void)addObserver:(id)arg0 ;
-(void)completeOnQueue:(id)arg0 error:(id)arg1 completion:(id)arg2 ;
-(void)fetchAppConfigurationIfExpired;
-(void)fetchAppConfigurationWithCompletionQueue:(id)arg0 completion:(id)arg1 ;
-(void)forceFetchAppConfiguration;
-(void)notifyObserversOfAppConfigRefresh;
-(void)removeObserver:(id)arg0 ;
-(void)setupRemoteSettings;
-(void)updateAssetURLHostIfNeededWithComponents:(id)arg0 containerIdentifier:(id)arg1 ;
-(void)userInfoManager:(id)arg0 didSynchronizeUserIdentifier:(id)arg1 ;


@end


#endif