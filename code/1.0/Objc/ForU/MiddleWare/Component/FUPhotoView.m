//
//  FUPhotoView.m
//  ForU
//
//  Created by 孙昕 on 14/12/18.
//  Copyright (c) 2014年 孙昕. All rights reserved.
//

#import "FUPhotoView.h"
#import <QuartzCore/QuartzCore.h>
@implementation FUPhotoView
-(id)init
{
    if(self=[super init])
    {
        self.pagingEnabled=YES;
    }
    return self;
}


-(void)showInView:(UIView*)view
{
    self.backgroundColor=[UIColor clearColor];
    self.translatesAutoresizingMaskIntoConstraints=NO;
    self.alpha=0;
    [view addSubview:self];
    [view addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"|[self]|" options:0 metrics:nil views:NSDictionaryOfVariableBindings(self)]];
    [view addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:|[self]|" options:0 metrics:nil views:NSDictionaryOfVariableBindings(self)]];
    [UIView animateWithDuration:0.5 animations:^{
        self.alpha=1;
    }];

}
-(void)addPhoto:(NSString*)dir
{
    NSString *imgPath=[[NSBundle mainBundle] pathForResource:@"Image" ofType:@"bundle"];
    NSArray *arrPhoto=[[NSBundle bundleWithPath:imgPath] pathsForResourcesOfType:@"jpg" inDirectory:[NSString stringWithFormat:@"story/%@",dir]];
    long height=[UIScreen mainScreen].bounds.size.height;
    long width=[UIScreen mainScreen].bounds.size.width*arrPhoto.count;
    self.contentSize=CGSizeMake(width, height);
    for(long i=0;i<arrPhoto.count;i++)
    {
        UIImageView* view=[[UIImageView alloc] initWithFrame:CGRectMake(i*[UIScreen mainScreen].bounds.size.width, 0, [UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.height)];
        UIImage *img=[UIImage imageWithContentsOfFile:arrPhoto[i]];
        view.image=img;
        [self addSubview:view];
        if(i==arrPhoto.count-1)
        {
            UIButton *btn=[UIButton buttonWithType:UIButtonTypeSystem];
            btn.frame=CGRectMake(width-130, height-60, 100, 30);
            [btn setTitle:@"结束" forState:UIControlStateNormal];
            [btn addTarget:self action:@selector(close) forControlEvents:UIControlEventTouchUpInside];
            [btn.layer setMasksToBounds:YES];
            [btn.layer setCornerRadius:1.0];
            [btn.layer setBorderWidth:0.5];
            [self addSubview:btn];
        }
    }
}

-(void)close
{
    [self removeFromSuperview];
}
@end















