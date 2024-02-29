#import <Foundation/Foundation.h>
#import "DCDTDangerButton.h"

@implementation DCDTDangerButton

- (id)init {
    return [super init];
}

- (void)layoutSubviews {
    [super layoutSubviews];

    [[self textLabel] setTextColor:[UIColor systemRedColor]];
    self.interactionTintColor = [UIColor systemRedColor];
    UILabel *label = [self titleLabel];
    label.highlightedTextColor = [UIColor systemRedColor];
}

@end
