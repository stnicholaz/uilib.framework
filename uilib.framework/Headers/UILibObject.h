//
//  UILibObject.h
//  UiTest
//
//  Created by qt on 14-7-7.
//  Copyright (c) 2014年 ___UILIBTEST___. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "UILib.h"
@class UILibLayout;
@class UILibManager;
@class UILibAttrib;
@class UILibCssStyle;


@interface UiIdManager : NSObject
{
    long			m_wNextID;
    NSMutableArray* m_lsFreeIDs;
}
- (long) CreateObjecteID;
- (void) ReleaseID:(long) oid;
@end


@interface UILibObject : NSObject
{
}
PROP_READONLY long intID;
PROP_COPY NSString* stringID;
PROP_COPY NSString* text;
PROP_COPY NSString* prefix;
PROP_COPY NSString* suffix;
PROP_READONLY BOOL  isCreated;
PROP_ASSIGN int     type;
PROP_ASSIGN BOOL    widthToFit;
PROP_ASSIGN BOOL    heightToFit;
PROP_ASSIGN float   fitOffset;
PROP_ASSIGN BOOL    visible;
PROP_ASSIGN int     widthPercent;
PROP_ASSIGN int     heightPercent;
PROP_ASSIGN BOOL    widthIsFixed;
PROP_ASSIGN BOOL    heightIsFixed;
PROP_ASSIGN float   weight;
PROP_READONLY float   measureWidth;
PROP_READONLY float   measureHeight;
PROP_NONE   RECT    rect;
PROP_NONE   CGRect  frame;
PROP_NONE   RECT    padding;
PROP_NONE   RECT    margin;
PROP_ASSIGN ALIGN   textAlign;
PROP_ASSIGN ALIGN   alignParent;
PROP_RETAIN UIView* view;
PROP_RETAIN UILibLayout* parentLayout;
PROP_RETAIN UILibManager* uiManager;
PROP_RETAIN UILibCssStyle* cssStyle;

+ (UILibObject*)objectOfBindView:(UIView*)view;
- (UILibObject*)initWithTagName:(NSString*)tagName attributes:(NSDictionary*)attributes parentView:(UIView*)view;
- (BOOL)Create;
- (void)Destroy;

- (float)getWidth;
- (float)getHeight;
- (void)setWidth:(float)width;
- (void)setHeight:(float)height;
- (void)moveToX:(float)x Y:(float)y;
- (void)setRectByLayout:(RECT)rect;
- (void)onMeasure:(float)measureWidth height:(float)measureHeight;

- (RECT)rectOfClient;
- (SIZE)fitSize;

- (void)show;
- (void)hide;
- (BOOL)isVisible;//check parent layout visible too, self.visible by self only

- (void)didCreate;
- (void)didDestroy;
- (void)didAttrib:(UILibAttrib*)attrib;
- (void)didRectChanged:(RECT)pre_rect to:(RECT)new_rect;
- (void)didTextChanged:(NSString*)pre_text to:(NSString*)new_text;
- (void)didVisibleChanged:(BOOL)pre_visible to:(BOOL)new_visible;

- (UIView*)getParentView;
@end




