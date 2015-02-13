//
//  GirlShowView.m
//  ForU
//
//  Created by 孙昕 on 15/2/12.
//  Copyright (c) 2015年 孙昕. All rights reserved.
//

#import "GirlShowView.h"
#import <pop/POP.h>
@interface GirlShowView()<POPAnimationDelegate>
@end
@implementation GirlShowView
-(id)initWithCoder:(NSCoder *)aDecoder
{
    if(self=[super initWithCoder:aDecoder])
    {
        [self addObserver:self forKeyPath:@"image" options:NSKeyValueObservingOptionOld|NSKeyValueObservingOptionNew context:nil];
        self.userInteractionEnabled=YES;
    }
    return  self;
}

-(void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary *)change context:(void *)context
{
    if([keyPath isEqualToString:@"image"])
    {
        if(self.image!=nil)
        {
            [self pop_removeAllAnimations];
            POPBasicAnimation *ani=[POPBasicAnimation animationWithPropertyNamed:kPOPViewScaleXY];
            ani.delegate=self;
            ani.toValue=[NSValue valueWithCGPoint:CGPointMake(1.03, 1.03)];
            ani.timingFunction = [CAMediaTimingFunction functionWithName:kCAMediaTimingFunctionEaseInEaseOut];
            ani.name=@"large";
            ani.duration=1.5;
            [self pop_addAnimation:ani forKey:@"large"];
        }
    }
}

-(void)pop_animationDidStop:(POPAnimation *)anim finished:(BOOL)finished
{
    if(!finished)
    {
        return;
    }
    if([anim.name isEqualToString:@"large"])
    {
        POPBasicAnimation *ani=[POPBasicAnimation animationWithPropertyNamed:kPOPViewScaleXY];
        ani.delegate=self;
        ani.toValue=[NSValue valueWithCGPoint:CGPointMake(1, 1)];
        ani.name=@"small";
        ani.duration=1.5;
        ani.timingFunction = [CAMediaTimingFunction functionWithName:kCAMediaTimingFunctionEaseInEaseOut];
        [self pop_addAnimation:ani forKey:@"small"];
    }
    else if([anim.name isEqualToString:@"small"])
    {
        POPBasicAnimation *ani=[POPBasicAnimation animationWithPropertyNamed:kPOPViewScaleXY];
        ani.delegate=self;
        ani.toValue=[NSValue valueWithCGPoint:CGPointMake(1.03, 1.03)];
        ani.name=@"large";
        ani.duration=1.5;
        ani.timingFunction = [CAMediaTimingFunction functionWithName:kCAMediaTimingFunctionEaseInEaseOut];
        [self pop_addAnimation:ani forKey:@"large"];
    }
}

-(void)dealloc
{
    [self pop_removeAllAnimations];
    [self removeObserver:self forKeyPath:@"image"];
}
@end












