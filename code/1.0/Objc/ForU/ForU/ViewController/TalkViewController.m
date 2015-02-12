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
@interface TalkViewController ()

@end

@implementation TalkViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [[NSNotificationCenter defaultCenter] postNotificationName:MSGUPDATE object:nil];
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

- (IBAction)onClose:(id)sender
{
    
}

- (IBAction)onQuit:(id)sender
{
    [self.navigationController popViewControllerAnimated:NO];
}
@end











