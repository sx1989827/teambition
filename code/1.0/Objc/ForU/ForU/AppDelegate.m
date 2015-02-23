//
//  AppDelegate.m
//  ForU
//
//  Created by 孙昕 on 14/12/15.
//  Copyright (c) 2014年 孙昕. All rights reserved.
//

#import "AppDelegate.h"
#import "StartViewController.h"
#import "StateViewController.h"
#import "SvGifView.h"
@interface AppDelegate ()

@end

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    if ([UIApplication instancesRespondToSelector:@selector(registerUserNotificationSettings:)]){
        
        [application registerUserNotificationSettings:[UIUserNotificationSettings settingsForTypes:UIUserNotificationTypeAlert|UIUserNotificationTypeBadge|UIUserNotificationTypeSound categories:nil]];
        
    }
    _app=[[FUApplication alloc] init];
    _window=[[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    //StateViewController *view=[[StateViewController alloc] initWithNibName:@"StateViewController" bundle:nil];
    StartViewController *view=[[StartViewController alloc] initWithNibName:@"StartViewController" bundle:nil];
    UINavigationController *nav=[[UINavigationController alloc] initWithRootViewController:view];
    nav.navigationBarHidden=YES;
    self.window.rootViewController=nav;
    [self.window makeKeyAndVisible];
    return YES;
}



- (void)applicationDidEnterBackground:(UIApplication *)application {


}

- (void)applicationWillEnterForeground:(UIApplication *)application {

}

- (void)applicationDidBecomeActive:(UIApplication *)application {

}

- (void)applicationWillTerminate:(UIApplication *)application {
    [_timerUpdate invalidate];
    _timerUpdate=nil;
    [[UIApplication sharedApplication] cancelAllLocalNotifications];
}

-(void)initTimer
{
    _timerUpdate=[NSTimer scheduledTimerWithTimeInterval:5 target:self selector:@selector(timerUpdate:) userInfo:nil repeats:YES];
}

-(void)timerUpdate:(NSTimer*)theTimer
{
    [APP Update];
    [APP Save];
}
@end









