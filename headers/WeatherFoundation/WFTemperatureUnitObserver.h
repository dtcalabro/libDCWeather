// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFTEMPERATUREUNITOBSERVER_H
#define WFTEMPERATUREUNITOBSERVER_H

@class NSMutableDictionary, NSHashTable;
@protocol OS_dispatch_queue;

#import <Foundation/Foundation.h>


@interface WFTemperatureUnitObserver : NSObject

@property (retain) NSMutableDictionary *blockObserversForUUID; // ivar: _blockObserversForUUID
@property (retain, nonatomic) NSObject<OS_dispatch_queue> *callbackQueue; // ivar: _callbackQueue
@property os_unfair_lock_s dataSynchronizationLock; // ivar: _dataSynchronizationLock
@property (retain) NSHashTable *observerObjects; // ivar: _observerObjects
@property (readonly) int temperatureUnit;
@property (retain) NSObject<OS_dispatch_queue> *temperatureUnitUpdateQueue; // ivar: _temperatureUnitUpdateQueue
@property int userTemperatureUnit; // ivar: _userTemperatureUnit


+(id)sharedObserver;
-(BOOL)removeBlockObserverWithHandle:(id)arg0 ;
-(BOOL)removeObserver:(id)arg0 ;
-(id)_init;
-(id)addBlockObserver:(id)arg0 ;
-(id)init;
-(void)_updateTemperatureUnit;
-(void)addObserver:(id)arg0 ;
-(void)dealloc;
-(void)q_notifyObserversOfUpdatedTemperatureUnit:(int)arg0 ;
-(void)q_updateTemperatureUnit;
-(void)removeAllObservers;


@end


#endif