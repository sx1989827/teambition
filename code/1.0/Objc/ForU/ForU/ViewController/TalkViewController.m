//
//  TalkViewController.m
//  ForU
//
//  Created by 孙昕 on 15/2/11.
//  Copyright (c) 2015年 孙昕. All rights reserved.
//

#import "TalkViewController.h"
#import "AppDelegate.h"
#import "FUPublic.h"
#import "FUListView.h"
#import "FUAlertView.h"
#define kEye 0
#define KBody 1
#define KTalk 2
@interface TalkViewController ()
{
    NSMutableArray *arrAction;
}
@end

@implementation TalkViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [[NSNotificationCenter defaultCenter] postNotificationName:MSGUPDATE object:nil];
    arrAction=[[NSMutableArray alloc] initWithCapacity:30];
    [arrAction addObject:@{
                    @"text":@"眼神",
                    @"id":@(kEye)
                     }];
    [arrAction addObject:@{
                     @"text":@"肢体",
                     @"id":@(KBody)
                     }];
    [arrAction addObject:@{
                     @"text":@"语言",
                     @"id":@(KTalk)
                     }];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(void)viewWillAppear:(BOOL)animated
{
    [_imgBack setPlaceImg:[APP GetPlace]];
    [_imgGirl setGirlImg:[APP GetGirlMood]];
}

-(BOOL)prefersStatusBarHidden
{
    return YES;
}

- (IBAction)onAction:(id)sender
{
    FUListView *view=[[FUListView alloc] init];
    [view addDataFromArray:arrAction];
    [view showInView:self.view];
    [view setSelectedBlock:^(long index, NSArray *arr) {
        int id=[arr[index][@"id"] intValue];
        [arrAction removeObjectAtIndex:index];
        switch(id)
        {
            case kEye:
            {
                break;
            }
            case KBody:
            {
                break;
            }
            case KTalk:
            {
                break;
            }
        }
    }];
}

- (IBAction)onQuit:(id)sender
{
    [self.navigationController popViewControllerAnimated:NO];
}
@end











