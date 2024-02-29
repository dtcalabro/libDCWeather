// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFAIRQUALITYPROVIDERATTRIBUTION_H
#define WFAIRQUALITYPROVIDERATTRIBUTION_H

@class UIImage, NSURL, NSString, NSMutableArray;
@protocol OS_dispatch_queue;

#import <Foundation/Foundation.h>

#import "WFAirQualityProviderStation.h"
#import "NSSecureCoding-Protocol.h"
#import "NSCopying-Protocol.h"

@interface WFAirQualityProviderAttribution : NSObject <NSSecureCoding, NSCopying>



@property (copy, nonatomic) UIImage *cachedLogoImage; // ivar: _cachedLogoImage
@property (nonatomic) NSInteger dataOrigination; // ivar: _dataOrigination
@property (nonatomic) os_unfair_lock_s dataSynchronizationLock; // ivar: _dataSynchronizationLock
@property (retain, nonatomic) NSObject<OS_dispatch_queue> *logoImageLoadingQueue; // ivar: _logoImageLoadingQueue
@property (nonatomic) BOOL logoRequestInFlight; // ivar: _logoRequestInFlight
@property (copy, nonatomic) NSURL *logoURL; // ivar: _logoURL
@property (copy, nonatomic) NSString *name; // ivar: _name
@property (retain, nonatomic) NSMutableArray *outstandingRequestsCompletionBlocks; // ivar: _outstandingRequestsCompletionBlocks
@property (retain, nonatomic) WFAirQualityProviderStation *station; // ivar: _station


+(BOOL)supportsSecureCoding;
+(id)defaultProviderAttribution;
-(BOOL)p_checkRequestInFlight;
-(id)copyWithZone:(struct _NSZone *)arg0 ;
-(id)description;
-(id)initWithCoder:(id)arg0 ;
-(id)initWithName:(id)arg0 logoImage:(id)arg1 dataOrigination:(NSInteger)arg2 station:(id)arg3 ;
-(id)initWithName:(id)arg0 logoURL:(id)arg1 dataOrigination:(NSInteger)arg2 ;
-(id)initWithName:(id)arg0 logoURL:(id)arg1 dataOrigination:(NSInteger)arg2 station:(id)arg3 ;
-(id)p_imageWithData:(id)arg0 ;
-(void)_initInternal;
-(void)encodeWithCoder:(id)arg0 ;
-(void)loadLogoImageWithCompletion:(id)arg0 ;
-(void)p_clearRequestInFlight;
-(void)p_invokeAndClearCompletionBlocksWithImage:(id)arg0 error:(id)arg1 ;
-(void)p_loadRemoteLogoImageForProvider:(id)arg0 completion:(id)arg1 ;
-(void)p_queueCompletionBlock:(id)arg0 ;
-(void)p_setRequestInFlight;


@end


#endif