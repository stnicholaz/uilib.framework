//
//  UILibManager.h
//
//  Created by on 14-7-7.
//  Copyright (c) 2014年  All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UILib.h"
#import "UILibObject.h"
#import "UILibLayout.h"

@class UILibObject;
@class UILibLayout;
@class UILibAttrib;
@class UILibXmlElement;
@class UILibScrollFragment;
@class UILibXmlParser;

#define UI_NAME(_NAME_) - (NSString*) nameOfUi{return @#_NAME_;}

#define UI_OBJECT(_ID_)         [self.ui objectWithStringId:@#_ID_]
#define UI_LAYOUT(_ID_)         ((UILibLayout*)[self.ui objectWithStringId:@#_ID_])
#define UI_VIEW(_ID_)           [self.ui viewWithStringId:@#_ID_]
#define UI_CONTROL(_ID_)        ((UIControl*)UI_VIEW(_ID_))
#define UI_LAYERVIEW(_ID_)      ((UILibLayerView*)UI_VIEW(_ID_))
#define UI_EXTERN(_ID_,_CLASS_) ((_CLASS_*)UI_VIEW(_ID_))
#define UI_LABEL(_ID_)          ((UILabel*)UI_VIEW(_ID_))
#define UI_BUTTON(_ID_)         ((UIButton*)UI_VIEW(_ID_))
#define UI_RADIO(_ID_)          ((UILibRadio*)UI_VIEW(_ID_))
#define UI_RADIOGROUP(_ID_)     ((UILibRadioGroup*)UI_OBJECT(_ID_))
#define UI_CHECK(_ID_)          ((UILibCheck*)UI_VIEW(_ID_))
#define UI_TEXTVIEW(_ID_)       ((UITextView*)UI_VIEW(_ID_))
#define UI_TEXTFIELD(_ID_)      ((UITextField*)UI_VIEW(_ID_))
#define UI_IMAGEVIEW(_ID_)      ((UIImageView*)UI_VIEW(_ID_))
#define UI_SWITCH(_ID_)         ((UISwitch*)UI_VIEW(_ID_))
#define UI_TOOLBAR(_ID_)        ((UIToolBar*)UI_VIEW(_ID_))
#define UI_TABBAR(_ID_)         ((UITabBar*)UI_VIEW(_ID_))
#define UI_SCROLLVIEW(_ID_)     ((UIScrollView*)UI_VIEW(_ID_))
#define UI_TABLEVIEW(_ID_)      ((UITableView*)UI_VIEW(_ID_))
#define UI_COLLECTIONVIEW(_ID_) ((UICollectionView*)UI_VIEW(_ID_))
#define UI_WEBVIEW(_ID_)        ((WKWebView*)UI_VIEW(_ID_))
#define UI_SLIDER(_ID_)         ((UISlider*)UI_VIEW(_ID_))
#define UI_SEGMENTEDCONTROL(_ID_) ((UISegmentedControl*)UI_VIEW(_ID_))
#define UI_DATEPICKER(_ID_)     ((UIDatePicker*)UI_VIEW(_ID_))

#define FUNC_UIVIEW(_ID_)           - (UIView*)_ID_{return (UIView*)UI_VIEW(_ID_);}
#define FUNC_EXTERN(_ID_,_CLASS_)   - (_CLASS_*)_ID_{return (_CLASS_*)UI_VIEW(_ID_);}
#define FUNC_EXTERN_EX(_ID_,_CLASS_,_FUNC_) - (_CLASS_*)_FUNC_{return (_CLASS_*)UI_VIEW(_ID_);}
#define FUNC_UICONTROL(_ID_)        FUNC_EXTERN(_ID_,UIControl)
#define FUNC_UILABEL(_ID_)          FUNC_EXTERN(_ID_,UILabel)
#define FUNC_UIBUTTON(_ID_)         FUNC_EXTERN(_ID_,UIButton)
#define FUNC_UIRADIO(_ID_)          FUNC_EXTERN(_ID_,UILibRadio)
#define FUNC_UIRADIOGROUP(_ID_)     FUNC_EXTERN(_ID_,UILibRadioGroup)
#define FUNC_UITEXTVIEW(_ID_)       FUNC_EXTERN(_ID_,UITextView)
#define FUNC_UITEXTFIELD(_ID_)      FUNC_EXTERN(_ID_,UITextField)
#define FUNC_UIIMAGEVIEW(_ID_)      FUNC_EXTERN(_ID_,UIImageView)
#define FUNC_UISWITCH(_ID_)         FUNC_EXTERN(_ID_,UISwitch)
#define FUNC_UITOOLBAR(_ID_)        FUNC_EXTERN(_ID_,UIToolBar)
#define FUNC_UITABBAR(_ID_)         FUNC_EXTERN(_ID_,UITabBar)
#define FUNC_UISCROLLVIEW(_ID_)     FUNC_EXTERN(_ID_,UIScrollView)
#define FUNC_UITABLEVIEW(_ID_)      FUNC_EXTERN(_ID_,UITableView)
#define FUNC_UICOLLECTIONVIEW(_ID_) FUNC_EXTERN(_ID_,UICollectionView)
#define FUNC_UIWEBVIEW(_ID_)        FUNC_EXTERN(_ID_,WKWebView)
#define FUNC_VKWEBVIEW(_ID_)        FUNC_EXTERN(_ID_,WKWebView)
#define FUNC_UISLIDER(_ID_)         FUNC_EXTERN(_ID_,UISlider)
#define FUNC_UISEGMENTEDCONTROL(_ID_) FUNC_EXTERN(_ID_,UISegmentedControl)
#define FUNC_UIDATEPICKER(_ID_)     FUNC_EXTERN(_ID_,UIDatePicker)

@interface UILibManager : NSObject

@property (nonatomic,copy) NSString* uiname;
@property (nonatomic,weak) UILibLayout* rootLayout;
@property (nonatomic,weak) UIViewController* controller;
@property (nonatomic,readonly,weak) UIView* view;
@property (nonatomic,readonly,retain) UILibAttrib* viewAttribs;
@property (nonatomic, assign) BOOL useSafeArea;
//XML解析器对象
@property (nonatomic,strong) UILibXmlParser *xmlparser;

+ (void)setBundleName:(NSString*)name;
+ (NSString*)bundleName;
+ (NSString*)bundlePath;
+ (NSString*)bundleFilePathOfUI:(NSString*)uiname;
+ (UIView*)inflate:(NSString*)ui_filename frame:(CGRect)frame;

- (id) initWithView:(UIView*)view;
- (id) initWithViewController:(UIViewController*)viewController;
- (BOOL) loadUI:(NSString*)uiname;
- (void) unloadUI;
- (void)syncStyleData:(NSDictionary*)styles;
- (NSDictionary*)styleByName:(NSString*)name;
//- (void) ReadNavigationBar:(UILibXmlElement*)element;
- (void) ReadLayoutChild:(UILibXmlElement*)layoutElement layout:(UILibLayout*)layout;
- (void) ReadObjectAttrib:(UILibObject*)obj element:(UILibXmlElement*)ele;
- (BOOL) AddObject:(UILibObject*)obj parentLayout:(UILibLayout*)parent;
- (void) ReadScrollViewChild:(UILibXmlElement*)element scrollFragment:(UILibScrollFragment*)scrollFragment
;
- (UILibObject*)rootObject;
- (UIView*) rootLayoutView;
- (NSInteger) getObjectCount;
- (void)relayoutUI:(CGRect)rect;
- (CGSize)sizeOfContent;
- (CGFloat)widthOfContent;
- (CGFloat)heightOfContent;
- (void)didContentHeightChanged;
- (UILibObject*) objectWithId:(long)oid;
- (UILibObject*) objectWithStringId:(NSString*)sid;
- (UIView*)viewWithStringId:(NSString*)sid;
- (NSDictionary*)allIdObjectMap;
- (void)removeObjcAssociatedObjects;
@end
