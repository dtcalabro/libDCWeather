// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFNETWORKBEHAVIORMONITOR_H
#define WFNETWORKBEHAVIORMONITOR_H

@class NSHashTable;

#import <Foundation/Foundation.h>


@interface WFNetworkBehaviorMonitor : NSObject

@property (readonly, nonatomic) NSHashTable *observers; // ivar: _observers


+(id)sharedInstance;
-(id)init;
-(void)addObserver:(id)arg0 ;
-(void)logNetworkEvent:(id)arg0 ;
-(void)removeObserver:(id)arg0 ;


@end


#endif