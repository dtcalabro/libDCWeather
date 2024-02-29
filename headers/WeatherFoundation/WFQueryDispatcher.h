// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFQUERYDISPATCHER_H
#define WFQUERYDISPATCHER_H

@class NSMutableDictionary;
@protocol OS_dispatch_queue;

#import <Foundation/Foundation.h>


@interface WFQueryDispatcher : NSObject

@property (retain, nonatomic) NSMutableDictionary *queriesPendingResponse; // ivar: _queriesPendingResponse
@property (retain, nonatomic) NSObject<OS_dispatch_queue> *queue; // ivar: _queue


-(id)init;
-(void)cancelTaskWithIdentifier:(id)arg0 ;
-(void)dispatchQuery:(id)arg0 ;
-(void)fetchFavoriteLocationsWithTaskIdentifier:(id)arg0 results:(id)arg1 ;
-(void)invalidateCacheWithIdentifier:(id)arg0 ;
-(void)locationForCoordinate:(struct CLLocationCoordinate2D )arg0 taskIdentifier:(id)arg1 results:(id)arg2 ;
-(void)locationForSearchCompletion:(id)arg0 taskIdentifier:(id)arg1 results:(id)arg2 ;
-(void)locationForString:(id)arg0 taskIdentifier:(id)arg1 results:(id)arg2 ;
-(void)removePendingQueryWithIdentifier:(id)arg0 ;


@end


#endif