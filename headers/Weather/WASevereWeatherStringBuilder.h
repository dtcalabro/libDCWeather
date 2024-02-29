// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WASEVEREWEATHERSTRINGBUILDER_H
#define WASEVEREWEATHERSTRINGBUILDER_H


#import <Foundation/Foundation.h>


@interface WASevereWeatherStringBuilder : NSObject



+(BOOL)_hasImportantEvent:(id)arg0 ;
+(id)_capitalizeFirstWordOfString:(id)arg0 ;
+(id)_displayDescriptionForEvent:(id)arg0 useSentenceCase:(BOOL)arg1 isFirstEvent:(BOOL)arg2 ;
+(id)attributedImportantHeadlineForEvents:(id)arg0 ;
+(id)atttributedDescriptionForEvents:(id)arg0 includeLearnMore:(BOOL)arg1 ;
+(id)atttributedDescriptionForEvents:(id)arg0 includeLearnMore:(BOOL)arg1 useSentenceCase:(BOOL)arg2 ;
+(id)atttributedHeadlineForEvents:(id)arg0 ;
+(id)descriptionForEvents:(id)arg0 includeLearnMore:(BOOL)arg1 ;
+(id)descriptionForEvents:(id)arg0 includeLearnMore:(BOOL)arg1 useSentenceCase:(BOOL)arg2 ;
+(id)headlineForEvents:(id)arg0 ;
+(id)headlineForEvents:(id)arg0 shouldUppercase:(BOOL)arg1 ;
+(id)importantHeadlineForEvents:(id)arg0 ;


@end


#endif