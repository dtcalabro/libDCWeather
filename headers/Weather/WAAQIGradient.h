// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WAAQIGRADIENT_H
#define WAAQIGRADIENT_H

@class NSMutableDictionary, NSMutableArray, NSMutableIndexSet, NSArray;

#import <Foundation/Foundation.h>


@interface WAAQIGradient : NSObject

@property (readonly, nonatomic) NSMutableDictionary *colorsByLocation; // ivar: _colorsByLocation
@property (retain, nonatomic) NSMutableArray *internalStops; // ivar: _internalStops
@property (readonly, nonatomic) NSMutableIndexSet *locationStops; // ivar: _locationStops
@property (readonly, nonatomic) struct _NSRange range; // ivar: _range
@property (readonly, copy, nonatomic) NSArray *stops;


-(id)gradientStopForLocation:(NSUInteger)arg0 ;
-(id)initWithRange:(struct _NSRange )arg0 ;
-(void)addGradientStop:(id)arg0 ;


@end


#endif