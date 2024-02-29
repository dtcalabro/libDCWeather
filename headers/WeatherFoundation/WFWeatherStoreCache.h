// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFWEATHERSTORECACHE_H
#define WFWEATHERSTORECACHE_H

@class NSURL, NSMutableDictionary, NSTimer, NSMutableSet;
@protocol OS_dispatch_queue;

#import <Foundation/Foundation.h>


@interface WFWeatherStoreCache : NSObject

@property (copy, nonatomic) NSURL *URL; // ivar: _URL
@property (retain) NSObject<OS_dispatch_queue> *cacheConcurrentQueue; // ivar: _cacheConcurrentQueue
@property (retain) NSMutableDictionary *cacheForDomain; // ivar: _cacheForDomain
@property (retain, nonatomic) NSTimer *cacheStoreTimer; // ivar: _cacheStoreTimer
@property (retain) NSMutableSet *dirtyCacheDomains; // ivar: _dirtyCacheDomains


+(BOOL)removeObjectsFromCache:(id)arg0 passingTest:(id)arg1 ;
+(id)createCacheIfNecessary:(id)arg0 error:(id*)arg1 ;
+(id)wf_mainDomains;
-(BOOL)_concurrentQueue_barrier_loadDomain:(id)arg0 ;
-(BOOL)_loadDomain:(id)arg0 ;
-(id)_loadedCacheDomains;
-(id)cachedObjectWithinDomain:(id)arg0 forKey:(id)arg1 ;
-(id)cachedObjectWithinDomain:(id)arg0 forKey:(id)arg1 staleness:(NSUInteger)arg2 ;
-(id)init;
-(id)initWithURL:(id)arg0 ;
-(void)_concurrentQueue_barrier_deleteOldDataFromCache;
-(void)_concurrentQueue_barrier_deleteOldDataFromCache:(id)arg0 allowedStaleness:(NSUInteger)arg1 ;
-(void)_concurrentQueue_barrier_removeObjectWithinDomain:(id)arg0 forKey:(id)arg1 ;
-(void)_concurrentQueue_barrier_shrinkDomain:(id)arg0 ;
-(void)_concurrentQueue_barrier_writeCacheDictionaryToFile;
-(void)_ensureDomainIsLoaded:(id)arg0 ;
-(void)_markDomainDirty:(id)arg0 ;
-(void)_shrinkDomain:(id)arg0 ;
-(void)_startCacheStoreTimer;
-(void)_stopCacheStoreTimer;
-(void)cache:(id)arg0 withinDomain:(id)arg1 date:(id)arg2 forKey:(id)arg3 expiration:(id)arg4 synchronous:(BOOL)arg5 ;
-(void)cache:(id)arg0 withinDomain:(id)arg1 forKey:(id)arg2 ;
-(void)cache:(id)arg0 withinDomain:(id)arg1 forKey:(id)arg2 expiration:(id)arg3 ;
-(void)dealloc;
-(void)deleteOldDataFromCache:(id)arg0 allowedStaleness:(NSUInteger)arg1 ;
-(void)executeTransaction:(id)arg0 ;
-(void)removeAllObjects;
-(void)removeObjectWithinDomain:(id)arg0 forKey:(id)arg1 ;
-(void)writeCacheDictionaryToFile;


@end


#endif