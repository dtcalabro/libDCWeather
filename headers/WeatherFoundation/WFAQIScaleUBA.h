// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFAQISCALEUBA_H
#define WFAQISCALEUBA_H

@class NSString;

#import <Foundation/Foundation.h>

#import "WFAQIScale-Protocol.h"

@interface WFAQIScaleUBA : NSObject <WFAQIScale>



@property (readonly, copy) NSString *debugDescription;
@property (readonly, copy) NSString *description;
@property (readonly) NSUInteger hash;
@property (readonly, nonatomic) NSString *name;
@property (readonly) Class superclass;


-(id)scaleCategoryForCategoryIndex:(NSUInteger)arg0 localizedCategoryDescription:(id)arg1 ;


@end


#endif