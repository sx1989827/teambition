//
//  ChooseGirlViewController.h
//  ForU
//
//  Created by 孙昕 on 15/1/10.
//  Copyright (c) 2015年 孙昕. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
@interface ChooseGirlViewController : UIViewController
@property (strong, nonatomic) IBOutlet UITextField *txtName;
@property (strong, nonatomic) IBOutlet UIScrollView *scvGirl;
@property (strong, nonatomic) IBOutlet UIButton *btnAddress;
- (IBAction)onAdress:(id)sender;
@property (assign,nonatomic) CLLocationCoordinate2D cood;
- (IBAction)onStart:(id)sender;

@end
