//
//  DatePickerView.h
//  ForU
//
//  Created by 孙昕 on 15/2/23.
//  Copyright (c) 2015年 孙昕. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DatePickerView : UIView
-(void)showInView:(UIView*)view;
-(void)setCompleteBlock:(void (^)(NSDate *date))block;
@end
