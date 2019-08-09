//
//  UILibAttrib.h
//  UiTest
//
//  Created by qt on 14-7-7.
//  Copyright (c) 2014年 ___UILIBTEST___. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UILib.h"

@class UILibAttrib;

//@protocol UILibAttribDelegate <NSObject>
//- (void)didAttrib:(UILibAttrib*)attrib;
//@end

@interface UILibAttrib : NSObject
- (id)initWithAttributes:(NSDictionary*)attributes;
- (void)append:(NSDictionary*)attributes;

- (BOOL)hasAttr:(NSString*)attr;
- (NSString*)strAttr:(NSString*) attr;
//用于兼容多个别名
- (NSString*)strAttr:(NSString*)attr or:(NSString*)attr2;
- (NSString*)strAttr:(NSString*)attr or:(NSString*)attr2 or:(NSString*)attr3;
- (int)intAttr:(NSString*)attr;
- (int)intAttr:(NSString*)attr or:(NSString*)attr2;
- (int)intAttr:(NSString*)attr or:(NSString*)attr2 or:(NSString*)attr3;
- (BOOL)boolAttr:(NSString*)attr;
- (BOOL)boolAttr:(NSString*)attr or:(NSString*)attr2;
- (BOOL)boolAttr:(NSString*)attr or:(NSString*)attr2 or:(NSString*)attr3;
- (float)floatAttr:(NSString*)attr;
- (float)floatAttr:(NSString*)attr or:(NSString*)attr2;
- (float)floatAttr:(NSString*)attr or:(NSString*)attr2 or:(NSString*)attr3;
- (POINT)pointAttr:(NSString*)attr;
- (POINT)pointAttr:(NSString*)attr or:(NSString*)attr2;
- (POINT)pointAttr:(NSString*)attr or:(NSString*)attr2 or:(NSString*)attr3;
- (SIZE)sizeAttr:(NSString*)attr;
- (SIZE)sizeAttr:(NSString*)attr or:(NSString*)attr2;
- (SIZE)sizeAttr:(NSString*)attr or:(NSString*)attr2 or:(NSString*)attr3;
- (RECT)rectAttr:(NSString*)attr;
- (RECT)rectAttr:(NSString*)attr or:(NSString*)attr2;
- (RECT)rectAttr:(NSString*)attr or:(NSString*)attr2 or:(NSString*)attr3;
- (UIColor*)colorAttr:(NSString*)attr;
- (UIColor*)colorAttr:(NSString*)attr or:(NSString*)attr2;
- (UIColor*)colorAttr:(NSString*)attr or:(NSString*)attr2 or:(NSString*)attr3;

@end
