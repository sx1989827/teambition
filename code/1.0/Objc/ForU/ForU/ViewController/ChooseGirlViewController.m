//
//  ChooseGirlViewController.m
//  ForU
//
//  Created by 孙昕 on 15/1/10.
//  Copyright (c) 2015年 孙昕. All rights reserved.
//

#import "ChooseGirlViewController.h"
#import "AddressMapViewController.h"
@interface ChooseGirlViewController ()<UITextFieldDelegate>

@end

@implementation ChooseGirlViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    UIImageView *viewLoli=[[UIImageView alloc] initWithFrame:CGRectMake(0, 0, _scvGirl.frame.size.width, _scvGirl.frame.size.height)];
    viewLoli.image=[UIImage imageNamed:@"loli"];
    viewLoli.autoresizingMask=UIViewAutoresizingFlexibleWidth|UIViewAutoresizingFlexibleHeight|UIViewAutoresizingFlexibleLeftMargin|UIViewAutoresizingFlexibleRightMargin;
    UIImageView *viewMaid=[[UIImageView alloc] initWithFrame:CGRectMake(_scvGirl.frame.size.width, 0, _scvGirl.frame.size.width, _scvGirl.frame.size.height)];
    viewMaid.image=[UIImage imageNamed:@"maid"];
    viewMaid.autoresizingMask=UIViewAutoresizingFlexibleWidth|UIViewAutoresizingFlexibleHeight|UIViewAutoresizingFlexibleLeftMargin|UIViewAutoresizingFlexibleRightMargin;
    UIImageView *viewQueen=[[UIImageView alloc] initWithFrame:CGRectMake(_scvGirl.frame.size.width*2, 0, _scvGirl.frame.size.width, _scvGirl.frame.size.height)];
    viewQueen.image=[UIImage imageNamed:@"queen"];
    viewQueen.autoresizingMask=UIViewAutoresizingFlexibleWidth|UIViewAutoresizingFlexibleHeight|UIViewAutoresizingFlexibleLeftMargin|UIViewAutoresizingFlexibleRightMargin;
    [_scvGirl addSubview:viewLoli];
    [_scvGirl addSubview:viewMaid];
    [_scvGirl addSubview:viewQueen];
    UITapGestureRecognizer *tap=[[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(hiddenKeyboard:)];
    [self.view addGestureRecognizer:tap];
}

-(void)viewDidAppear:(BOOL)animated
{
    _scvGirl.contentSize=CGSizeMake(_scvGirl.frame.size.width*3, _scvGirl.frame.size.height);
}

-(void)hiddenKeyboard:(UIGestureRecognizer*)tap
{
    [self.view endEditing:YES];
}

-(BOOL)textFieldShouldReturn:(UITextField *)textField
{
    [self.view endEditing:YES];
    return YES;
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (BOOL)prefersStatusBarHidden
{
    return YES;
}

- (IBAction)onAdress:(id)sender {
    AddressMapViewController *view=[[AddressMapViewController alloc] initWithNibName:@"AddressMapViewController" bundle:nil];
    view.vc=self;
    [self presentViewController:view animated:YES completion:nil];
}
@end










