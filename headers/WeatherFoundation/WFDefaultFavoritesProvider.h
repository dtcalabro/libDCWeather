// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFDEFAULTFAVORITESPROVIDER_H
#define WFDEFAULTFAVORITESPROVIDER_H

@class NSString;
@protocol WFFavoriteLocationProviderDelegate;

#import <Foundation/Foundation.h>

#import "WFFavoriteLocationProvider-Protocol.h"

@interface WFDefaultFavoritesProvider : NSObject <WFFavoriteLocationProvider>



@property (readonly, copy) NSString *debugDescription;
@property (weak, nonatomic) NSObject<WFFavoriteLocationProviderDelegate> *delegate; // ivar: _delegate
@property (readonly, copy) NSString *description;
@property (readonly) NSUInteger hash;
@property (readonly) Class superclass;


-(BOOL)canProvideDefaultFavorites;
-(id)init;
-(id)initWithDelegate:(id)arg0 persistence:(id)arg1 ;
-(id)locationFromCity:(id)arg0 ;
-(id)locations;
-(void)addLocation:(id)arg0 ;
-(void)removeLocation:(id)arg0 ;
-(void)setLocations:(id)arg0 ;


@end


#endif