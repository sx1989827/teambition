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
#import "SvGifView.h"
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
    FULoadingView *view=[[FULoadingView alloc] init];
    [view showInView:self.view];
    dispatch_time_t time=dispatch_time(DISPATCH_TIME_NOW, 5*NSEC_PER_SEC);
    dispatch_after(time, dispatch_get_main_queue(), ^{
        [view remove];
    });
}
@end















