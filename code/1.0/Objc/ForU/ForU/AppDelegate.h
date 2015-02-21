//
//  AppDelegate.h
//  ForU
//
//  Created by 孙昕 on 14/12/15.
//  Copyright (c) 2014年 孙昕. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FUApplication.h"
@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;
@property (assign,nonatomic) long viewAppearTime;
@property (strong,nonatomic) FUApplication *app;
@property (strong,nonatomic) NSTimer *timerUpdate;
@end

