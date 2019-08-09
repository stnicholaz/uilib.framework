//
//  UIBaseViewController.h
//
//  Created by  on 16/4/12.
//
//

#import <UIKit/UIKit.h>
#import "UILibManager.h"


@interface UILibViewController : UIViewController
{
}
@property(nonatomic, readonly, retain) UILibManager* ui;
- (NSString*)nameOfUi;
- (CGRect)frameOfClient;
- (void)relayoutUI;
- (void)unloadUI;

@end
