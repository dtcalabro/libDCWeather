// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFREACHABILITYCONFIGURATIONRESPONSE_H
#define WFREACHABILITYCONFIGURATIONRESPONSE_H

@class NWPathEvaluator, NSURL;


#import "WFResponse.h"
#import "NSSecureCoding-Protocol.h"

@interface WFReachabilityConfigurationResponse : WFResponse <NSSecureCoding>



@property (readonly, nonatomic) NWPathEvaluator *pathEvaluator;
@property (copy, nonatomic) NSURL *reachabilityHostURL; // ivar: _reachabilityHostURL


+(BOOL)supportsSecureCoding;
-(id)initWithCoder:(id)arg0 ;
-(void)encodeWithCoder:(id)arg0 ;


@end


#endif