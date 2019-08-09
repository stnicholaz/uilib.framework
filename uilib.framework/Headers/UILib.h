//
//  UILib.h
//
//  Created by qt on 14-7-7.
//  Copyright (c) 2014年 ___UILIB___. All rights reserved.
//

#ifndef _UILIB_h_
#define _UILIB_h_
#ifdef __OBJC__

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

//! Project version number for uilib.
FOUNDATION_EXPORT double uilibVersionNumber;

//! Project version string for uilib.
FOUNDATION_EXPORT const unsigned char uilibVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <uilib/PublicHeader.h>

#define UILIB_SCREEN_WIDTH [UIScreen mainScreen].bounds.size.width
#define UILIB_SCREEN_HEIGHT [UIScreen mainScreen].bounds.size.height

//判断是否是ipad
#define UILIB_IS_IPAD ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad)
//判断是否是iPhoneX系列 X XR XS XS_MAX
#define UILIB_IS_IPHONE_X_ALL                 uilib_is_iPhoneX_ALL()
#define UILIB_SAFE_AREA_INSETS_BOTTOM         uilib_safeAreaInsetsBottom()
#define UILIB_STATUSBAR_HEIGHT    [[UIApplication sharedApplication] statusBarFrame].size.height
#define UILIB_NAVIGATIONBAR_HEIGHT    64.f

#define UILIB_KVC_SET_COPY(_OBJ_,_KEY_,_VALUE_) objc_setAssociatedObject(_OBJ_, _KEY_, _VALUE_, OBJC_ASSOCIATION_COPY);
#define UILIB_KVC_SET_RETAIN(_OBJ_,_KEY_,_VALUE_) objc_setAssociatedObject(_OBJ_, _KEY_, _VALUE_, OBJC_ASSOCIATION_RETAIN);
#define UILIB_KVC_SET(_OBJ_,_KEY_,_VALUE_,_ASSOCIATION_) objc_setAssociatedObject(_OBJ_, _KEY_, _VALUE_, _ASSOCIATION_);
#define UILIB_KVC_GET(_OBJ_,_KEY_) objc_getAssociatedObject(_OBJ_, _KEY_);
#define UILIB_KVC_REMOVE(_OBJ_) objc_removeAssociatedObjects(_OBJ_)


typedef UIButton UIRadioButon;
typedef UIButton UICheckButon;

#define WM_NULL 0
#define WM_CREATE 1
#define WM_DESTROY 3
#define WM_TIMER 4
#define WM_COMMAND 5
#define WM_NOTIFY 6
#define WM_KEYEVENT 7
#define WM_MENUEVENT 8

#define WM_TOUCHEVENT 200
#define WM_TOUCHDOWN 201
#define WM_TOUCHMOVE 202
#define WM_TOUCHUP 203
#define WM_TOUCHCANCEL 204

#define WM_UPDATEUI 0x399
#define WM_USER 0x400

//-------------
#define ON_CLICKED 0x001
#define ON_TEXT_CHANGED 0x002
#define ON_RECT_CHANGED 0x003
#define ON_VISIBLE_CHANGED 0x004
#define ON_ENABLE_CHANGED 0x005
#define ON_STATE_CHANGED 0x006
#define ON_FOCUS_CHANGED 0x007
#define ON_SELECT_CHANGED 0x008
#define ON_CHECK_CHANGED 0x008

#define DECLARE_UI(XXX) -(NSString*) nameOfUi{return @#XXX;}

#define PROP_NONE @property (nonatomic)
#define PROP_COPY @property (nonatomic,copy)
#define PROP_ASSIGN @property (nonatomic,assign)
#define PROP_STRONG @property (nonatomic,strong)
#define PROP_RETAIN @property (nonatomic,retain)
#define PROP_WEAK   @property (nonatomic,weak)
#define PROP_READONLY_WEAK @property (nonatomic,readonly,weak)
#define PROP_READONLY @property (nonatomic,readonly)
#define PROP_READONLY_RETAIN @property (nonatomic,readonly,retain)

#define COLOR UIColor*
#define COLORREF UIColor*
#define TRANSPARENT 0xFFFFFFFF

#define RGB(r,g,b) [UIColor colorWithRed:((float)r/255.0f) green:((float)g/255.0f) blue:((float)b/255.0f) alpha:1.0f]
#define RGBA(r,g,b,a) [UIColor colorWithRed:((float)r/255.0f) green:((float)g/255.0f) blue:((float)b/255.0f) alpha:a/255.0f]

long RGB2LONG(int r, int g, int b);
long CLR2LONG(UIColor* clr);
UIColor* LONG2CLR(long vle);

#define LOBYTE(w)           ((unsigned short)(((unsigned long)(w)) & 0xff))
#define GetRValue(rgb)      (LOBYTE(rgb))
#define GetGValue(rgb)      (LOBYTE(((unsigned int)(rgb)) >> 8))
#define GetBValue(rgb)      (LOBYTE((rgb)>>16))

#define IS_COLOR_STR(strVal) ([strVal hasPrefix:@"#"] || [strVal hasPrefix:@"0x"] || [strVal hasPrefix:@"0X"] ||[strVal hasPrefix:@"rgb("] || [strVal hasPrefix:@"rgba"] || [strVal hasPrefix:@"@color/"] || [strVal rangeOfString:@","].location != NSNotFound)

enum
{
    OS_NORMAL=0,
    OS_PRESSED,
    OS_DISABLED,
    OS_NORMAL2,
    OS_PRESSED2,
    OS_DISABLED3,
};

enum
{
    OT_UNKOWN=0,
    OT_WINDOW,
    OT_VIEW,
    OT_WIDGET,
    OT_OBJECT,
    OT_LABEL,
    OT_LAYOUT,
    OT_BUTTON,
    OT_TOOLBUTTON,
    OT_CHECKBOX,
    OT_RADIOBOX,
    OT_SWITCH,
    OT_COMBOBOX,
    OT_IMAGE,
    OT_EDIT,
    OT_HYPERLINK,
    OT_SLIDER,
    OT_SCROLLBAR,
    OT_TABCTRL,
    OT_TABITEM,
    OT_LISTVIEW,
    OT_LISTITEM,
    OT_TREEVIEW,
    OT_TREEITEM,
    OT_MENU,
    OT_MENUITEM,
    OT_MENUSPLITER
};

enum
{
    RT_Null=0,
    RT_Default,
    RT_NewInst
};
enum
{
    AL_UNDEFINE=-1,
    AL_LEFT=0,
    AL_TOP,
    AL_RIGHT,
    AL_BOTTOM,
    AL_CENTER,
    AL_FILL
};
enum
{
    STRM_NORMAL=0,
    STRM_STRETCH,
    STRM_STRETCH_NOCENTER,
    STRM_STRETCH_PROPORT
};

enum
{
    LT_UNKONW=0,
    LT_HOR,
    LT_VER,
    LT_FLOW,
    LT_REL,
    LT_ABS
};

typedef struct tagRect
{
    float left;
    float top;
    float right;
    float bottom;
}RECT,*LPRECT;
#define CG2RECT(_CGRECT_) {_CGRECT_.origin.x,_CGRECT_.origin.y,_CGRECT_.origin.x+_CGRECT_.size.width,_CGRECT_.origin.y+_CGRECT_.size.height};
CGRect RECT2CG(RECT rect);
RECT NewRect(float l, float t, float r, float b);
void RectMoveToXY(RECT* lpRect, float x, float y);

typedef struct tagPoint
{
    float x;
    float y;
}POINT,*LPPOINT;
#define CG2PT(_CGPOINT_) {_CGPOINT_.x,_CGPOINT_.y}
int PtInRect(RECT rect, POINT pt);
int IsRectInterset(RECT rect1, RECT rect2);

typedef struct tagSize
{
    float cx;
    float cy;
}SIZE,*LPSIZE;
#define CG2SIZE(_CGSIZE_) {_CGSIZE_.width,_CGSIZE_.height}

typedef struct tagRange
{
    float min;
    float max;
}RANGE,*LPRANGE;

typedef struct tagRadius
{
    float topLeft;
    float topRight;
    float bottomLeft;
    float bottomRight;
}RADIUS,*LPRADIUS;


typedef struct tagAlign
{
    int x;
    int y;
}ALIGN,*LPALIGN;



typedef struct tagState
{
    unsigned long normal;
    unsigned long pressed;
    unsigned long disabled;
}STATE, LPSTATE;

BOOL isNotEmpty(NSString* str);
BOOL isEmptyStr(NSString* str);
BOOL isEqualIgnoreCase(NSString* str, NSString* casex);
BOOL isEqualIgnoreCase2(NSString* str, NSString* case1, NSString* case2);
BOOL isZeroRect(RECT rect);
BOOL isZeroSize(SIZE size);
BOOL isZeroPoint(POINT point);
BOOL isZeroRadius(RADIUS radius);

CGRect rect2cg(RECT rect);
UIEdgeInsets rect2edge(RECT rect);
CGSize size2cg(SIZE size);
UIEdgeInsets rect2insets(RECT rect);

UIImage* clr2img(UIColor* color);
UIImage* imageNameStretch(NSString* name, RECT stretch);
UIImage* imageWithStretch(UIImage* image, RECT stretch);

BOOL uilib_is_iPhoneX_ALL();
float uilib_safeAreaInsetsBottom();

#endif
#endif
