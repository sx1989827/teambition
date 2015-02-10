//
//  StateViewController.m
//  ForU
//
//  Created by 孙昕 on 15/1/25.
//  Copyright (c) 2015年 孙昕. All rights reserved.
//

#import "StateViewController.h"

@interface StateViewController ()

@end

@implementation StateViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    _viewHeader.lPhysical=100;
    _viewHeader.lMoney=500;
    _viewHeader.mood=@"开心";
    _viewHeader.lIOI=80;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (BOOL)prefersStatusBarHidden
{
    return YES;
}

@end
