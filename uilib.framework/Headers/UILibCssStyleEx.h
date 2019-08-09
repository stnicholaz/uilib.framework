//
//  UILibCssStyleEx.h
//
//  Created by qt on 14-7-7.
//  Copyright (c) 2014年 ___UILIBTEST___. All rights reserved.
//

#import "UILibCssStyle.h"


@interface UILibCssStyleEx : UILibCssStyle
{
}
//背景
//PROP_RETAIN UIColor*        bkgrd_color;
//PROP_RETAIN UIColor*        bkgrd_pressed_color;
//PROP_COPY   NSString*       bkgrd_image;
//PROP_COPY   NSString*       bkgrd_pressed_image;
//PROP_ASSIGN RECT            bkgrd_image_stretch;
//PROP_RETAIN UIColor*        border_color;
//PROP_ASSIGN CGFloat         border_width;
//PROP_ASSIGN CGFloat         border_radius;
//PROP_RETAIN UIFont*         font;
//PROP_RETAIN UIColor*        font_color;                //字体颜色 font-color="0,0,0"
//PROP_RETAIN UIColor*        font_selected_color;
//PROP_RETAIN UIColor*        font_pressed_color;


////背景图
//PROP_STRONG NSString*       bkgrd_image;			//图片文件名 bkgrd-image=".png@35x25"
//PROP_ASSIGN SIZE            bkgrd_image_size;
//PROP_ASSIGN ALIGN           bkgrd_image_align;
//PROP_ASSIGN int             bkgrd_stretch_mode; 	//绘制模式 bkgrd-stretch-mode="DIF_STRETCH" // xgdidef.h -> enum DRAW_IMAGE_FLAG
//PROP_ASSIGN RECT            bkgrd_stretch_zone;     //拉伸范围 bkgrd-stretch-zone="3,3,3,3"//左上右下
//
////边框
//PROP_ASSIGN RECT            border_width;			//四条边框的厚度 border-width="1"
//PROP_ASSIGN RECT            border_color;;			//四条边框的颜色 border-color="255,0,0" 或 "rgb(0,0,0),...
//PROP_ASSIGN RADIUS          border_radius;;			//圆角半径 border-radius="5"
//
////边框图
//PROP_STRONG NSString*       border_image;			//图片文件名 border-image=".png@35x25"
//PROP_ASSIGN SIZE            border_image_size;
//PROP_ASSIGN ALIGN           border_image_align;
//PROP_ASSIGN int             border_stretch_mode;    //绘制模式 border-stretch-mode="DIF_STRETCH"
//PROP_ASSIGN RECT            border_stretch_zone;    //拉伸范围 border-stretch-zone="3,3,3,3"
////图标
//PROP_STRONG NSString*       icon;					//图标文件名 icon=".png@42x40"
//
//PROP_ASSIGN int             icon_index;				//图标序数 icon-index="0"
//PROP_ASSIGN BOOL            icon_auto_index;		//图标随鼠标状态自动改变序数 icon-auto-index="0"
//PROP_ASSIGN int             icon_align;				//图标相对文本的位置 icon-align="left"
//PROP_ASSIGN int             icon_space;				//图标和文本间的间距 icon-space="5"
//PROP_ASSIGN SIZE            icon_size;              //图标显示的尺寸 依此来判断是否缩放
//
////字体
//PROP_STRONG NSString*       font;					//字体样式 font="system-default@12px#underline#bold#i..."
//PROP_STRONG NSString*       font_face;
//
////文本
//PROP_ASSIGN ALIGN          text_align; //文本方位 text-align="left,top"//如果写成这样="left",代表"left,center"
//PROP_ASSIGN BOOL           text_wrap;                  //是否換行 text-wrap="1"
//PROP_ASSIGN BOOL           text_bold;
//PROP_ASSIGN BOOL           text_underline;
//PROP_ASSIGN BOOL           text_italic;
//PROP_ASSIGN BOOL           text_ellipsis;              //溢出时是否显示"..."	text-ellipsis="1"
////空白
//PROP_ASSIGN RECT           padding;
//PROP_ASSIGN RECT           margin;

@end
