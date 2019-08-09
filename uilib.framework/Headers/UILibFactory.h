//
//  UiFactory.h
//  UiTest
//
//  Created by qt on 14-7-7.
//  Copyright (c) 2014年 ___UILIBTEST___. All rights reserved.
//
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "UILib.h"


@protocol UILibCreateObjectViewDelegate <NSObject>
@required
- (UIView*) createObjectView:(NSString*)tagname attributes:(NSDictionary*)attributes;
@end

#define BEGIN_CREATE_VIEW - (UIView*)createObjectView:(NSString*)tagname attributes:(NSDictionary*)attributes{
#define END_CREATE_VIEW return nil;}

#define CREATE_CLASS_LEVEL(_NAME_,_CLASS_) if(isEqualIgnoreCase(tagname,@#_NAME_)) return _CLASS_;
#define CREATE_ALLOC_ONLY(_NAME_,_CLASS_) if(isEqualIgnoreCase2(tagname,@#_NAME_,@#_CLASS_)){ UIView* v=[_CLASS_ alloc];return v;}
#define CREATE_ALLOC_INIT(_NAME_,_CLASS_) if(isEqualIgnoreCase2(tagname,@#_NAME_,@#_CLASS_)){ UIView* v=[_CLASS_ new];v.userInteractionEnabled=YES;return v;}
#define CREATE_ALLOC_INIT_HITEST(_NAME_,_CLASS_,_HITEST_) if(isEqualIgnoreCase2(tagname,@#_NAME_,@#_CLASS_)){ UIView* v=[_CLASS_ new];v.userInteractionEnabled=_HITEST_;return v;}
#define CREATE_ALLOC_INIT_HITEST_OR(_NAME_,_OR_NAME_,_CLASS_,_HIT_) if(isEqualIgnoreCase(tagname,@#_NAME_) || isEqualIgnoreCase2(tagname,@#_OR_NAME_,@#_CLASS_)){ UIView* v=[_CLASS_ new];v.userInteractionEnabled=_HIT_;return v;}

@interface UILibFactory : NSObject
{
    
}
    
@property (weak, nonatomic) id <UILibCreateObjectViewDelegate> delegate;


+ (UILibFactory*)inst;
+ (UIView*)createObject:(NSString*)tagname attributes:(NSDictionary*)attributes;

@end
