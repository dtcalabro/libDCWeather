// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFWEATHERCHANNELVALIDATOR_H
#define WFWEATHERCHANNELVALIDATOR_H


#import <Foundation/Foundation.h>


@interface WFWeatherChannelValidator : NSObject



+(BOOL)isLeafNodeType:(id)arg0 ;
+(id)expectedStructure;
-(BOOL)validateDictionary:(id)arg0 expectedStructure:(id)arg1 ;
-(BOOL)validateResponseData:(id)arg0 ;


@end


#endif