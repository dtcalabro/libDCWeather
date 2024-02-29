#import <Preferences/PSListController.h>
#import <Preferences/PSSpecifier.h>
#import <Preferences/PSTableCell.h>
#import <UIKit/UIKit.h>
#import "DCDTDateTimePickerView.h"
#import "DCDTBaseTableCell.h"

@interface DCDTDateTimePicker : DCDTBaseTableCell {
	DCDTDateTimePickerView *_dateTimePickerView;
	UIViewController *_rootViewController;
    DCDTDateTimePickerStyle _dateTimePickerStyle;
}
@property (nonatomic, retain) DCDTDateTimePickerView *dateTimePickerView;
@property (nonatomic, retain) UIViewController *rootViewController;
//@property (nonatomic, retain) UIVisualEffectView *blurEffectView;
//@property (nonatomic, retain) UIView *dimBackgroundView;

@property (nonatomic) DCDTDateTimePickerStyle dateTimePickerStyle;

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(id)identifier specifier:(PSSpecifier *)specifier withPickerStyle:(DCDTDateTimePickerStyle)pickerStyle;

- (void)presentDateTimePicker;
- (void)setDateTimePickerStyle:(DCDTDateTimePickerStyle)style;
- (DCDTDateTimePickerStyle)dateTimePickerStyle;
- (void)updateValueLabel;
@end
