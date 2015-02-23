//
//  DatePickerView.m
//  ForU
//
//  Created by 孙昕 on 15/2/23.
//  Copyright (c) 2015年 孙昕. All rights reserved.
//

#import "DatePickerView.h"
#import <pop/POP.h>
@interface DatePickerView()
{
    void (^blockComplete)(NSDate *date);
    UIDatePicker *datePicker;
}
@end
@implementation DatePickerView
-(id)init
{
    if(self=[super init])
    {
        datePicker = [ [ UIDatePicker alloc] initWithFrame:CGRectMake(0,0,320,300)];
        NSLocale * locale = [[NSLocale alloc] initWithLocaleIdentifier:@"Chinese"];
        [datePicker setLocale:locale];
        //datePicker.minuteInterval=10;
        datePicker.datePickerMode=UIDatePickerModeDateAndTime;
        datePicker.backgroundColor=[UIColor colorWithRed:0.824 green:0.902 blue:1.000 alpha:0.790];
        NSDate* minDate = [NSDate date];
        NSDate* maxDate = [NSDate dateWithTimeIntervalSinceNow:3600*24];
        datePicker.minimumDate = minDate;
        datePicker.maximumDate = maxDate;
        [self addSubview:datePicker];

    }
    return self;
}

-(void)dateValueChange:(id)sender
{
    blockComplete(datePicker.date);
    [self removeFromSuperview];
}

-(void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
    [self removeFromSuperview];
}

-(void)showInView:(UIView*)view
{
    self.frame=view.bounds;
    self.autoresizingMask=UIViewAutoresizingFlexibleWidth|UIViewAutoresizingFlexibleHeight;
    self.backgroundColor=[UIColor colorWithRed:1 green:1 blue:1 alpha:0.8];
    datePicker.center=self.center;
    CGRect frame=datePicker.frame;
    datePicker.frame=CGRectMake(self.center.x, self.center.y, 0, 0);
    [view addSubview:self];
    POPSpringAnimation *aniFrame=[POPSpringAnimation animationWithPropertyNamed:kPOPViewFrame];
    aniFrame.springBounciness=10;
    aniFrame.toValue=[NSValue valueWithCGRect:frame];
    [datePicker pop_addAnimation:aniFrame forKey:@"aniFrame"];
    [aniFrame setCompletionBlock:^(POPAnimation *, BOOL) {
        UIButton *btn=[[UIButton alloc] initWithFrame:CGRectMake(self.center.x-40, frame.origin.y+frame.size.height+10, 80, 30)];
        [btn setBackgroundColor:[UIColor colorWithRed:0.363 green:0.851 blue:1.000 alpha:0.740]];
        [btn setTitle:@"确定" forState:UIControlStateNormal];
        [btn addTarget:self action:@selector(dateValueChange:) forControlEvents:UIControlEventTouchUpInside];
        [self addSubview:btn];
    }];
}

-(void)setCompleteBlock:(void (^)(NSDate *date))block
{
    blockComplete=block;
}

@end













