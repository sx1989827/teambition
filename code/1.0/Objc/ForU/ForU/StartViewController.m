//
//  StartViewController.m
//  ForU
//
//  Created by 孙昕 on 14/12/16.
//  Copyright (c) 2014年 孙昕. All rights reserved.
//

#import "StartViewController.h"
#import "FUAlertView.h"
#import "FUListView.h"
#import "FULoadingView.h"
#import "FUPhotoView.h"
@interface StartViewController ()

@end

@implementation StartViewController

- (void)viewDidLoad {
    [super viewDidLoad];

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

- (IBAction)click:(id)sender {
    FUPhotoView *view=[[FUPhotoView alloc] init];
    [view addPhoto:@"123"];
    [view showInView:self.view];
}
@end















