// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFTASK_H
#define WFTASK_H

@class NSProgress;

#import <Foundation/Foundation.h>

#import "WFTaskIdentifier.h"

@interface WFTask : NSObject

@property (readonly, nonatomic) WFTaskIdentifier *identifier; // ivar: _identifier
@property (readonly, nonatomic) BOOL isCancelled;
@property (retain, nonatomic) NSProgress *progress; // ivar: _progress
@property (readonly, nonatomic) BOOL requiresResponse; // ivar: _requiresResponse


+(id)sharedServiceConnection;
-(id)init;
-(id)initWithResponseRequired:(BOOL)arg0 ;
-(void)cancel;
-(void)cleanup;
-(void)executeSynchronously;
-(void)handleCancellation;
-(void)handleError:(id)arg0 forResponseIdentifier:(id)arg1 ;
-(void)handleResponse:(id)arg0 ;
-(void)start;
-(void)startWithService:(id)arg0 ;


@end


#endif