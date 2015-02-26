//
//  FUListView.m
//  ForU
//
//  Created by 孙昕 on 14/12/17.
//  Copyright (c) 2014年 孙昕. All rights reserved.
//

#import "FUListView.h"
#import <QuartzCore/QuartzCore.h>
#import <pop/POP.h>
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
        UIImageView *img=[[UIImageView alloc] initWithFrame:_tableView.bounds];
        img.image=[UIImage imageNamed:@"listback.jpg"];
        _tableView.backgroundView=img;
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
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        POPBasicAnimation *aniShow=[POPBasicAnimation animationWithPropertyNamed:kPOPViewAlpha];
        aniShow.fromValue=@0;
        aniShow.toValue=@1;
        [self pop_addAnimation:aniShow forKey:@"aniShow"];
        POPSpringAnimation *aniFrame=[POPSpringAnimation animationWithPropertyNamed:kPOPViewFrame];
        aniFrame.springBounciness=10;
        aniFrame.fromValue=[NSValue valueWithCGRect:CGRectMake(self.tableView.center.x, self.tableView.center.y, 0, 0)];
        aniFrame.toValue=[NSValue valueWithCGRect:self.tableView.frame];
        [self.tableView pop_addAnimation:aniFrame forKey:@"aniFrame"];
    });
    
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
        //cell.contentView.backgroundColor=[UIColor colorWithRed:200.0/255 green:244.0/255 blue:251.0/255 alpha:1];
        cell.backgroundColor=[UIColor clearColor];
        cell.contentView.backgroundColor=[UIColor clearColor];
        [cell setSelectionStyle:UITableViewCellSelectionStyleNone];
        UILabel *title=[[UILabel alloc] init];
        title.backgroundColor=[UIColor colorWithRed:255.0/255 green:230.0/255 blue:190.0/255 alpha:1];
        title.tag=100;
        title.translatesAutoresizingMaskIntoConstraints=NO;
        [cell.contentView addSubview:title];
        [title.layer setMasksToBounds:YES];
        [title.layer setCornerRadius:10.0];
        [title.layer setBorderWidth:0.5];
        [cell.contentView addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"|-5-[title]-5@750-|" options:0 metrics:nil views:NSDictionaryOfVariableBindings(title)]];
        [cell.contentView addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:|-3-[title(30)]-3-|" options:0 metrics:nil views:NSDictionaryOfVariableBindings(title)]];
    }
    UILabel *lbText=((UILabel*)[cell.contentView viewWithTag:100]);
    lbText.textAlignment=NSTextAlignmentCenter;
    lbText.text=arrTitle[indexPath.row][@"text"];
    return cell;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    if(blockSelected)
    {
        blockSelected(indexPath.row,arrTitle);
    }
    [self removeFromSuperview];
   
}


-(void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
    if(blockCancelled)
    {
        blockCancelled();
    }
    [self removeFromSuperview];
}

-(void)setSelectedBlock:(void (^)(long index,NSArray* arr))block
{
    blockSelected=block;
}

-(void)addDataFromArray:(NSArray*)arr
{
    [arrTitle addObjectsFromArray:arr];
}

-(void)setBlockCancelled:(void (^)())block
{
    blockCancelled=block;
}

@end










