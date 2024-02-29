// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef PROGRESSCONTROLLER_H
#define PROGRESSCONTROLLER_H

@class NSTimer;

#import <Foundation/Foundation.h>


@interface ProgressController : NSObject {
    BOOL _progressShowing;
    int _loadingCount;
    NSTimer *_hideSpinnerTimer;
}




+(id)sharedProgressController;
-(void)_hideSpinner;
-(void)_setHideSpinnerTimer:(id)arg0 ;
-(void)_showSpinner;
-(void)setLoadingData:(BOOL)arg0 ;
-(void)suspend;
-(void)userScrolled;


@end


#endif