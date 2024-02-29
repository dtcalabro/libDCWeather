// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFTEMPERATUREUNITPROVIDER_H
#define WFTEMPERATUREUNITPROVIDER_H

@protocol OS_dispatch_queue;

#import <Foundation/Foundation.h>


@interface WFTemperatureUnitProvider : NSObject

@property (retain, nonatomic) NSObject<OS_dispatch_queue> *providerQueue; // ivar: _providerQueue
@property (readonly) int userTemperatureUnit;


-(id)init;
-(int)_providerQueue_changeUnit:(int)arg0 ;
-(void)_postDidChangeUnitDefaultsPreference;
-(void)fetchTemperatureUnitWithCompletionHandler:(id)arg0 ;
-(void)replaceUnit:(int)arg0 ;
-(void)replaceUnit:(int)arg0 completionHandler:(id)arg1 ;


@end


#endif