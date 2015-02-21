//
//  DateViewController.m
//  ForU
//
//  Created by 孙昕 on 15/2/16.
//  Copyright (c) 2015年 孙昕. All rights reserved.
//

#import "DateViewController.h"
#import "FUPublic.h"
#import "AppDelegate.h"
#import "FUListView.h"
#import "FUAlertView.h"
#import "MsgShowView.h"
#import "TalkViewController.h"
@interface DateViewController ()

@end

@implementation DateViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [_imgBack setPlaceImg:[APP GetPlace]];
    FUListView *view=[[FUListView alloc] init];
    [view addDataFromArray:@[
                             @{
                                 @"text":@"吃饭",
                                 @"id":@(EAT)
                                 },
                             @{
                                 @"text":@"看电影",
                                 @"id":@(FILM)
                                 },
                             @{
                                 @"text":@"公园",
                                 @"id":@(WALK)
                                 },
                             @{
                                 @"text":@"游乐场",
                                 @"id":@(PARK)
                                 }
                             ]];
    [view showInView:self.view];
    __weak DateViewController* weakSelf=self;
    [view setBlockCancelled:^{
        [weakSelf.navigationController popViewControllerAnimated:NO];
    }];
    [view setSelectedBlock:^(long index, NSArray *arr) {
        [weakSelf actionDate:(DATETYPE)[arr[index][@"id"] integerValue]];
    }];
}

-(void)actionDate:(DATETYPE)type
{
    if([APP TryEnterInteraction:_dateType DateType:type])
    {
        [APP EnterInteraction:_dateType DateType:type];
        NSArray *arr=@[@"餐厅",@"电影院",@"公园",@"游乐场"];
        [_imgBack setPlaceImg:arr[type]];
        [MsgShowView showTitleInView:@"进入约会模式" View:self.view];
    }
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


- (IBAction)onAction:(id)sender
{
    TalkViewController *view=[[TalkViewController alloc] initWithNibName:@"TalkViewController" bundle:nil];
    [self.navigationController pushViewController:view animated:NO];
}

- (IBAction)onQuit:(id)sender
{
    __weak DateViewController* weakSelf=self;
    FUAlertView *view=[[FUAlertView alloc] initWithChoose:@"是否结束约会?" First:@"是" Second:@"否" FirstBlock:^{
        [APP LeaveInteraction];
        [weakSelf.navigationController popViewControllerAnimated:NO];
    } SecondBlock:^{
    }];
    [view showInView:self.view];
    
}

-(BOOL)prefersStatusBarHidden
{
    return YES;
}
@end







