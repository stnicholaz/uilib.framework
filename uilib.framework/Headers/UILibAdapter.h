//
//  HomeTableAdapter.h
//
//  Created by  on 16/4/20.
//
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "UILibManager.h"

#define ADAPTER_ITEM_TYPE_NORMAL 0
#define ADAPTER_ITEM_TYPE_HEADER 1
#define ADAPTER_ITEM_TYPE_FOOTER 2
#define ADAPTER_ITEM_TYPE_EMPTY  3

#define ADAPTER_HOLDER_UI(CELL_HOLDER_CLASS,UINAME) -(CellHolder*)didCreateCellHolder:(UITableView*)tableView cell:(UITableViewCell*)tableViewCell row:(NSInteger)position cellRect:(CGRect)rect{ return [[CELL_HOLDER_CLASS alloc] initWithView:tableViewCell.contentView uiname:@#UINAME cellRect:rect];}


//---------

@interface UILibAdapter : NSObject
{
}
@property(nonatomic,strong,readonly) NSMutableArray* dataArray;
@property(nonatomic,readonly) NSInteger dataCount;


- (NSObject*)dataFromIndex:(NSInteger)index;
- (void)setDataArray:(NSArray*)data;
- (void)addDataArray:(NSArray*)data;
- (void)addData:(NSObject*)obj;
- (void)insertData:(NSObject*)obj indexTo:(NSInteger)index;
- (void)insertDataArray:(NSArray*)data indexTo:(NSInteger)index;
- (void)moveDataIndex:(NSInteger)indexFrom to:(NSInteger)indexTo;
- (void)updateData;
- (void)clear;
//for child to override
- (void)didDataChanged;
@end

//---------

@interface CellHolder : NSObject
{
    
}
@property(retain,readonly) UILibManager* ui;
@property(retain) UIView* cell;
@property(nonatomic,copy) NSString* identifier;
//@property(nonatomic,retain) UIColor* backgroundColor;
@property(nonatomic,retain) UIColor* selectedBackgroundColor;
@property(nonatomic,assign) UITableViewCellSelectionStyle selectionStyle;

+ (id)inflate:(Class)className contentView:(UIView*)cellContentView uiname:(NSString*)name cellRect:(CGRect)rect;

- (id)initWithView:(UIView*)view;
- (id)initWithView:(UIView*)view uiname:(NSString*)name cellRect:(CGRect)rect;
//- (void)onHolderCreated:(UIView*)contentView;
//- (CGFloat)heightOfCell;
@end

//---------

typedef void(^didSelectRowBlock)(NSInteger);
typedef void(^didViewClickedBlock)(NSInteger,UIView*);

@interface UILibTableAdapter : UILibAdapter <UITableViewDataSource,UITableViewDelegate>

@property(nonatomic,weak) UITableView* tableView;
@property(nonatomic,retain) UIView* headerView;
@property(nonatomic,retain) UIView* footerView;
@property(nonatomic,retain) UIView* emptyView;
@property(nonatomic,assign) UITableViewCellSelectionStyle selectionStyle;
@property(nonatomic,assign) BOOL cellUserInteractionEnabled;
@property(nonatomic,retain) UIColor* cellSelectedBackgroundColor;
@property(nonatomic,copy) didSelectRowBlock didSelectRowAtPosition;
@property(nonatomic,copy) didSelectRowBlock didLongPressedRowAtPosition;

- (id)initWithTableView:(UITableView*)tableview;
//- (CellHolder*)didCreateCellHolder:(UITableView*)tableView cell:(UITableViewCell*)tableViewCell row:(NSInteger)position cellRect:(CGRect)rect;
//- (void)onBindCellHolder:(CellHolder*)cellview row:(NSInteger)position;
//- (NSString*)identifierByRow:(NSInteger)position;
//- (CGFloat)heightOfCellByRow:(NSInteger)position;
//- (NSInteger)numberOfRows;
- (CellHolder*)holderOfRow:(NSInteger)position;
- (NSInteger)dataIndexOfPosition:(NSInteger)position;
- (void)setEditActions:(NSArray<UITableViewRowAction*>*)editActions;
@end


