#import "DCDTTimeIntervalPicker.h"

@implementation DCDTTimeIntervalPicker

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(id)identifier specifier:(PSSpecifier *)specifier {
    self = [super initWithStyle:style reuseIdentifier:identifier specifier:specifier withPickerStyle:DCDTDateTimePickerStyleTimeInterval];

    return self;
}

- (void)layoutSubviews {
    [super layoutSubviews];
}

- (void)presentTimeIntervalPicker {
    [super presentDateTimePicker];
}

@end