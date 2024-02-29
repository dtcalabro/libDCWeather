#import <Preferences/PSListController.h>
#import <Preferences/PSSpecifier.h>
#import "DCDTCommonHeader.h"
#import "DCDTBaseListController.h"

@interface DCDTRootListController : DCDTBaseListController
@property (nonatomic, retain) UIView *optionsButtonView;
@property (nonatomic, retain) UIButton *optionsButton;
@property (nonatomic, retain) UILabel *optionsLabel;
@property (nonatomic, retain) UIBarButtonItem *menuButton;

- (void)setupBetterTitleView;
@end
