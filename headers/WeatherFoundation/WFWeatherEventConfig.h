// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFWEATHEREVENTCONFIG_H
#define WFWEATHEREVENTCONFIG_H


#import <Foundation/Foundation.h>

#import "NSCopying-Protocol.h"

@interface WFWeatherEventConfig : NSObject <NSCopying>



@property (nonatomic) BOOL enabled; // ivar: _enabled


-(id)copyWithZone:(struct _NSZone *)arg0 ;
-(id)initWithDictionary:(id)arg0 defaulEnabled:(BOOL)arg1 ;


@end


#endif