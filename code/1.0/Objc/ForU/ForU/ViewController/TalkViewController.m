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
#import "ChangeValueView.h"
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
    if(arrAction.count==0)
    {
        __weak TalkViewController *weakSelf=self;
        FUAlertView *view=[[FUAlertView alloc] initWithMsgBlock:@"您已经完成所有动作，请结束当前交互!" Block:^{
            [weakSelf onQuit:nil];
        }];
        [view showInView:self.view];
        return;
    }
    FUListView *view=[[FUListView alloc] init];
    [view addDataFromArray:arrAction];
    [view showInView:self.view];
    [view setSelectedBlock:^(long index, NSArray *arr) {
        int type=[arr[index][@"id"] intValue];
        switch(type)
        {
            case kEye:
            {
                UITapGestureRecognizer *tap=[[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(actionTap:)];
                tap.numberOfTapsRequired=1;
                [self.view addGestureRecognizer:tap];
                UILongPressGestureRecognizer *tapLong=[[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(actionTapLong:)];
                [self.view addGestureRecognizer:tapLong];
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

-(void)actionTap:(UITapGestureRecognizer*)tap
{
    CGPoint p=[tap locationInView:self.view];
    [self handleEye:p FaceEye:LOOKFACE BreastEye:LOOKBREAST];
}

-(void)actionTapLong:(UILongPressGestureRecognizer*)tapLong
{
    CGPoint p=[tapLong locationInView:self.view];
    [self handleEye:p FaceEye:GAZEFACE BreastEye:GAZEBREAST];
}

-(void)handleEye:(CGPoint)p FaceEye:(ACTIONEYETYPE)faceEye BreastEye:(ACTIONEYETYPE)breastEye
{
    NSString *oldMood=[APP GetGirlMoodDes];
    double oldIOI=[[APP GetGirlIOI] doubleValue];
    BOOL bHandle=NO;
    if(CGRectContainsPoint([APP GetGirlFaceRect], p))
    {
        bHandle=YES;
        if(![APP HandleActionEye:faceEye])
        {
            FUAlertView *view=[[FUAlertView alloc] initWithMsg:@"很遗憾，她没有注意到你得举动!"];
            [view showInView:self.view];
        }
    }
    else if(CGRectContainsPoint([APP GetGirlBreastRect], p))
    {
        bHandle=YES;
        if(![APP HandleActionEye:breastEye])
        {
            FUAlertView *view=[[FUAlertView alloc] initWithMsg:@"很遗憾，她没有注意到你得举动!"];
            [view showInView:self.view];
        }
        
    }
    if(bHandle)
    {
        double newIOI=[[APP GetGirlIOI] doubleValue];
        double off=newIOI-oldIOI;
        NSString *strText=[NSString stringWithFormat:@"好感度:%+.2lf",off];
        BOOL bGrow=YES;
        if(off>0.000001)
        {
            bGrow=YES;
            [ChangeValueView viewWithTitle:p Title:strText View:self.view Grow:YES];
        }
        else if(off<-0.000001)
        {
            bGrow=NO;
            [ChangeValueView viewWithTitle:p Title:strText View:self.view Grow:NO];
        }
        NSString *newMood=[APP GetGirlMoodDes];
        if(![newMood isEqualToString:oldMood])
        {
            dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
                [ChangeValueView viewWithTitle:p Title:newMood View:self.view Grow:bGrow];
            });
        }
        [arrAction removeObject:@{
                                  @"text":@"眼神",
                                  @"id":@(kEye)
                                  }];
        for(UIGestureRecognizer *ges in self.view.gestureRecognizers)
        {
            [self.view removeGestureRecognizer:ges];
        }
    }

}
@end











