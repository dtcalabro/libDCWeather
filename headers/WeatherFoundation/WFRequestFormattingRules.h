// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFREQUESTFORMATTINGRULES_H
#define WFREQUESTFORMATTINGRULES_H


#import <Foundation/Foundation.h>

#import "WFSettings-Protocol.h"

@interface WFRequestFormattingRules : NSObject

@property (readonly, nonatomic) NSObject<WFSettings> *settings; // ivar: _settings


+(BOOL)aqiEnabledByRules:(id)arg0 forLocation:(id)arg1 ;
-(BOOL)aqiEnabledForCountryCode:(id)arg0 ;
-(NSInteger)locationNumDecimalsOfPrecision;
-(id)initWithSettings:(id)arg0 ;


@end


#endif