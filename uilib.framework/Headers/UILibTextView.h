//
//  UILibTextView.h
//  Client
//
//  Created by Mac on 2019/2/19.
//  Copyright © 2019 rc. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UILibTextView : UITextView
/* 占位文字 */
@property (copy, nonatomic) NSString *placeholder;
/* 占位文字颜色 */
@property (strong, nonatomic) UIColor *placeholderColor;
@end

NS_ASSUME_NONNULL_END
