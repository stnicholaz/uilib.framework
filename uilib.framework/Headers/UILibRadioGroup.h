//
//  UILibRadioGroup.h
//  Client
//
//  Created by Apple on 2018/10/8.
//  Copyright © 2018年 rc. All rights reserved.
//
//    //RadioGroup的使用方法：
//    //1.<radiogroup layout-type="hor/ver"><radio id="radio1" ... />...</radiogroup>
//    //2.选中某个radio => radioGroup.selectedRadio = UILibRadio;
//    //3.监听选中事件=>如下
//    UILibRadioGroup* radioGroup = UI_RADIOGROUP(radiogroup);
//    radioGroup.onSelectChanged = ^(UIRadioButon* radio) {
//        [Alert shortTips:weakself.view message:radio.titleLabel.text];
//    };

#import "UILibLayout.h"
#import "UILibRadio.h"


typedef void(^onRadioSelectChangedBlockDef)(UIRadioButon*);

NS_ASSUME_NONNULL_BEGIN

@interface UILibRadioGroup : UILibLayout
@property(nonatomic,copy) onRadioSelectChangedBlockDef onSelectChanged;
@property(nonatomic,weak) UILibRadio* selectRadio;
@property(nonatomic,readonly) UIView* selectRadioView;
@end

NS_ASSUME_NONNULL_END
