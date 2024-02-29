#import "DCDTTimePicker.h"

@implementation DCDTTimePicker

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(id)identifier specifier:(PSSpecifier *)specifier {
    self = [super initWithStyle:style reuseIdentifier:identifier specifier:specifier withPickerStyle:DCDTDateTimePickerStyleTime];

    return self;
}

- (void)layoutSubviews {
    [super layoutSubviews];
}

- (void)presentTimePicker {
    [super presentDateTimePicker];
}

@end