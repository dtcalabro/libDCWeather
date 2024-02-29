// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WEATHERCLOUDPERSISTENCE_H
#define WEATHERCLOUDPERSISTENCE_H

@class NSUbiquitousKeyValueStore, NSString;

#import <Foundation/Foundation.h>

#import "WeatherCloudMigrator.h"
#import "WeatherPreferencesPersistence-Protocol.h"
#import "WeatherCloudPersistenceDelegate-Protocol.h"

@interface WeatherCloudPersistence : NSObject <WeatherPreferencesPersistence>



@property (retain, nonatomic) NSUbiquitousKeyValueStore *activeCloudStore; // ivar: _activeCloudStore
@property (readonly, copy) NSString *debugDescription;
@property (weak) NSObject<WeatherCloudPersistenceDelegate> *delegate; // ivar: _delegate
@property (readonly, copy) NSString *description;
@property (retain, nonatomic) NSUbiquitousKeyValueStore *encryptedStore; // ivar: _encryptedStore
@property (readonly) NSUInteger hash;
@property (readonly, nonatomic) WeatherCloudMigrator *migrator; // ivar: _migrator
@property (retain, nonatomic) NSUbiquitousKeyValueStore *nonEncryptedStore; // ivar: _nonEncryptedStore
@property (readonly) Class superclass;


+(BOOL)processIsWhitelistedForSync;
+(id)cloudPersistenceWithDelegate:(id)arg0 ;
-(BOOL)boolForKey:(id)arg0 ;
-(BOOL)isInitialSyncNotification:(id)arg0 ;
-(BOOL)synchronize;
-(id)arrayForKey:(id)arg0 ;
-(id)dictionaryForKey:(id)arg0 ;
-(id)init;
-(id)initWithDelegate:(id)arg0 ;
-(id)objectForKey:(id)arg0 ;
-(id)stringForKey:(id)arg0 ;
-(void)cloudCitiesChangedExternally:(id)arg0 ;
-(void)encryptedStoreChanged:(id)arg0 ;
-(void)removeObjectForKey:(id)arg0 ;
-(void)setBool:(BOOL)arg0 forKey:(id)arg1 ;
-(void)setObject:(id)arg0 forKey:(id)arg1 ;
-(void)synchronizeWithCompletionHandler:(id)arg0 ;


@end


#endif