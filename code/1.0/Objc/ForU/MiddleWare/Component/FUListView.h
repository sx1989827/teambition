//
//  FUListView.h
//  ForU
//
//  Created by 孙昕 on 14/12/17.
//  Copyright (c) 2014年 孙昕. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface FUListView : UIView<UITableViewDataSource,UITableViewDelegate>
{
    NSMutableArray *arrTitle;
    void (^blockSelected)(long index,NSArray* arr);
    void (^blockCancelled)();
}
@property (strong, nonatomic) IBOutlet UITableView *tableView;
-(void)showInView:(UIView*)view;
-(void)addDataFromArray:(NSArray*)arr;
-(void)setSelectedBlock:(void (^)(long index,NSArray* arr))block;
-(void)setBlockCancelled:(void (^)())block;
@end
