// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFSEVEREWEATHEREVENT_H
#define WFSEVEREWEATHEREVENT_H

@class NSURL, NSString, NSDate;

#import <Foundation/Foundation.h>

#import "NSCopying-Protocol.h"
#import "NSSecureCoding-Protocol.h"

@interface WFSevereWeatherEvent : NSObject <NSCopying, NSSecureCoding>



@property (readonly, copy, nonatomic) NSURL *URL; // ivar: _URL
@property (readonly, copy, nonatomic) NSString *areaName; // ivar: _areaName
@property (readonly, copy, nonatomic) NSString *eventDescription; // ivar: _eventDescription
@property (readonly, copy, nonatomic) NSDate *expirationDate; // ivar: _expirationDate
@property (readonly, copy, nonatomic) NSString *identifier; // ivar: _identifier
@property (readonly, nonatomic) NSUInteger importance; // ivar: _importance
@property (readonly, copy, nonatomic) NSString *source; // ivar: _source


+(BOOL)supportsSecureCoding;
-(id)copyWithZone:(struct _NSZone *)arg0 ;
-(id)initWithCoder:(id)arg0 ;
-(id)initWithIdentifier:(id)arg0 areaName:(id)arg1 eventDescription:(id)arg2 source:(id)arg3 expirationDate:(id)arg4 URL:(id)arg5 importance:(NSUInteger)arg6 ;
-(void)encodeWithCoder:(id)arg0 ;


@end


#endif