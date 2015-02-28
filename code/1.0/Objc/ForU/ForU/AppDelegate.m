//
//  AppDelegate.m
//  ForU
//
//  Created by 孙昕 on 14/12/15.
//  Copyright (c) 2014年 孙昕. All rights reserved.
//

#import "AppDelegate.h"
#import "StartViewController.h"
#import "FUAlertView.h"
#import "SvGifView.h"
#import "FUSoundPlay.h"
@interface AppDelegate ()
{
    UIImageView *viewImg;
}
@end

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    [NSThread  sleepForTimeInterval:1];
    [application setMinimumBackgroundFetchInterval:UIApplicationBackgroundFetchIntervalMinimum];
    if ([UIApplication instancesRespondToSelector:@selector(registerUserNotificationSettings:)]){
        
        [application registerUserNotificationSettings:[UIUserNotificationSettings settingsForTypes:UIUserNotificationTypeAlert|UIUserNotificationTypeBadge|UIUserNotificationTypeSound categories:nil]];
        
    }
    _app=[[FUApplication alloc] init];
    _window=[[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    StartViewController *view=[[StartViewController alloc] initWithNibName:@"StartViewController" bundle:nil];
    UINavigationController *nav=[[UINavigationController alloc] initWithRootViewController:view];
    nav.navigationBarHidden=YES;
    self.window.rootViewController=nav;
    [self.window makeKeyAndVisible];
    return YES;
}

-(void)applicationWillResignActive:(UIApplication *)application
{
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        viewImg=[[UIImageView alloc] initWithFrame:self.window.bounds];
        viewImg.image=[UIImage imageNamed:@"start.jpg"];
        [self.window addSubview:viewImg];

    });
    _viewAppearTime=[NSDate date];
}


- (void)applicationDidEnterBackground:(UIApplication *)application
{

}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
   if(_timerUpdate==nil)
   {
       return;
   }

}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    [viewImg removeFromSuperview];
    if(_timerUpdate==nil)
    {
        return;
    }
    if([APP GetNotifyCount]==0)
    {
        if(-[_viewAppearTime timeIntervalSinceNow]>=600 && ![APP isInteraction])
        {
            [APP CreateNotify];
        }
    }
    else
    {
        [_app AdjustNotify];
    }

}

- (void)applicationWillTerminate:(UIApplication *)application {
    [_timerUpdate invalidate];
    _timerUpdate=nil;
    [[UIApplication sharedApplication] cancelAllLocalNotifications];
}

-(void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification
{
    if(_timerUpdate==nil)
    {
        return;
    }
    [_app AdjustNotify];
}

-(void)initTimer
{
    _timerUpdate=[NSTimer scheduledTimerWithTimeInterval:5 target:self selector:@selector(timerUpdate:) userInfo:nil repeats:YES];
}

-(void)timerUpdate:(NSTimer*)theTimer
{
    [APP Update];
    [APP Save];
    if([UIApplication sharedApplication].applicationState==UIApplicationStateActive && ![APP isInteraction])
    {
        if([APP HandleLove])
        {
            UIViewController *view=((UINavigationController*)self.window.rootViewController).topViewController;
            [[FUSoundPlay shareInstance] playEffectSound:@"good"];
            FUAlertView *alertview=[[FUAlertView alloc] initWithMsg:@"恭喜你！你终于追到女生啦，不要高兴太早，接下里还有更多挑战噢！"];
            [alertview showInView:view.view];
        }
    }
}

-(void)application:(UIApplication *)application performFetchWithCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler
{
    if(_timerUpdate!=nil)
    {
        if(![APP isInteraction])
        {
            [APP CreateNotify];
        }
        [APP Update];
        [APP Save];
        completionHandler(UIBackgroundFetchResultNewData);
    }
    else
    {
        completionHandler(UIBackgroundFetchResultNoData);
    }
}
@end









