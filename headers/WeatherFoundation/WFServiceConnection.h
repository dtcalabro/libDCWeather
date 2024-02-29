// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFSERVICECONNECTION_H
#define WFSERVICECONNECTION_H

@class NSString, NSMutableDictionary, NSXPCConnection;
@protocol OS_dispatch_queue;

#import <Foundation/Foundation.h>

#import "WeatherServiceClientProtocol-Protocol.h"
#import "WeatherServiceProtocol-Protocol.h"

@interface WFServiceConnection : NSObject <WeatherServiceClientProtocol>



@property (retain, nonatomic) NSObject<OS_dispatch_queue> *callbackQueue; // ivar: _callbackQueue
@property (readonly, copy) NSString *debugDescription;
@property (readonly, copy) NSString *description;
@property (readonly) NSMutableDictionary *dispatchGroupForTaskIdentifier; // ivar: _dispatchGroupForTaskIdentifier
@property (readonly) NSMutableDictionary *executionStartTimeForTaskIdentifier; // ivar: _executionStartTimeForTaskIdentifier
@property (readonly) NSUInteger hash;
@property (retain, nonatomic) NSObject<OS_dispatch_queue> *internalStateQueue; // ivar: _internalStateQueue
@property (retain, nonatomic) NSObject<OS_dispatch_queue> *queue; // ivar: _queue
@property (retain, nonatomic) NSObject<WeatherServiceProtocol> *serviceProxy; // ivar: _serviceProxy
@property (readonly) Class superclass;
@property (readonly) NSMutableDictionary *tasksPendingResponseForTaskIdentifier; // ivar: _tasksPendingResponseForTaskIdentifier
@property (retain, nonatomic) NSXPCConnection *xpcConnection; // ivar: _xpcConnection


+(id)allAllowedClasses;
+(id)weatherServiceClientInterface;
+(id)weatherServiceInterface;
-(id)init;
-(void)_callbackAllPendingTasksOnInvalidate:(id)arg0 ;
-(void)_cleanup;
-(void)_handleRemoteObjectProxyError:(id)arg0 ;
-(void)_onQueueInvalidateConnection:(id)arg0 ;
-(void)_onQueueOpenConnection;
-(void)accessServiceWithBlock:(id)arg0 ;
-(void)cancelRequestWithIdentifier:(id)arg0 ;
-(void)dealloc;
-(void)enqueueRequest:(id)arg0 ;
-(void)enqueueRequest:(id)arg0 waitUntilDone:(BOOL)arg1 ;
-(void)invalidate;
-(void)invalidateCache;
-(void)serviceDidReceiveResponse:(id)arg0 ;
-(void)taskIdentifier:(id)arg0 ;


@end


#endif