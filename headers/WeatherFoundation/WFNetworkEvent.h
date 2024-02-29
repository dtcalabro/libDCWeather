// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFNETWORKEVENT_H
#define WFNETWORKEVENT_H

@class NSDate;

#import <Foundation/Foundation.h>


@interface WFNetworkEvent : NSObject

@property (readonly, nonatomic) CGFloat DNSDuration; // ivar: _DNSDuration
@property (readonly, nonatomic) NSUInteger HTTPStatusCode; // ivar: _HTTPStatusCode
@property (readonly, nonatomic) CGFloat connectDuration; // ivar: _connectDuration
@property (readonly, nonatomic) NSInteger errorCode; // ivar: _errorCode
@property (readonly, nonatomic) NSInteger eventType; // ivar: _eventType
@property (readonly, nonatomic) CGFloat requestDuration; // ivar: _requestDuration
@property (readonly, nonatomic) CGFloat responseDuration; // ivar: _responseDuration
@property (readonly, nonatomic) NSUInteger responseSize; // ivar: _responseSize
@property (readonly, nonatomic) NSDate *startDate; // ivar: _startDate


-(id)initWithEventType:(NSInteger)arg0 metrics:(id)arg1 ;
-(id)initWithEventType:(NSInteger)arg0 startDate:(id)arg1 DNSDuration:(CGFloat)arg2 connectDuration:(CGFloat)arg3 requestDuration:(CGFloat)arg4 responseDuration:(CGFloat)arg5 responseSize:(NSUInteger)arg6 HTTPStatusCode:(NSUInteger)arg7 errorCode:(NSInteger)arg8 ;
-(id)initWithEventType:(NSInteger)arg0 startDate:(id)arg1 error:(id)arg2 ;


@end


#endif