//
//  StartViewController.h
//  ForU
//
//  Created by 孙昕 on 14/12/16.
//  Copyright (c) 2014年 孙昕. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface StartViewController : UIViewController
- (IBAction)click:(id)sender;
@property (strong, nonatomic) IBOutlet UIButton *btn1;
@property (strong, nonatomic) IBOutlet NSLayoutConstraint *btn1Height;
@property (strong, nonatomic) IBOutlet NSLayoutConstraint *btn1Left;
@property (strong, nonatomic) IBOutlet UILabel *lbText;

@end
