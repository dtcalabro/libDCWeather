#import <UIKit/UIKit.h>
#import "DCDTCommonHeader.h"

@interface DCDTBetterTitleView : UIView
- (instancetype)initWithTitle:(NSString *)title minimumScrollOffsetRequired:(CGFloat)minimumOffset;
- (void)adjustLabelPositionToScrollOffset:(CGFloat)offset;
- (void)updateTitleColorBasedOnCurrentInterfaceStyle;
@end