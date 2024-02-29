#import <Preferences/PSSpecifier.h>
#import <Preferences/PSTableCell.h>
#import <UIKit/UIKit.h>
#import "DCDTDateTimePicker.h"

@interface DCDTTimePicker : DCDTDateTimePicker {
    DCDTDateTimePickerView *_timePickerView;
}

@property (nonatomic, retain) DCDTDateTimePickerView *timePickerView;
@end