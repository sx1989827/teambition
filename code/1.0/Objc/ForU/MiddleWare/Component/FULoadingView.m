//
//  FULoadingView.m
//  ForU
//
//  Created by 孙昕 on 14/12/17.
//  Copyright (c) 2014年 孙昕. All rights reserved.
//

#import "FULoadingView.h"

@implementation FULoadingView

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
}
*/
-(id)init
{
    if(self=[super init])
    {
        gifView=[[SvGifView alloc] initWithCenter:CGPointMake(self.bounds.size.width / 2, 130) fileName:@"loading" Bundle:@"Image"];
        gifView.backgroundColor = [UIColor clearColor];
        gifView.translatesAutoresizingMaskIntoConstraints=NO;
        [self addSubview:gifView];
        [gifView startGif];
        [self addConstraint:[NSLayoutConstraint constraintWithItem:gifView attribute:NSLayoutAttributeCenterX relatedBy:NSLayoutRelationEqual toItem:self attribute:NSLayoutAttributeCenterX multiplier:1 constant:0]];
        [self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"[gifView(240)]" options:0 metrics:nil views:NSDictionaryOfVariableBindings(gifView)]];
        [self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:|-120-[gifView(160)]" options:0 metrics:nil views:NSDictionaryOfVariableBindings(gifView)]];
        lbTitle=[[UILabel alloc] init];
        lbTitle.text=@"加载中。。。";
        lbTitle.textAlignment=NSTextAlignmentCenter;
        lbTitle.font=[UIFont fontWithName:@"Arial" size:20];
        lbTitle.translatesAutoresizingMaskIntoConstraints=NO;
        [self addSubview:lbTitle];
        [self addConstraint:[NSLayoutConstraint constraintWithItem:lbTitle attribute:NSLayoutAttributeCenterX relatedBy:NSLayoutRelationEqual toItem:self attribute:NSLayoutAttributeCenterX multiplier:1 constant:0]];
        [self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"[lbTitle(==gifView)]" options:0 metrics:nil views:NSDictionaryOfVariableBindings(lbTitle,gifView)]];
        [self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:[gifView]-10-[lbTitle(<=100)]" options:0 metrics:nil views:NSDictionaryOfVariableBindings(gifView,lbTitle)]];
    }
    return self;
}

-(void)showInView:(UIView*)view
{
    self.backgroundColor=[UIColor colorWithRed:255.0/255 green:248.0/255 blue:210.0/255 alpha:1];
    self.translatesAutoresizingMaskIntoConstraints=NO;
    self.alpha=0;
    [view addSubview:self];
    [view addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"|[self]|" options:0 metrics:nil views:NSDictionaryOfVariableBindings(self)]];
    [view addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:|[self]|" options:0 metrics:nil views:NSDictionaryOfVariableBindings(self)]];
    [UIView animateWithDuration:0.5 animations:^{
        self.alpha=1;
    }];
}

-(void)remove
{
    [gifView stopGif];
    [self removeFromSuperview];
}

@end










