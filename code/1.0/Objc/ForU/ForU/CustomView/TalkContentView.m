//
//  TalkContentView.m
//  ForU
//
//  Created by 孙昕 on 15/2/14.
//  Copyright (c) 2015年 孙昕. All rights reserved.
//

#import "TalkContentView.h"
#import "FUPublic.h"
#import "AppDelegate.h"
@interface TalkContentView()
{
    NSString *strContent;
    NSTimer *timer;
    long index;
    double afterDismiss;
    void (^blockComplete)();
}
@end
@implementation TalkContentView
-(UIView*)viewInstance
{
    UIView *view=[[[NSBundle mainBundle] loadNibNamed:@"TalkContentView" owner:self options:nil] lastObject];
    view.frame=self.bounds;
    view.clipsToBounds=NO;
    view.autoresizingMask=UIViewAutoresizingFlexibleWidth|UIViewAutoresizingFlexibleHeight;
    return view;
}

-(id)initWithCoder:(NSCoder *)aDecoder
{
    if(self=[super initWithCoder:aDecoder])
    {
        UIView *view=[self viewInstance];
        self.backgroundColor=[UIColor colorWithRed:0 green:0 blue:0 alpha:0.500];
        self.clipsToBounds=NO;
        _lbName.userInteractionEnabled=YES;
        UITapGestureRecognizer *tap=[[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(actionTap:)];
        [_lbName addGestureRecognizer:tap];
        [self addSubview:view];
    }
    return self;
}

-(void)actionTap:(UITapGestureRecognizer*)tap
{
    if(_delegate && [_delegate respondsToSelector:@selector(TalkContentViewClicked:Text:)])
    {
        [_delegate TalkContentViewClicked:self Text:_lbContent.text];
    }
}

-(void)setGirlContentText:(NSString*)text AfterDiss:(double)diss DissCompleteBlock:(void (^)())block
{
    [timer invalidate];
    timer=nil;
    index=0;
    strContent=text;
    self.hidden=NO;
    afterDismiss=diss;
    blockComplete=block;
    NSString *strGirlType;
	if([APP GetGirlType]==LOLI)
    {
        strGirlType=@"lolihead";
    }
    else if([APP GetGirlType]==MAID)
    {
        strGirlType=@"maidhead";
    }
    else if([APP GetGirlType]==QUEEN)
    {
        strGirlType=@"queenhead";
    }
    _imgHead.image=[UIImage imageNamed:strGirlType];
    _lbName.text=[[NSUserDefaults standardUserDefaults] stringForKey:@"name"];
    timer=[NSTimer scheduledTimerWithTimeInterval:0.08 target:self selector:@selector(setContent) userInfo:nil repeats:YES];
                  
}


-(void)setContent
{
    if(index==strContent.length)
    {
        [timer invalidate];
        timer=nil;
        if(afterDismiss>0.000001)
        {
            dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(afterDismiss * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
                self.hidden=YES;
                if(blockComplete)
                {
                    blockComplete();
                }
            });
        }
        return;
    }
    _lbContent.text=[strContent substringToIndex:++index];
    
}

-(void)willMoveToSuperview:(UIView *)newSuperview
{
    if(newSuperview==nil)
    {
        [timer invalidate];
        timer=nil;
    }
}

-(void)setPlayerContentText:(NSString*)text AfterDiss:(double)diss DissCompleteBlock:(void (^)())block
{
    [timer invalidate];
    timer=nil;
    index=0;
    strContent=text;
    self.hidden=NO;
    afterDismiss=diss;
    blockComplete=block;
    _imgHead.image=[UIImage imageNamed:@"player.jpg"];
    _lbName.text=@"我";
    timer=[NSTimer scheduledTimerWithTimeInterval:0.08 target:self selector:@selector(setContent) userInfo:nil repeats:YES];
}
@end












