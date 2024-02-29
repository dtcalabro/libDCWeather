// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFNETWORKRETRYMANAGER_H
#define WFNETWORKRETRYMANAGER_H

@class NSArray, NSMutableDictionary, NSMutableSet;

#import <Foundation/Foundation.h>


@interface WFNetworkRetryManager : NSObject

@property (readonly, nonatomic) NSArray *apiVersions;
@property (readonly, nonatomic) NSMutableDictionary *failTrackerDict; // ivar: _failTrackerDict
@property (readonly, nonatomic) NSArray *failingAPIVersions;
@property (readonly, nonatomic) NSMutableSet *failingAPIVersionsSet; // ivar: _failingAPIVersionsSet


-(BOOL)defaultAPIVersionIsFailingForSettings:(id)arg0 failTracker:(id)arg1 ;
-(CGFloat)lastFailTimeInSecondsForAPIVersion:(id)arg0 ;
-(id)apiVersionForSettings:(id)arg0 ;
-(id)init;
-(int)consecutiveFailsForAPIVersion:(id)arg0 ;
-(void)requestFailureForAPIVersion:(id)arg0 error:(id)arg1 ;
-(void)requestSuccessForAPIVersion:(id)arg0 ;


@end


#endif