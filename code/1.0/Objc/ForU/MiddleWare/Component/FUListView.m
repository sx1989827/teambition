//
//  FUListView.m
//  ForU
//
//  Created by 孙昕 on 14/12/17.
//  Copyright (c) 2014年 孙昕. All rights reserved.
//

#import "FUListView.h"
#import <QuartzCore/QuartzCore.h>
@implementation FUListView

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
}
*/
-(id)init
{
    if((self=[[[NSBundle mainBundle] loadNibNamed:@"FUListView" owner:self options:nil] lastObject])!=nil)
    {
        arrTitle=[[NSMutableArray alloc] initWithCapacity:30];
    }
    return self;
}

-(void)showInView:(UIView*)view
{
    self.backgroundColor=[UIColor colorWithRed:1 green:1 blue:1 alpha:0.8];
    self.translatesAutoresizingMaskIntoConstraints=NO;
    self.alpha=0;
    _tableView.estimatedRowHeight = 60.0;
    _tableView.rowHeight = UITableViewAutomaticDimension;
    [_tableView reloadData];
    [_tableView.layer setMasksToBounds:YES];
    [_tableView.layer setCornerRadius:1.0];
    [_tableView.layer setBorderWidth:0.5];
    [view addSubview:self];
    [view addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"|[self]|" options:0 metrics:nil views:NSDictionaryOfVariableBindings(self)]];
    [view addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:|[self]|" options:0 metrics:nil views:NSDictionaryOfVariableBindings(self)]];
    [UIView animateWithDuration:0.5 animations:^{
        self.alpha=1;
    }];
}

-(long)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return arrTitle.count;
}

-(UITableViewCell*)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *reuseIdetify = @"FUListViewTableCell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:reuseIdetify];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:reuseIdetify];
        cell.contentView.backgroundColor=[UIColor colorWithRed:151.0/255 green:211.0/255 blue:255.0/255 alpha:1];
        UILabel *title=[[UILabel alloc] init];
        title.backgroundColor=[UIColor colorWithRed:238.0/255 green:250.0/255 blue:150.0/255 alpha:1];
        title.tag=100;
        title.translatesAutoresizingMaskIntoConstraints=NO;
        [cell.contentView addSubview:title];
        [title.layer setMasksToBounds:YES];
        [title.layer setCornerRadius:10.0];
        [title.layer setBorderWidth:0.5];
        [cell.contentView addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"|-5-[title]-5-|" options:0 metrics:nil views:NSDictionaryOfVariableBindings(title)]];
        [cell.contentView addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:|-3-[title(30)]-3-|" options:0 metrics:nil views:NSDictionaryOfVariableBindings(title)]];
    }
    ((UILabel*)[cell.contentView viewWithTag:100]).text=arrTitle[indexPath.row];
    return cell;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    NSString *title=arrTitle[indexPath.row];
    if(blockSelected)
    {
        blockSelected(indexPath.row,title);
    }
    [self removeFromSuperview];
   
}

-(void)addData:(NSString*)title
{
    [arrTitle addObject:title];
}

-(void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
    [self removeFromSuperview];
}

-(void)setSelectedBlock:(void (^)(long index,NSString* title))block
{
    blockSelected=block;
}
@end










