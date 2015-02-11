//
//  StateViewController.m
//  ForU
//
//  Created by 孙昕 on 15/1/25.
//  Copyright (c) 2015年 孙昕. All rights reserved.
//

#import "StateViewController.h"
#import "FUListView.h"
#import "AppDelegate.h"
#import "SvGifView.h"
@interface StateViewController ()
{
    SvGifView *imgBack;
    NSArray *arrStateImg;
}
@end

@implementation StateViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    arrStateImg=@[@"leisure",@"sleep",@"work"];
    _viewHeader.lPhysical=10;
    _viewHeader.lMoney=50;
    _viewHeader.mood=@"生气";
    _viewHeader.lIOI=50;
    PLAYERSTATE state=[APP GetPlayerState];
    imgBack=[[SvGifView alloc] initWithCenter:CGPointZero fileName:arrStateImg[state] Bundle:nil];
    imgBack.translatesAutoresizingMaskIntoConstraints=NO;
    [self.view addSubview:imgBack];
    [self.view sendSubviewToBack:imgBack];
    [self.view addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"|[imgBack]|" options:0 metrics:nil views:NSDictionaryOfVariableBindings(imgBack)]];
    [self.view addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:|[imgBack]|" options:0 metrics:nil views:NSDictionaryOfVariableBindings(imgBack)]];
    [imgBack startGif];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (BOOL)prefersStatusBarHidden
{
    return YES;
}

- (IBAction)onSwitch:(id)sender
{
    FUListView *view=[[FUListView alloc] init];
    NSDictionary *dicLeisure=@{
                    @"text":@"休闲",
                    @"id":@(LEISURE)
                               };
    NSDictionary *dicSleep=@{
                               @"text":@"休息",
                               @"id":@(SLEEP)
                               };
    NSDictionary *dicWork=@{
                               @"text":@"工作",
                               @"id":@(WORK)
                               };
    switch([APP GetPlayerState])
    {
        case LEISURE:
        {
            [view addDataFromArray:@[
                                     dicSleep,dicWork
                                    ]];
            break;
        }
        case SLEEP:
        {
            [view addDataFromArray:@[
                                     dicLeisure,dicWork
                                     ]];
            break;
        }
        case WORK:
        {
            [view addDataFromArray:@[
                                     dicLeisure,dicSleep
                                     ]];
            break;
        }
    }
    [view showInView:self.view];
    __weak StateViewController* weakSelf=self;
    __weak FUApplication* weakApp=APP;
    [view setSelectedBlock:^(long index, NSArray *arr) {
        SvGifView *view=[weakSelf valueForKey:@"imgBack"];
        PLAYERSTATE state=(PLAYERSTATE)[arr[index][@"id"] integerValue];
        [view setGif:[weakSelf valueForKey:@"arrStateImg"][state] Bundle:nil];
        [weakApp ChangePlayerState:state];
    }];
}

- (IBAction)onAction:(id)sender
{
    
}

@end











