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

@interface UILibScrollFragment : UIScrollView

PROP_READONLY_RETAIN UILibManager* ui;
PROP_READONLY_WEAK UILibViewController* viewController;
- (NSString*)nameOfUi;
- (CGRect)frameOfClient;
- (void)RelayoutUI;
- (void)UnloadUI;

@end
