// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFNETWORKFAILTRACKER_H
#define WFNETWORKFAILTRACKER_H


#import <Foundation/Foundation.h>


@interface WFNetworkFailTracker : NSObject

@property (readonly, nonatomic) CGFloat lastFailTimeInSeconds; // ivar: _lastFailTimeInSeconds
@property (readonly, nonatomic) int numConsecutiveFails; // ivar: _numConsecutiveFails


-(BOOL)lastFailTimeExpiredForSettings:(id)arg0 ;
-(void)incrementFailCount;


@end


#endif