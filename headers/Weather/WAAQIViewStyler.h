// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WAAQIVIEWSTYLER_H
#define WAAQIVIEWSTYLER_H


#import <Foundation/Foundation.h>


@interface WAAQIViewStyler : NSObject



+(id)shadowColor;
+(id)textColorWithLightLabel:(BOOL)arg0 ;
-(id)stringWithLogoImageFromText:(id)arg0 attribution:(id)arg1 attr:(id)arg2 ;
-(id)styledAQICategoryText:(id)arg0 mode:(NSRange)arg1 ;
-(id)styledAQILocalizedIndexText:(id)arg0 mode:(NSRange)arg1 ;
-(id)styledAQIMetadataCitationText:(id)arg0 attribution:(id)arg1 shouldInsertGlyph:(BOOL)arg2 ;
-(id)styledAQIMetadataGradeText:(id)arg0 ;
-(id)styledAQIMetadataRecommendationText:(id)arg0 ;
-(id)styledAQIMetadataSourceText:(id)arg0 ;
-(id)styledAQIText:(id)arg0 mode:(NSRange)arg1 ;
-(id)styledDashWithLabelColor:(BOOL)arg0 ;


@end


#endif