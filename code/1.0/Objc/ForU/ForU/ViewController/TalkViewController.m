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
    NSMutableDictionary *dicActionBody;
}
@end

@implementation TalkViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(changeGirlMood) name:MSGMOODCHANGE object:nil];
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
    dicActionBody=[[NSMutableDictionary alloc] initWithCapacity:30];
    [dicActionBody setObject:NSStringFromSelector(@selector(actionCommonBody:)) forKey:@(PATSHOULDER)];
}

-(void)actionCommonBody:(NSNumber*)type
{
    double oldValue=[[APP GetGirlIOI] doubleValue];
    [APP HandleActionBody:(ACTIONBODYTYPE)[type integerValue]];
    double newValue=[[APP GetGirlIOI] doubleValue];
    [FUPublic showChangeView:@"好感度：" Offset:(newValue-oldValue) View:self.view Point:CGPointMake(self.view.center.x+10,self.view.center.y-100)];
}


-(void)changeGirlMood
{
    [_imgGirl setGirlImg:[APP GetGirlMood]];
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
    for(UIGestureRecognizer *ges in self.view.gestureRecognizers)
    {
        [self.view removeGestureRecognizer:ges];
    }
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
                [self showActionBody];
                break;
            }
            case KTalk:
            {
                [self showActionTalk];
                break;
            }
        }
    }];
}

-(void)showActionTalk
{
    FUListView *view=[[FUListView alloc] init];
    NSArray *arr=[APP GetAvalibleTalkAction];
    if(arr.count==0)
    {
        FUAlertView *alert=[[FUAlertView alloc] initWithMsg:@"没有可选的选项哦！"];
        [alert showInView:self.view];
        return;
    }
    [view addDataFromArray:arr];
    [view showInView:self.view];
    [view setSelectedBlock:^(long index, NSArray *arr) {
        [self actionTalk:arr[index][@"text"]];
        [arrAction removeObject:@{
                                  @"text":@"语言",
                                  @"id":@(KTalk)
                                  }];
    }];

}

-(void)actionTalk:(NSString*)title
{
    double oldValue=[[APP GetGirlIOI] doubleValue];
    [APP HandleActionTalk:title];
    double newValue=[[APP GetGirlIOI] doubleValue];
    [FUPublic showChangeView:@"好感度：" Offset:(newValue-oldValue) View:self.view Point:CGPointMake(self.view.center.x+10,self.view.center.y-100)];
}

-(void)showActionBody
{
    FUListView *view=[[FUListView alloc] init];
    NSArray *arr=[APP GetAvalibleBodyAction];
    if(arr.count==0)
    {
        FUAlertView *alert=[[FUAlertView alloc] initWithMsg:@"没有可选的选项哦！"];
        [alert showInView:self.view];
        return;
    }
    [view addDataFromArray:arr];
    [view showInView:self.view];
    [view setSelectedBlock:^(long index, NSArray *arr) {
       [self performSelector:NSSelectorFromString(dicActionBody[arr[index][@"id"]]) withObject:arr[index][@"id"]];
        [arrAction removeObject:@{
                                 @"text":@"肢体",
                                 @"id":@(KBody)
                                 }];
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
        [FUPublic showChangeView:@"好感度:" Offset:off View:self.view Point:p];
        NSString *newMood=[APP GetGirlMoodDes];
        if(![newMood isEqualToString:oldMood])
        {
            [_viewTalk setGirlContentText:newMood AfterDiss:2];
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

-(void)dealloc
{
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}
@end











