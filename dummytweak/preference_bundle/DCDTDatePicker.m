#import "DCDTDatePicker.h"

@implementation DCDTDatePicker

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(id)identifier specifier:(PSSpecifier *)specifier {
    self = [super initWithStyle:style reuseIdentifier:identifier specifier:specifier withPickerStyle:DCDTDateTimePickerStyleDate];

    return self;
}

- (void)layoutSubviews {
    [super layoutSubviews];
}

- (void)presentDatePicker {
    [super presentDateTimePicker];
}

@end