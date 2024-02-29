// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WEATHERUSERDEFAULTS_H
#define WEATHERUSERDEFAULTS_H

@class NSString, NSUserDefaults;

#import <Foundation/Foundation.h>

#import "WeatherPreferencesPersistence-Protocol.h"

@interface WeatherUserDefaults : NSObject <WeatherPreferencesPersistence>



@property (readonly, copy) NSString *debugDescription;
@property (readonly, copy) NSString *description;
@property (readonly) NSUInteger hash;
@property (readonly) Class superclass;
@property (retain) NSUserDefaults *userDefaults; // ivar: _userDefaults


-(BOOL)boolForKey:(id)arg0 ;
-(BOOL)synchronize;
-(id)arrayForKey:(id)arg0 ;
-(id)dictionaryForKey:(id)arg0 ;
-(id)initWithUserDefaults:(id)arg0 ;
-(id)objectForKey:(id)arg0 ;
-(id)stringForKey:(id)arg0 ;
-(void)removeObjectForKey:(id)arg0 ;
-(void)setBool:(BOOL)arg0 forKey:(id)arg1 ;
-(void)setObject:(id)arg0 forKey:(id)arg1 ;
-(void)synchronizeWithCompletionHandler:(id)arg0 ;


@end


#endif