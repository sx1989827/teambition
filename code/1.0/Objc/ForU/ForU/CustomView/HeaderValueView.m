//
//  HeaderValueView.m
//  ForU
//
//  Created by 孙昕 on 15/2/9.
//  Copyright (c) 2015年 孙昕. All rights reserved.
//

#import "HeaderValueView.h"
#import "AppDelegate.h"
@interface HeaderValueView()
@property (strong, nonatomic) IBOutlet UILabel *lbPhysical;
@property (strong, nonatomic) IBOutlet UILabel *lbMoney;
@property (strong, nonatomic) IBOutlet UIImageView *imgMood;
@property (strong, nonatomic) IBOutlet UIView *viewIOI;
@property (strong, nonatomic) IBOutlet NSLayoutConstraint *conPhysical;
@end
@implementation HeaderValueView
@dynamic  lPhysical;
@dynamic lMoney;
@dynamic mood;
@dynamic lIOI;

-(UIView*)sharedInstance
{
    static dispatch_once_t onceToken;
    static UIView *view;
    dispatch_once(&onceToken, ^{
        view=[[[NSBundle mainBundle] loadNibNamed:@"HeaderValueView" owner:self options:nil] lastObject];
        view.frame=self.bounds;
        view.autoresizingMask=UIViewAutoresizingFlexibleWidth|UIViewAutoresizingFlexibleHeight;
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(update) name:MSGUPDATE object:nil];
    });
    return view;
}

-(void)update
{
    self.lPhysical=[[APP GetPlayerPhysical] integerValue];
    self.lMoney=[[APP GetPlayerMoney] integerValue];
    self.mood=[APP GetGirlMood];
    self.lIOI=[[APP GetGirlIOI] integerValue];
}

-(id)initWithCoder:(NSCoder *)aDecoder
{
    if(self=[super initWithCoder:aDecoder])
    {
        UIView *view=[self sharedInstance];
        [self addSubview:view];
    }
    return self;
}

-(void)setLPhysical:(long)lPhysical
{
    if(lPhysical<20)
    {
        _lbPhysical.backgroundColor=[UIColor redColor];
    }
    else if (lPhysical>=20 && lPhysical<60)
    {
        _lbPhysical.backgroundColor=[UIColor orangeColor];
    }
    else if (lPhysical>60 && lPhysical<80)
    {
        _lbPhysical.backgroundColor=[UIColor yellowColor];
    }
    else if (lPhysical>=80)
    {
        _lbPhysical.backgroundColor=[UIColor greenColor];
    }
    _conPhysical.constant=lPhysical;
    [self layoutIfNeeded];
}


-(void)setLMoney:(long)lMoney
{
    _lbMoney.text=[NSString stringWithFormat:@"%ld",lMoney];
}

-(void)setMood:(NSString *)mood
{
    //_imgMood.backgroundColor=[UIColor colorWithRed:0.899 green:0.792 blue:0.814 alpha:1.000];
    _imgMood.image=[UIImage imageNamed:mood];
}

-(void)setLIOI:(long)lIOI
{
    for(UIView * view in _viewIOI.subviews)
    {
        [view removeFromSuperview];
    }
    long count=lIOI/20+1;
    if(count<1) count=1;
    if(count>5) count=5;
    for(long i=0;i<count;i++)
    {
        UIImageView *imgView=[[UIImageView alloc] initWithImage:[UIImage imageNamed:@"IOI"]];
        imgView.frame=CGRectMake(i*20+3, 0, 20, 21);
        [_viewIOI addSubview:imgView];
    }
}

-(void)dealloc
{
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}
@end


















