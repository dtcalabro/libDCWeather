// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFRESOURCEMANAGER_H
#define WFRESOURCEMANAGER_H


#import <Foundation/Foundation.h>


@interface WFResourceManager : NSObject



+(id)sharedManager;
-(id)frameworkBundle;
-(id)localizedStringForKey:(id)arg0 ;
-(id)tableName;


@end


#endif