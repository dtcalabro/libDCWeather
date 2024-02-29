#import <Foundation/Foundation.h>
#import "DCDTSubListController.h"

@implementation DCDTSubListController

- (NSArray *)specifiers {
	return _specifiers;
}

- (void) viewDidLoad {
    [super viewDidLoad];
}

- (void)loadFromSpecifier:(PSSpecifier *)specifier {
    NSString* sub = [specifier propertyForKey:@"DCDTSub"];

    _specifiers = [self loadSpecifiersFromPlistName:sub target:self];
}

- (void)setSpecifier:(PSSpecifier *)specifier {
    [self loadFromSpecifier:specifier];
    [super setSpecifier:specifier];
}

- (BOOL)shouldReloadSpecifiersOnResume {
    return FALSE;
}

@end
