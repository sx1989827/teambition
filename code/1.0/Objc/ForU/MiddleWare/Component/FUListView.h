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
    void (^blockSelected)(long index,NSString* title);
}
@property (strong, nonatomic) IBOutlet UITableView *tableView;
-(void)showInView:(UIView*)view;
-(void)addData:(NSString*)title;
-(void)setSelectedBlock:(void (^)(long index,NSString* title))block;
@end
