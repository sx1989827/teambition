//
//  FUAlertView.m
//  ForU
//
//  Created by 孙昕 on 14/12/17.
//  Copyright (c) 2014年 孙昕. All rights reserved.
//

#import "FUAlertView.h"
#import <QuartzCore/QuartzCore.h>
@implementation FUAlertView

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
}
*/

-(void)setup
{
    self.translatesAutoresizingMaskIntoConstraints=NO;
    viewTitle=[[UIView alloc] init];
    viewTitle.backgroundColor=[UIColor colorWithRed:238.0/255 green:250.0/255 blue:150.0/255 alpha:1];
    viewTitle.translatesAutoresizingMaskIntoConstraints=NO;
    lbTitle=[[UILabel alloc] init];
    lbTitle.numberOfLines=3;
    lbTitle.translatesAutoresizingMaskIntoConstraints=NO;
    btnFirst=[UIButton buttonWithType:UIButtonTypeSystem];
    [btnFirst addTarget:self action:@selector(close:) forControlEvents:UIControlEventTouchUpInside];
    btnFirst.tag=0;
    btnFirst.translatesAutoresizingMaskIntoConstraints=NO;
    [btnFirst setTitle:@"确定" forState:UIControlStateNormal];
    btnFirst.hidden=YES;
    [btnFirst.layer setMasksToBounds:YES];
    [btnFirst.layer setCornerRadius:2.0];
    [btnFirst.layer setBorderWidth:1.0];
    btnSecond=[UIButton buttonWithType:UIButtonTypeSystem];
    [btnSecond addTarget:self action:@selector(close:) forControlEvents:UIControlEventTouchUpInside];
    btnSecond.tag=1;
    btnSecond.translatesAutoresizingMaskIntoConstraints=NO;
    [btnSecond setTitle:@"取消" forState:UIControlStateNormal];
    btnSecond.hidden=YES;
    [btnSecond.layer setMasksToBounds:YES];
    [btnSecond.layer setCornerRadius:2.0];
    [btnSecond.layer setBorderWidth:1.0];
    [self addSubview:viewTitle];
    [viewTitle addSubview:lbTitle];
    [viewTitle addSubview:btnFirst];
    [viewTitle addSubview:btnSecond];
    [self addConstraint:[NSLayoutConstraint constraintWithItem:viewTitle attribute:NSLayoutAttributeCenterX relatedBy:NSLayoutRelationEqual toItem:self attribute:NSLayoutAttributeCenterX multiplier:1 constant:0]];
    [self addConstraint:[NSLayoutConstraint constraintWithItem:viewTitle attribute:NSLayoutAttributeCenterY relatedBy:NSLayoutRelationEqual toItem:self attribute:NSLayoutAttributeCenterY multiplier:1 constant:0]];
    [self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"[viewTitle(200)]" options:0 metrics:nil views:NSDictionaryOfVariableBindings(viewTitle)]];
    [self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:[viewTitle(140)]" options:0 metrics:nil views:NSDictionaryOfVariableBindings(viewTitle)]];
    [viewTitle addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"|-20-[lbTitle]-20-|" options:0 metrics:nil views:NSDictionaryOfVariableBindings(lbTitle)]];
    [viewTitle addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:|-20-[lbTitle(<=90)]" options:0 metrics:nil views:NSDictionaryOfVariableBindings(lbTitle)]];
}

-(id)initWithMsg:(NSString*)title
{
    if(self=[super init])
    {
        [self setup];
        lbTitle.text=title;
        btnFirst.hidden=NO;
        [viewTitle addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"|-70-[btnFirst]-70-|" options:0 metrics:nil views:NSDictionaryOfVariableBindings(btnFirst)]];
        [viewTitle addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:[btnFirst(20)]-5-|" options:0 metrics:nil views:NSDictionaryOfVariableBindings(btnFirst)]];
    }
    return self;
}

-(id)initWithMsgBlock:(NSString*)title Block:(void (^)())block
{
    if(self=[super init])
    {
        [self setup];
        blockFirst=block;
        lbTitle.text=title;
        btnFirst.hidden=NO;
        [viewTitle addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"|-70-[btnFirst]-70-|" options:0 metrics:nil views:NSDictionaryOfVariableBindings(btnFirst)]];
        [viewTitle addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:[btnFirst(20)]-5-|" options:0 metrics:nil views:NSDictionaryOfVariableBindings(btnFirst)]];
    }
    return self;
}

-(id)initWithChoose:(NSString*)title First:(NSString*)firstbtn Second:(NSString*)secondbtn FirstBlock:(void (^)())firstblock SecondBlock:(void (^)())secondblock
{
    if(self=[super init])
    {
        [self setup];
        blockFirst=firstblock;
        blockSecond=secondblock;
        lbTitle.text=title;
        btnFirst.hidden=NO;
        btnSecond.hidden=NO;
        if(firstbtn!=nil)
        {
            [btnFirst setTitle:firstbtn forState:UIControlStateNormal];
        }
        if(secondbtn!=nil)
        {
            [btnSecond setTitle:secondbtn forState:UIControlStateNormal];
        }
        [viewTitle addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"|-25-[btnFirst(==btnSecond)]-30-[btnSecond]-25-|" options:0 metrics:nil views:NSDictionaryOfVariableBindings(btnFirst,btnSecond)]];
        [viewTitle addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:[btnFirst(20)]-5-|" options:0 metrics:nil views:NSDictionaryOfVariableBindings(btnFirst)]];
        [viewTitle addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:[btnSecond(20)]-5-|" options:0 metrics:nil views:NSDictionaryOfVariableBindings(btnSecond)]];
    }
    return self;
}

-(void)showInView:(UIView*)view
{
    self.backgroundColor=[UIColor colorWithRed:1 green:1 blue:1 alpha:0.3];
    self.alpha=0;
    [view addSubview:self];
    [view addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"|[self]|" options:0 metrics:nil views:NSDictionaryOfVariableBindings(self)]];
    [view addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:|[self]|" options:0 metrics:nil views:NSDictionaryOfVariableBindings(self)]];
    [UIView animateWithDuration:0.5 animations:^{
        self.alpha=1;
    }];
}

-(void)close:(UIButton*)sender
{
    if(sender.tag==0)
    {
        if(blockFirst!=nil)
        {
            blockFirst();
        }
    }
    else if (sender.tag==1)
    {
        if(blockSecond!=nil)
        {
            blockSecond();
        }
    }
    [self removeFromSuperview];
}
@end













