//
//  MsgShowView.m
//  ForU
//
//  Created by 孙昕 on 15/2/20.
//  Copyright (c) 2015年 孙昕. All rights reserved.
//

#import "MsgShowView.h"
#import <pop/POP.h>
#import "AppDelegate.h"
@implementation MsgShowView


+(void)showTitleInView:(NSString*)tite
{
    MsgShowView *msgView=[[[self class] alloc] init];
    msgView.text=tite;
    msgView.textAlignment=NSTextAlignmentCenter;
    msgView.frame=CGRectMake(0, 0, 1000, 30);
    msgView.textColor=[UIColor colorWithRed:0.000 green:0.685 blue:1.000 alpha:1.000];
    msgView.backgroundColor=[UIColor colorWithRed:1.000 green:0.902 blue:0.745 alpha:1.000];
    AppDelegate *app=[UIApplication sharedApplication].delegate;
    msgView.center=app.window.center;
    CGRect frame=msgView.frame;
    msgView.frame=CGRectMake(app.window.center.x, app.window.center.y, 0, 0);
    [app.window addSubview:msgView];
    POPBasicAnimation *ani=[POPBasicAnimation animationWithPropertyNamed:kPOPViewFrame];
    ani.duration=0.2;
    ani.toValue=[NSValue valueWithCGRect:frame];
    [ani setCompletionBlock:^(POPAnimation *, BOOL) {
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1.5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            POPBasicAnimation *aniHide=[POPBasicAnimation animationWithPropertyNamed:kPOPViewFrame];
            aniHide.duration=0.2;
            aniHide.toValue=[NSValue valueWithCGRect:CGRectMake(app.window.center.x, app.window.center.y, 0, 0)];
            [aniHide setCompletionBlock:^(POPAnimation *, BOOL) {
                [msgView removeFromSuperview];
            }];
            [msgView pop_addAnimation:aniHide forKey:@"hideFrame"];
        });
    }];
    [msgView pop_addAnimation:ani forKey:@"showFrame"];
    
}

@end





