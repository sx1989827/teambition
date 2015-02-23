//
//  GiftView.m
//  ForU
//
//  Created by 孙昕 on 15/2/22.
//  Copyright (c) 2015年 孙昕. All rights reserved.
//

#import "GiftView.h"
#import <pop/POP.h>
#import "GiftCell.h"
#import "FUPublic.h"
#import "AppDelegate.h"
#import "MsgShowView.h"
@interface GiftView()<UITableViewDelegate,UITableViewDataSource>
{
    UITableView *viewTable;
    NSArray *arrData;
}
@end
@implementation GiftView
-(id)init
{
    if(self=[super init])
    {
        viewTable=[[UITableView alloc] initWithFrame:CGRectMake(0, 0, self.frame.size.width, self.frame.size.height)];
        viewTable.delegate=self;
        viewTable.dataSource=self;
        viewTable.separatorStyle=UITableViewCellSeparatorStyleNone;
        viewTable.frame=CGRectMake(0, 0, 280, 360);
        [self addSubview:viewTable];
    }
    return self;
}

-(void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
    [self removeFromSuperview];
}

-(void)showInView:(UIView*)view
{
    self.frame=view.bounds;
    self.autoresizingMask=UIViewAutoresizingFlexibleWidth|UIViewAutoresizingFlexibleHeight;
    self.backgroundColor=[UIColor colorWithRed:1 green:1 blue:1 alpha:0.8];
    viewTable.center=self.center;
    CGRect frame=viewTable.frame;
    viewTable.frame=CGRectMake(self.center.x, self.center.y, 0, 0);
    viewTable.alpha=0;
    arrData=[APP GetAvalibleGift];
    [viewTable reloadData];
    viewTable.backgroundColor=[UIColor clearColor];
    [view addSubview:self];
    POPBasicAnimation *aniShow=[POPBasicAnimation animationWithPropertyNamed:kPOPViewAlpha];
    aniShow.toValue=@1;
    [viewTable pop_addAnimation:aniShow forKey:@"aniShow"];
    POPSpringAnimation *aniFrame=[POPSpringAnimation animationWithPropertyNamed:kPOPViewFrame];
    aniFrame.springBounciness=10;
    aniFrame.toValue=[NSValue valueWithCGRect:frame];
    [viewTable pop_addAnimation:aniFrame forKey:@"aniFrame"];
}

-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return arrData.count;
}

-(CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 60;
}

-(UITableViewCell*)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    GiftCell *cell=[tableView dequeueReusableCellWithIdentifier:@"GiftCell"];
    if(cell==nil)
    {
        cell=(GiftCell*)[[[NSBundle mainBundle] loadNibNamed:@"GiftCell" owner:nil options:nil] lastObject ];
        cell.selectionStyle=UITableViewCellSelectionStyleNone;
        cell.backgroundColor=[UIColor colorWithRed:200.0/255 green:244.0/255 blue:251.0/255 alpha:1];
        [cell.contentView.layer setMasksToBounds:YES];
        [cell.contentView.layer setCornerRadius:10.0];
        [cell.contentView.layer setBorderWidth:0.5];
        cell.contentView.backgroundColor=[UIColor colorWithRed:255.0/255 green:230.0/255 blue:190.0/255 alpha:1];
    }
    [cell.imgGift setGiftImg:arrData[indexPath.row][@"title"]];
    cell.lbName.text=arrData[indexPath.row][@"title"];
    cell.lbPrice.text=[arrData[indexPath.row][@"price"] stringValue];
    return cell;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    NSDictionary *dic=[APP HandleGift:arrData[indexPath.row][@"title"]];
    if([dic[@"status"] isEqualToString:@"success"])
    {
        [MsgShowView showTitleInView:@"购买成功！" View:self.superview];
        [self removeFromSuperview];
    }
    else
    {
        [MsgShowView showTitleInView:dic[@"error"] View:self.superview];
        [self removeFromSuperview];
    }
}

@end













