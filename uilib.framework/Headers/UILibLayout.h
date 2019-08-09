//
//  UILibLayout.h
//  UiTest
//
//  Created by qt on 14-7-7.
//  Copyright (c) 2014年 ___UILIBTEST___. All rights reserved.
//

#import "UILibObject.h"
@class UiAttrib;
//@class UiCanvas;

@interface UILibLayout : UILibObject

PROP_ASSIGN int     layoutType;
PROP_ASSIGN BOOL    canRelayout;
PROP_ASSIGN POINT   spacing;

+ (int) GetLayoutTypeFromName:(NSString*)name;
- (NSMutableArray*) GetVisibleChild;
- (RECT) GetLayoutRect;
- (BOOL) AddChild:(UILibObject*)obj;
- (BOOL) IsChild:(UILibObject*)obj;
- (UILibObject*) FindFirstChild;
- (SIZE) sizeOfContent;
- (SIZE) sizeOfContentWithPadding;

- (void) MoveLayoutTo:(float)offsetX y:(float)offsetY;
- (void) Relayout;
+ (void) HorRelayout:(NSMutableArray*)vtChild rect:(RECT)rect align_h:(int)align align_v:(int)valign spacing:(float)spacing;
+ (void) VerRelayout:(NSMutableArray*)vtChild rect:(RECT)rect align_h:(int)align align_v:(int)valign spacing:(float)spacing;
+ (void) RelRelayout:(NSMutableArray*)vtChild rect:(RECT)rect align_h:(int)align_h align_v:(int)align_v spacing:(POINT)spacing;
+ (void) FlowRelayout:(NSMutableArray*)vtChild rect:(RECT)rect align_h:(int)align align_v:(int)valign spacing:(POINT)spacing;

@end
