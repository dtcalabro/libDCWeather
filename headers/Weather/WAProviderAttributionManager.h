// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WAPROVIDERATTRIBUTIONMANAGER_H
#define WAPROVIDERATTRIBUTIONMANAGER_H

@class NSString, NSUserDefaults;

#import <Foundation/Foundation.h>


@interface WAProviderAttributionManager : NSObject

@property (readonly, nonatomic) NSString *providerName;
@property (readonly, nonatomic) NSUserDefaults *weatherUserDefaults; // ivar: _weatherUserDefaults


+(id)sharedManager;
-(id)init;


@end


#endif