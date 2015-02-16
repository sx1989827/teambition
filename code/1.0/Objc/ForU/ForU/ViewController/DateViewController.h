//
//  DateViewController.h
//  ForU
//
//  Created by 孙昕 on 15/2/16.
//  Copyright (c) 2015年 孙昕. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FUConstHeader.h"
@interface DateViewController : UIViewController
@property (strong, nonatomic) IBOutlet UIButton *btnAction;
- (IBAction)onAction:(id)sender;
- (IBAction)onQuit:(id)sender;
@property (strong, nonatomic) IBOutlet UIImageView *imgBack;
@property (assign,nonatomic) INTERACTIONTYPE dateType;
@end
