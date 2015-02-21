//
//  StateViewController.h
//  ForU
//
//  Created by 孙昕 on 15/1/25.
//  Copyright (c) 2015年 孙昕. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "HeaderValueView.h"
@interface StateViewController : UIViewController
@property (strong, nonatomic) IBOutlet HeaderValueView *viewHeader;
- (IBAction)onSwitch:(id)sender;
- (IBAction)onAction:(id)sender;
@property (strong, nonatomic) IBOutlet UIButton *btnAction;
@property (strong, nonatomic) IBOutlet NSLayoutConstraint *conTitleTop;
- (IBAction)onTitle:(id)sender;

@end
