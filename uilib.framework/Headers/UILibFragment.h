//
//  UIBaseViewController.h
//
//  Created by  on 16/4/12.
//
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "UILibManager.h"
#import "UILibViewController.h"

@interface UILibFragment : UIView

PROP_READONLY_RETAIN UILibManager* ui;
PROP_WEAK UILibViewController* viewController;
@property(nonatomic) BOOL unloadWhenRemoveFromSuperview;
- (void)viewDidLoad;
- (void)loadUI;
- (void)unloadUI;
- (NSString*)nameOfUi;
- (CGRect)frameOfClient;
- (void)relayoutUI;
@end
