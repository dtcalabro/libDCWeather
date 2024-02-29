#import <UIKit/UIKit.h>
#import <Preferences/PSTableCell.h>
#import <Preferences/PSSpecifier.h>
#import "DCDTCommonHeader.h"

@interface DCDTHeaderCell : PSTableCell
- (id)initWithSpecifier:(PSSpecifier *)specifier;
- (void)layoutSubviews;
- (CGFloat)preferredHeightForWidth:(CGFloat)arg1;
@end