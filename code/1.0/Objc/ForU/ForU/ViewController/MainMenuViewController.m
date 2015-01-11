//
//  MainMenuViewController.m
//  ForU
//
//  Created by 孙昕 on 14/12/28.
//  Copyright (c) 2014年 孙昕. All rights reserved.
//

#import "MainMenuViewController.h"
#include "FUPhotoView.h"
#include "AppDelegate.h"
#import "ChooseGirlViewController.h"
@interface MainMenuViewController ()

@end

@implementation MainMenuViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

- (IBAction)onNew:(id)sender {
    ChooseGirlViewController *view=[[ChooseGirlViewController alloc] initWithNibName:@"ChooseGirlViewController" bundle:nil];
    [self.navigationController pushViewController:view animated:YES];
}

- (IBAction)onLoad:(id)sender {
    
}

- (IBAction)onSetup:(id)sender {
    
}

- (BOOL)prefersStatusBarHidden
{
    return YES;
}
@end













