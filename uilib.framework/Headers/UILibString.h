//
//  UILibString.h
//  UiTest
//
//  Created by qt on 14-7-7.
//  Copyright (c) 2014年 ___UILIBTEST___. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UILib.h"

@interface UILibString : NSObject

+ (BOOL)isNotEmpty:(NSString*)str;
+ (BOOL)isEmpty:(NSString*)str;
+ (BOOL)isEqualIgnoreCase:(NSString*)str1 to:(NSString*)str2;
+ (BOOL)isIntegerStr:(NSString *)str;
+ (BOOL)isDoubleStr:(NSString *)str;
+ (int) str2int:(NSString*)str;
+ (NSString*)int2str:(int)int_;
+ (NSString*)long2str:(long)long_;
+ (uint32_t) hex2int:(NSString *)str;
+ (float) str2float:(NSString*)str;
+ (double) str2double:(NSString*)str;
+ (BOOL) str2bool:(NSString*)str;
+ (POINT) str2pt:(NSString*)str;
+ (SIZE) str2size:(NSString*)str;
+ (RANGE) str2range:(NSString*)str;
+ (RECT) str2rect:(NSString*)str;
+ (UIColor*) str2clr:(NSString*)str;
+ (NSArray*) split:(NSString*)str by:(NSString*)sp_str;
+ (NSString*) replace:(NSString*)str oldstr:(NSString*)old_str newstr:(NSString*)new_str;
+ (ALIGN) str2align:(NSString*)strVal;
+ (NSUInteger)indexOf:(NSString*)str substr:(NSString*)substr;

+ (double)calcFormula:(NSString*)str;
@end
