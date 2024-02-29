// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFATTRIBUTION_H
#define WFATTRIBUTION_H

@class NSString, NSURL;

#import <Foundation/Foundation.h>


@interface WFAttribution : NSObject

@property (readonly) NSString *localizedSourceAttribution;
@property (readonly) NSURL *sourceAttributionURL;
@property (readonly) NSString *sourceName;


+(id)platformSpecializedWeatherSourceAttributionURLForTrafficParameter:(id)arg0 ;
+(id)sharedAttribution;
+(id)weatherSourceAttributionURLForTrafficParameter:(id)arg0 ;
-(id)sourceAttributionImageForStyle:(NSUInteger)arg0 ;


@end


#endif