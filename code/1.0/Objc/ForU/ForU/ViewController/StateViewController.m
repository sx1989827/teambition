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
#import "FUAlertView.h"
#import "TalkViewController.h"
#import "DateViewController.h"
#import "GiftView.h"
#import "DatePickerView.h"
#import "MsgShowView.h"
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
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(resignActive) name:UIApplicationWillResignActiveNotification object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(enterForeground) name:UIApplicationWillEnterForegroundNotification object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(msgDateItemEnd) name:MSGDATEITEMEND object:nil];
}

-(void)msgDateItemEnd
{
    
    if(self.navigationController.topViewController!=self)
    {
        [MsgShowView showTitleInView:@"约会已经结束了！"];
        [self.navigationController popToViewController:self animated:NO];
    }
}

-(void)resignActive
{
    
}

-(void)enterForeground
{
    [imgBack startGif];
}

-(void)dealloc
{
    [[NSNotificationCenter defaultCenter] removeObserver:self];
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
        [APP RemoveNotify];
        SvGifView *view=[weakSelf valueForKey:@"imgBack"];
        PLAYERSTATE state=(PLAYERSTATE)[arr[index][@"id"] integerValue];
        if(state==SLEEP)
        {
            weakSelf.btnAction.hidden=YES;
            weakSelf.conTitleTop.constant=-weakSelf.btnAction.frame.size.height;
            [weakSelf.view layoutIfNeeded];
            [weakSelf showCall];
        }
        else
        {
            weakSelf.btnAction.hidden=NO;
            weakSelf.conTitleTop.constant=24;
            [weakSelf.view layoutIfNeeded];

        }
        [view setGif:[weakSelf valueForKey:@"arrStateImg"][state] Bundle:nil];
        [weakApp ChangePlayerState:state];
    }];
}

-(void)showCall
{
    FUAlertView *viewAlert=[[FUAlertView alloc] initWithChoose:@"是否需要女主喊醒呢？" First:@"是" Second:@"否" FirstBlock:^{
        DatePickerView *view=[[DatePickerView alloc] init];
        [view showInView:self.view];
        [view setCompleteBlock:^(NSDate *date) {
            [APP CreateNotify:CALL Time:date DateType:(DATETYPE)0];
        }];
            } SecondBlock:^{
        
    }];
    [viewAlert showInView:self.view];
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
            case kDate:
            {
                DateViewController *view=[[DateViewController alloc] initWithNibName:@"DateViewController" bundle:nil];
                view.dateType=[APP GetLove]?DATELOVE:DATENOLOVE;
                [weakSelf.navigationController pushViewController:view animated:NO];
                break;
            }
            case kGift:
            {
                GiftView *view=[[GiftView alloc] init];
                [view showInView:weakSelf.view];
                break;
            }
        }
    }];

}

- (IBAction)onTitle:(id)sender
{
    __weak StateViewController* weakSelf=self;
    FUAlertView *view=[[FUAlertView alloc] initWithChoose:@"是否回到标题页面?" First:@"是" Second:@"否" FirstBlock:^{
        [APP Save];
        AppDelegate *app=(AppDelegate*)[UIApplication sharedApplication].delegate;
        [app.timerUpdate invalidate];
        app.timerUpdate=nil;
        for(UIViewController *view in weakSelf.navigationController.viewControllers)
        {
            if([view isKindOfClass:NSClassFromString(@"MainMenuViewController")])
            {
                [weakSelf.navigationController popToViewController:view animated:NO];
                break;
            }
        }
    } SecondBlock:^{
    }];
    [view showInView:self.view];
}
@end











