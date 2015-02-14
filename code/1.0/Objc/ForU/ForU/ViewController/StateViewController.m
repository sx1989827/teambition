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
#import "TalkViewController.h"
#define kTalk 0
#define kDate 1
#define kGift 2
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
        if(state==SLEEP)
        {
            weakSelf.btnAction.hidden=YES;
        }
        else
        {
            weakSelf.btnAction.hidden=NO;
        }
        [view setGif:[weakSelf valueForKey:@"arrStateImg"][state] Bundle:nil];
        [weakApp ChangePlayerState:state];
    }];
}

- (IBAction)onAction:(id)sender
{
    NSArray *arr;
    switch([APP GetPlayerState])
    {
        case LEISURE:
        {
            arr=@[
                  @{
                      @"text":@"交流",
                      @"id":@(kTalk)
                      },
                  @{
                      @"text":@"约会",
                      @"id":@(kDate)
                      },
                  @{
                      @"text":@"送礼物",
                      @"id":@(kGift)
                      }
                  ];
            break;
        }
        case WORK:
        {
            arr=@[
                  @{
                      @"text":@"交流",
                      @"id":@(kTalk)
                      }
                  ];
            break;
        }
        default:
        {
            break;
        }
    }
    FUListView *view=[[FUListView alloc] init];
    [view addDataFromArray:arr];
    [view showInView:self.view];
    __weak StateViewController* weakSelf=self;
    __weak FUApplication* weakApp=APP;
    [view setSelectedBlock:^(long index, NSArray *arr) {
        switch([arr[index][@"id"] integerValue])
        {
            case kTalk:
            {
                TalkViewController *view=[[TalkViewController alloc] initWithNibName:@"TalkViewController" bundle:nil];
                [weakSelf.navigationController pushViewController:view animated:NO];
                break;
            }
        }
    }];

}

@end











