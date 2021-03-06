//
//  ChangeValueView.m
//  ForU
//
//  Created by 孙昕 on 15/2/13.
//  Copyright (c) 2015年 孙昕. All rights reserved.
//

#import "ChangeValueView.h"
#import <pop/POP.h>
@implementation ChangeValueView

-(id)initWithPoint:(CGPoint)point Title:(NSString*)title
{
    if(self=[super init])
    {
        self.frame=CGRectMake(point.x, point.y, 300, 30);
        self.text=title;
        self.font=[UIFont systemFontOfSize:20];
        
    }
    return self;
}

+(void)viewWithTitle:(CGPoint)point Title:(NSString*)title View:(UIView *)parentView Grow:(BOOL)bGrow
{
    ChangeValueView *view=[[ChangeValueView alloc] initWithPoint:point Title:title];
    if(bGrow)
    {
        view.textColor=[UIColor greenColor];
    }
    else
    {
        view.textColor=[UIColor redColor];
    }
    [parentView addSubview:view];
    POPBasicAnimation *aniFrame=[POPBasicAnimation animationWithPropertyNamed:kPOPViewFrame];
    aniFrame.duration=4;
    aniFrame.toValue=[NSValue valueWithCGRect:CGRectMake(view.frame.origin.x, view.frame.origin.y-300, view.frame.size.width, view.frame.size.height)];
    aniFrame.timingFunction=[CAMediaTimingFunction functionWithName:kCAMediaTimingFunctionEaseOut];
    [view pop_addAnimation:aniFrame forKey:@"aniFrame"];
    POPBasicAnimation *aniShow=[POPBasicAnimation animationWithPropertyNamed:kPOPViewAlpha];
    aniShow.duration=4;
    aniShow.toValue=@0;
    __weak ChangeValueView *weakView=view;
    [aniShow setCompletionBlock:^(POPAnimation *, BOOL) {
        [weakView pop_removeAllAnimations];
        [weakView removeFromSuperview];
    }];
    [view pop_addAnimation:aniShow forKey:@"aniShow"];
}



@end






