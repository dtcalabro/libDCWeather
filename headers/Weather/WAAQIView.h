// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WAAQIVIEW_H
#define WAAQIVIEW_H

@class UIView, UILabel;
@protocol WAAQIViewDelegate;


#import "WAAQIScaleView.h"
#import "WAAQIAttributionStringBuilder.h"
#import "City.h"
#import "WAAQIViewStyler.h"

@interface WAAQIView : UIView

@property (retain, nonatomic) UILabel *airQualityMetadataGradeLabel; // ivar: _airQualityMetadataGradeLabel
@property (retain, nonatomic) UILabel *airQualityRecommendationLabel; // ivar: _airQualityRecommendationLabel
@property (retain, nonatomic) UILabel *aqiAgencyLabel; // ivar: _aqiAgencyLabel
@property (retain, nonatomic) UILabel *aqiCategoryLabel; // ivar: _aqiCategoryLabel
@property (retain, nonatomic) UILabel *aqiCitationLabel; // ivar: _aqiCitationLabel
@property (retain, nonatomic) UILabel *aqiIndexLabel; // ivar: _aqiIndexLabel
@property (retain, nonatomic) UILabel *aqiLabel; // ivar: _aqiLabel
@property (retain, nonatomic) WAAQIScaleView *aqiScaleView; // ivar: _aqiScaleView
@property (retain, nonatomic) WAAQIAttributionStringBuilder *attributionStringBuilder; // ivar: _attributionStringBuilder
@property (retain, nonatomic) City *city; // ivar: _city
@property (retain, nonatomic) UILabel *dash; // ivar: _dash
@property (weak, nonatomic) NSObject<WAAQIViewDelegate> *delegate; // ivar: _delegate
@property (nonatomic) BOOL forceHideThisEntireView; // ivar: _forceHideThisEntireView
@property (nonatomic) BOOL hideCitationString; // ivar: _hideCitationString
@property (nonatomic) BOOL hideRecommendationString; // ivar: _hideRecommendationString
@property (nonatomic) BOOL initialized; // ivar: _initialized
@property (nonatomic) NSUInteger layoutMode; // ivar: _layoutMode
@property (retain, nonatomic) WAAQIViewStyler *styler; // ivar: _styler


+(id)createWeatherLabelWithLightColor:(BOOL)arg0 ;
-(BOOL)accessibilityElementsHidden;
-(BOOL)isAccessibilityElement;
-(BOOL)shouldInsertGlyphImage:(id)arg0 ;
-(CGFloat)contentMarginFromTop;
-(id)accessibilityLabel;
-(id)accessibilityValue;
-(id)currentScaleCategoryLabelForCity:(id)arg0 ;
-(id)drawableScaleForCity:(id)arg0 ;
-(id)metadataLabelForCity:(id)arg0 ;
-(id)scaleDisplayNameForCity:(id)arg0 ;
-(struct CGRect )adjustedFrame:(struct CGRect )arg0 basedOnFont:(id)arg1 desiredBaseline:(CGFloat)arg2 ;
-(struct CGRect )rtlAdjustFrame:(struct CGRect )arg0 inBounds:(struct CGRect )arg1 ;
-(struct CGSize )sizeForAQIAvailableThatFits:(struct CGSize )arg0 ;
-(struct CGSize )sizeForAQITemporarilyUnavailableThatFits:(struct CGSize )arg0 ;
-(struct CGSize )sizeForCompactOneLineLayoutWithScaleViewThatFits:(struct CGSize )arg0 platterView:(BOOL)arg1 ;
-(struct CGSize )sizeForExtendedLayoutWithScaleViewThatFits:(struct CGSize )arg0 ;
-(struct CGSize )sizeForLayoutWithoutScaleViewThatFits:(struct CGSize )arg0 ;
-(struct CGSize )sizeForTwoLineLayoutWithScaleViewTheFits:(struct CGSize )arg0 platterView:(BOOL)arg1 ;
-(struct CGSize )sizeThatFits:(struct CGSize )arg0 ;
-(void)handleTapGesture:(id)arg0 ;
-(void)hideEverything;
-(void)initialize;
-(void)layoutForCompactModeWithScaleInPlatterView:(BOOL)arg0 ;
-(void)layoutForExtendedModeWithScale;
-(void)layoutForModeAQITemporarilyUnavailable;
-(void)layoutForModeWithoutScale;
-(void)layoutForTwoLinesLayoutWithScaleInPlatterView:(BOOL)arg0 ;
-(void)layoutSubviews;
-(void)prepareForReuse;
-(void)setupForLayoutCompactScaleViewOneLinePlatterView:(BOOL)arg0 ;
-(void)setupForLayoutCompactScaleViewTwoLinesPlatterView:(BOOL)arg0 ;
-(void)setupForLayoutExtendedNoScaleView;
-(void)setupForLayoutExtendedScaleView;
-(void)setupForLayoutTemporarilyUnavailable;
-(void)updateWithCity:(id)arg0 layoutMode:(NSUInteger)arg1 ;


@end


#endif