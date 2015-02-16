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
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


- (IBAction)onAction:(id)sender
{
    
}

- (IBAction)onQuit:(id)sender
{
    [self.navigationController popViewControllerAnimated:NO];
}

-(BOOL)prefersStatusBarHidden
{
    return YES;
}
@end







