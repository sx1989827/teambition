//
//  ChooseGirlViewController.m
//  ForU
//
//  Created by 孙昕 on 15/1/10.
//  Copyright (c) 2015年 孙昕. All rights reserved.
//

#import "ChooseGirlViewController.h"
#import "AddressMapViewController.h"
#import "FUPhotoView.h"
#import "AppDelegate.h"
#import "FUAlertView.h"
#import "StateViewController.h"
@interface ChooseGirlViewController ()<UITextFieldDelegate>

@end

@implementation ChooseGirlViewController

- (void)viewDidLoad {
    [super viewDidLoad];
//        FUPhotoView *view=[[FUPhotoView alloc] init];
//    NSString *strPath= [APP GetStartStory];
//    [view addPhoto:strPath];
//    [view showInView:self.view];
    _cood.latitude=100;
    _cood.longitude=100;
    _txtName.text=@"asd";
    [_btnAddress setTitle:@"已选择" forState:UIControlStateNormal];
}

-(void)viewWillAppear:(BOOL)animated
{
    UIImageView *viewLoli=[[UIImageView alloc] initWithFrame:CGRectMake(0, 0, _scvGirl.frame.size.width, _scvGirl.frame.size.height)];
    NSString *filePath = [[NSBundle mainBundle] pathForResource:@"loli" ofType:@"png"];
    NSData *image = [NSData dataWithContentsOfFile:filePath];
    viewLoli.image=[UIImage imageWithData:image];
    viewLoli.autoresizingMask=UIViewAutoresizingFlexibleWidth|UIViewAutoresizingFlexibleHeight|UIViewAutoresizingFlexibleLeftMargin|UIViewAutoresizingFlexibleRightMargin;
    UIImageView *viewMaid=[[UIImageView alloc] initWithFrame:CGRectMake(_scvGirl.frame.size.width, 0, _scvGirl.frame.size.width, _scvGirl.frame.size.height)];
    filePath = [[NSBundle mainBundle] pathForResource:@"maid" ofType:@"png"];
    image = [NSData dataWithContentsOfFile:filePath];
    viewMaid.image=[UIImage imageWithData:image];
    viewMaid.autoresizingMask=UIViewAutoresizingFlexibleWidth|UIViewAutoresizingFlexibleHeight|UIViewAutoresizingFlexibleLeftMargin|UIViewAutoresizingFlexibleRightMargin;
    UIImageView *viewQueen=[[UIImageView alloc] initWithFrame:CGRectMake(_scvGirl.frame.size.width*2, 0, _scvGirl.frame.size.width, _scvGirl.frame.size.height)];
    filePath = [[NSBundle mainBundle] pathForResource:@"queen" ofType:@"png"];
    image = [NSData dataWithContentsOfFile:filePath];
    viewQueen.image=[UIImage imageWithData:image];
    viewQueen.autoresizingMask=UIViewAutoresizingFlexibleWidth|UIViewAutoresizingFlexibleHeight|UIViewAutoresizingFlexibleLeftMargin|UIViewAutoresizingFlexibleRightMargin;
    [_scvGirl addSubview:viewLoli];
    [_scvGirl addSubview:viewMaid];
    [_scvGirl addSubview:viewQueen];
    UITapGestureRecognizer *tap=[[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(hiddenKeyboard:)];
    [self.view addGestureRecognizer:tap];

}

-(void)viewWillDisappear:(BOOL)animated
{
    for(UIView * view in _scvGirl.subviews)
    {
        [view removeFromSuperview];
    }
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
- (IBAction)onStart:(id)sender {
    if([[_btnAddress titleForState:UIControlStateNormal] isEqualToString:@"选择您的住址"])
    {
        FUAlertView *view=[[FUAlertView alloc] initWithMsg:@"请选择您的住址"];
        [view showInView:self.view];
        return;
    }
    else if([_txtName.text isEqualToString:@""])
    {
        FUAlertView *view=[[FUAlertView alloc] initWithMsg:@"请输入女生的名字"];
        [view showInView:self.view];
        return;
    }
    GIRLTYPE type=(GIRLTYPE)(_scvGirl.contentOffset.y/_scvGirl.frame.size.width);
    [APP Reset:type girlname:_txtName.text x:_cood.latitude y:_cood.longitude];
    StateViewController *view=[[StateViewController alloc] initWithNibName:@"StateViewController" bundle:nil];
    [self.navigationController pushViewController:view animated:NO];
}
@end










