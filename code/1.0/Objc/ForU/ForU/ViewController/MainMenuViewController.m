//
//  MainMenuViewController.m
//  ForU
//
//  Created by 孙昕 on 14/12/28.
//  Copyright (c) 2014年 孙昕. All rights reserved.
//

#import "MainMenuViewController.h"
#import "FUPhotoView.h"
#import "FULoadingView.h"
#import "AppDelegate.h"
#import "ChooseGirlViewController.h"
#import "SettingView.h"
#import <pop/POP.h>
#import "FUPublic.h"
#import "StateViewController.h"
#import "FUAlertView.h"
#import "FUSoundPlay.h"
@interface MainMenuViewController ()
{
    SettingView *viewSetting;
}
@end

@implementation MainMenuViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    viewSetting=[[SettingView alloc] init];
    viewSetting.hidden=YES;
    [self.view addSubview:viewSetting];
    [self.view addConstraint:[NSLayoutConstraint constraintWithItem:viewSetting attribute:NSLayoutAttributeCenterX relatedBy:NSLayoutRelationEqual toItem:self.view attribute:NSLayoutAttributeCenterX multiplier:1 constant:0]];
    [self.view addConstraint:[NSLayoutConstraint constraintWithItem:viewSetting attribute:NSLayoutAttributeCenterY relatedBy:NSLayoutRelationEqual toItem:self.view attribute:NSLayoutAttributeCenterY multiplier:1 constant:0]];
    [viewSetting addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"[viewSetting(240)]" options:0 metrics:nil views:NSDictionaryOfVariableBindings(viewSetting)]];
    [viewSetting addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:[viewSetting(320)]" options:0 metrics:nil views:NSDictionaryOfVariableBindings(viewSetting)]];
    
    _btnNew.alpha=0;
    _btnOld.alpha=0;
    _btnSet.alpha=0;
    POPBasicAnimation *aniNew=[POPBasicAnimation animationWithPropertyNamed:kPOPViewAlpha];
    aniNew.fromValue=@(0);
    aniNew.toValue=@(1);
    aniNew.duration=0.8;
    POPBasicAnimation *aniOld=[POPBasicAnimation animationWithPropertyNamed:kPOPViewAlpha];
    aniOld.fromValue=@(0);
    aniOld.toValue=@(1);
    aniOld.duration=0.8;
    POPBasicAnimation *aniSet=[POPBasicAnimation animationWithPropertyNamed:kPOPViewAlpha];
    aniSet.fromValue=@(0);
    aniSet.toValue=@(1);
    aniSet.duration=0.8;
    [_btnNew pop_addAnimation:aniNew forKey:@"btnNewShow"];
    [FUPublic dispatchAfter:0.4 Block:^{
        [_btnOld pop_addAnimation:aniOld forKey:@"btnOldShow"];
    }];
    [FUPublic dispatchAfter:0.8 Block:^{
        [_btnSet pop_addAnimation:aniSet forKey:@"btnSetShow"];
    }];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(void)viewWillAppear:(BOOL)animated
{
    [[FUSoundPlay shareInstance] playTitle];
}

- (IBAction)onNew:(id)sender {
    NSUserDefaults *userDefaults=[NSUserDefaults standardUserDefaults];
    if([userDefaults floatForKey:@"ver"]>0.0000001)
    {
        __weak MainMenuViewController* weakSelf=self;
        FUAlertView *view=[[FUAlertView alloc] initWithChoose:@"已经有存档，是否覆盖?" First:@"是" Second:@"否" FirstBlock:^{
            [userDefaults removeObjectForKey:@"ver"];
            ChooseGirlViewController *view=[[ChooseGirlViewController alloc] initWithNibName:@"ChooseGirlViewController" bundle:nil];
            [weakSelf.navigationController pushViewController:view animated:YES];
        } SecondBlock:^{
        }];
        [view showInView:self.view];
        return;
    }
    ChooseGirlViewController *view=[[ChooseGirlViewController alloc] initWithNibName:@"ChooseGirlViewController" bundle:nil];
    [self.navigationController pushViewController:view animated:YES];
}

- (IBAction)onLoad:(id)sender
{
    NSUserDefaults *userDefaults=[NSUserDefaults standardUserDefaults];
    if([userDefaults floatForKey:@"ver"]==0)
    {
        FUAlertView *view=[[FUAlertView alloc] initWithMsg:@"您尚未存档，请开始新的旅程!"];
        [view showInView:self.view];
        return;
    }
    [APP Reset:(GIRLTYPE)[[userDefaults valueForKey:@"type"] integerValue] girlname:[userDefaults stringForKey:@"name"] x:[userDefaults doubleForKey:@"x"] y:[userDefaults doubleForKey:@"y"]];
    [APP Load];
    AppDelegate *app=(AppDelegate*)[UIApplication sharedApplication].delegate;
    [app performSelector:@selector(initTimer)];
    StateViewController *view=[[StateViewController alloc] initWithNibName:@"StateViewController" bundle:nil];
    [self.navigationController pushViewController:view animated:NO];
    [[FUSoundPlay shareInstance] playBackMusic];
}

- (IBAction)onSetup:(id)sender {
    viewSetting.hidden=NO;
    viewSetting.alpha=0;
    POPBasicAnimation *ani=[POPBasicAnimation animationWithPropertyNamed:kPOPViewAlpha];
    ani.fromValue=@(0);
    ani.toValue=@(1);
    [viewSetting pop_addAnimation:ani forKey:@"SettingShow"];
    POPSpringAnimation *aniSpring=[POPSpringAnimation animationWithPropertyNamed:kPOPViewFrame];
    aniSpring.springBounciness=10;
    aniSpring.fromValue=[NSValue valueWithCGRect:CGRectMake(self.view.center.x, self.view.center.y, 0, 0)];
    aniSpring.toValue=[NSValue valueWithCGRect:viewSetting.frame];
    [viewSetting pop_addAnimation:aniSpring forKey:@"SettingFrame"];
}

- (BOOL)prefersStatusBarHidden
{
    return YES;
}
@end













