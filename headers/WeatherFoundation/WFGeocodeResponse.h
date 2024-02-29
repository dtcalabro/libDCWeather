// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFGEOCODERESPONSE_H
#define WFGEOCODERESPONSE_H



#import "WFResponse.h"
#import "WFLocation.h"
#import "NSSecureCoding-Protocol.h"

@interface WFGeocodeResponse : WFResponse <NSSecureCoding>



@property (readonly) WFLocation *location; // ivar: _location


+(BOOL)supportsSecureCoding;
-(id)description;
-(id)initWithCoder:(id)arg0 ;
-(id)initWithIdentifier:(id)arg0 location:(id)arg1 ;
-(void)encodeWithCoder:(id)arg0 ;


@end


#endif