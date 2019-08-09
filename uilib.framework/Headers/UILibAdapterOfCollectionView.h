//
//  UILibAdapterOfCollectionView.h
//  Client
//
//  Created by Apple on 2018/9/8.
//  Copyright © 2018年 rc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "UILibManager.h"
#import "UILibAdapter.h"


/**************************************************************/
/**************************************************************/



@interface UILibColletcionViewCell : UICollectionViewCell

//@property (strong, nonatomic) UIImageView* imageView;

@end

//======================

//@interface ColletcionCellHolder : CellHolder
//
//@end

//==========================


@interface UILibAdapterOfCollectionView : UILibAdapter<UICollectionViewDelegate,UICollectionViewDataSource,UICollectionViewDelegateFlowLayout>

@property(nonatomic,weak) UIViewController* viewController;
@property(nonatomic,weak) UICollectionView* collectionView;
@property(nonatomic,copy) didSelectRowBlock didSelectRowAtPosition;
@property(nonatomic,copy) didSelectRowBlock didLongPressedRowAtPosition;
@property(nonatomic,readonly) CGSize sizeOfCell;

- (id)initWithCollectionView:(UICollectionView*)collectionView;
- (id)initWithCollectionView:(UICollectionView*)collectionView viewSize:(CGSize)viewSize columns:(NSUInteger)columns;
- (id)initWithCollectionView:(UICollectionView*)collectionView itemSize:(CGSize)itemSize;

//- (NSString*)identifierByRow:(NSInteger)position;
//- (CellHolder*)didCreateCellHolder:(UICollectionView*)collectionView cell:(UICollectionViewCell*)cell row:(NSInteger)position cellRect:(CGRect)rect;
//- (void)onBindCellHolder:(CellHolder*)cellHolder row:(NSInteger)position;
@end
