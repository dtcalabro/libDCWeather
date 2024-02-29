// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WEATHERIMAGELOADER_H
#define WEATHERIMAGELOADER_H

@class NSCache, CPBitmapStore;

#import <Foundation/Foundation.h>


@interface WeatherImageLoader : NSObject {
    CGFloat _scale;
}


@property (retain, nonatomic) NSCache *conditionImagesCache; // ivar: _conditionImagesCache
@property (retain, nonatomic) CPBitmapStore *store; // ivar: _store


+(id)cachedImageNamed:(id)arg0 completion:(id)arg1 ;
+(id)colorForImageColor:(id)arg0 lighter:(BOOL)arg1 ;
+(id)conditionImageBundle;
+(id)conditionImageNameWithConditionIndex:(NSInteger)arg0 ;
+(id)conditionImageNamed:(id)arg0 size:(struct CGSize )arg1 cloudAligned:(BOOL)arg2 stroke:(BOOL)arg3 strokeAlpha:(CGFloat)arg4 lighterColors:(BOOL)arg5 ;
+(id)conditionImageNamed:(id)arg0 style:(NSInteger)arg1 ;
+(id)conditionImageWithConditionIndex:(NSInteger)arg0 ;
+(id)conditionImageWithConditionIndex:(NSInteger)arg0 style:(NSInteger)arg1 ;
+(id)sharedImageLoader;
+(void)cacheImageIfNecessary:(id)arg0 ;
+(void)preloadImages;
-(id)cachedImageForKey:(id)arg0 ;
-(id)init;
-(void)setImage:(id)arg0 forKey:(id)arg1 ;


@end


#endif