// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFSERVICEREACHABILITYOBSERVER_H
#define WFSERVICEREACHABILITYOBSERVER_H

@class NSMutableDictionary, NSHashTable, NWPathEvaluator;
@protocol OS_dispatch_queue;

#import <Foundation/Foundation.h>


@interface WFServiceReachabilityObserver : NSObject

@property (retain) NSMutableDictionary *blockObserversForUUID; // ivar: _blockObserversForUUID
@property (retain, nonatomic) NSObject<OS_dispatch_queue> *callbackQueue; // ivar: _callbackQueue
@property (readonly) BOOL isServiceAvailable;
@property (retain) NSHashTable *observerObjects; // ivar: _observerObjects
@property (retain) NSObject<OS_dispatch_queue> *observerQueue; // ivar: _observerQueue
@property (nonatomic) NSInteger reachability; // ivar: _reachability
@property (retain) NWPathEvaluator *serviceReachabilityEvaluator; // ivar: _serviceReachabilityEvaluator


+(id)sharedObserver;
-(BOOL)removeBlockObserverWithHandle:(id)arg0 ;
-(BOOL)removeObserver:(id)arg0 ;
-(id)_init;
-(id)addBlockObserver:(id)arg0 ;
-(id)init;
-(void)_deliverReachabilityUpdate:(NSInteger)arg0 ;
-(void)_setupReachability;
-(void)addObserver:(id)arg0 ;
-(void)dealloc;
-(void)observeValueForKeyPath:(id)arg0 ofObject:(id)arg1 change:(id)arg2 context:(void*)arg3 ;
-(void)removeAllObservers;


@end


#endif