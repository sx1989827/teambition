//
//  HeaderValueView.m
//  ForU
//
//  Created by 孙昕 on 15/2/9.
//  Copyright (c) 2015年 孙昕. All rights reserved.
//

#import "HeaderValueView.h"

@implementation HeaderValueView
-(UIView*)sharedInstance
{
    static dispatch_once_t onceToken;
    static UIView *view;
    dispatch_once(&onceToken, ^{
        view=[[[NSBundle mainBundle] loadNibNamed:@"HeaderValueView" owner:self options:nil] lastObject];
        view.frame=self.bounds;
        view.autoresizingMask=UIViewAutoresizingFlexibleWidth|UIViewAutoresizingFlexibleHeight;
    });
    return view;
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

@end




