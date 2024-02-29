#import "DCDTDateAndTimePicker.h"

@implementation DCDTDateAndTimePicker

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(id)identifier specifier:(PSSpecifier *)specifier {
    self = [super initWithStyle:style reuseIdentifier:identifier specifier:specifier withPickerStyle:DCDTDateTimePickerStyleDateAndTime];

    return self;
}

- (void)layoutSubviews {
    [super layoutSubviews];
}

- (void)presentDateAndTimePicker {
    [super presentDateTimePicker];
}

@end