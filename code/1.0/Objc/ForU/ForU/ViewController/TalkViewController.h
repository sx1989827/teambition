//
//  TalkViewController.h
//  ForU
//
//  Created by 孙昕 on 15/2/11.
//  Copyright (c) 2015年 孙昕. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TalkContentView.h"
@interface TalkViewController : UIViewController
@property (strong, nonatomic) IBOutlet UIImageView *imgBack;
- (IBAction)onAction:(id)sender;
- (IBAction)onQuit:(id)sender;
@property (strong, nonatomic) IBOutlet UIImageView *imgGirl;
@property (strong, nonatomic) IBOutlet TalkContentView *viewTalk;


@end
