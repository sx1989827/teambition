//
//  FUApplication.m
//  ForU
//
//  Created by 孙昕 on 14/12/16.
//  Copyright (c) 2014年 孙昕. All rights reserved.
//

#import "FUApplication.h"
#import "AppDelegate.h"
#include "Application.h"
@interface FUApplication()
{
    CoreApplication *app;
    std::map<sNotify::TYPE,std::string> NotifyDes;
}
@end
@implementation FUApplication
-(id)init
{
    if(self=[super init])
    {
        app=new CoreApplication;
        NotifyDes[sNotify::CALL]="懒猪，该醒啦!";
        NotifyDes[sNotify::DATEITEMEND]="该约会项目结束了!";
        NotifyDes[sNotify::WORKHELPEND]="终于帮助女主完成工作啦!";
        NotifyDes[sNotify::WORKIOI]="女主主动来找你了噢!";
        NotifyDes[sNotify::WORKMEET]="碰到女主了，要不要打个招呼呢！";
        NotifyDes[sNotify::WORKHELP]="女主找你帮忙啦，是否帮助她呢！";
        NotifyDes[sNotify::LEISUREIOI]="女主主动来找你了噢!";
        NotifyDes[sNotify::LEISUREDATE]="女主找你约会啦！";
    }
    return self;
}

-(void)dealloc
{
    if(app)
    {
        delete app;
    }
}

-(void)Reset:(GIRLTYPE)girltype girlname:(NSString*)name x:(double)x y:(double)y
{
    NSUserDefaults *userDefaults=[NSUserDefaults standardUserDefaults];
    [userDefaults removeObjectForKey:@"ver"];
    [userDefaults setFloat:  [[[[NSBundle mainBundle] infoDictionary] objectForKey:(NSString *)kCFBundleVersionKey] floatValue] forKey:@"ver"];
    [userDefaults setDouble:x forKey:@"x"];
    [userDefaults setDouble:y forKey:@"y"];
    [userDefaults setValue:name forKey:@"name"];
    [userDefaults setValue:@(girltype) forKey:@"type"];
    [userDefaults synchronize];
    app->Reset((CoreGirl::TYPE)girltype);
    
}

-(void)Update
{
    app->Update();
}

-(NSString*)GetPlayerPhysical
{
    return [NSString stringWithFormat:@"%0.1lf",app->GetPlayer()->GetPhysical()];
}
-(NSString*)GetPlayerMoney
{
    return [NSString stringWithFormat:@"%0.1lf",app->GetPlayer()->GetMoney()];
}
-(NSString*)GetGirlIOI
{
    return [NSString stringWithFormat:@"%0.1lf",app->GetGirl()->GetIOI()];
}
-(NSString*)GetGirlMood
{
    return [NSString  stringWithUTF8String:app->GetGirl()->GetMood()->GetStrMood().data()];
}

-(void)Save
{
    SAVEINSTANCE->Save();
}

-(void)CreateNotify
{
    UIApplicationState state = [UIApplication sharedApplication].applicationState;
    if(state!=UIApplicationStateActive)
    {
        
    }
    else
    {
        if(app->GetPlayer()->GetStatusController()->GetStatus()==CoreStatus::SLEEP)
        {
            return;
        }
        AppDelegate *appDelegate=(AppDelegate*)[UIApplication sharedApplication].delegate;
        if(CoreTime::DiffNowTime(appDelegate.viewAppearTime)>=1200)
        {
            sNotify::TYPE type=NOTIFYCENTER->GetAvailableNotify();
            if(type!=sNotify::NONE)
            {
                sNotify noti;
                noti.type=type;
                noti.sec=time(0);
                long id=NOTIFYCENTER->CreateNotify(&noti);
                NSString *strContent;
                if(noti.type!=sNotify::WORKEVENT && noti.type!=sNotify::LEISUREEVENT)
                {
                    strContent=[NSString stringWithUTF8String:NotifyDes[noti.type].data()];
                }
                else
                {
                    sEvent eve= EVENTCENTER->GetAvaliableEvent();
                    strContent=[NSString stringWithUTF8String:eve.strDes.data()];
                    EVENTCENTER->HandleEvent(eve);
                }
                UILocalNotification *notification = [[UILocalNotification alloc] init];
                if (notification != nil) {
                    notification.timeZone = [NSTimeZone defaultTimeZone];
                    notification.soundName = UILocalNotificationDefaultSoundName;
                    notification.alertBody = strContent;
                    NSDictionary *info = @{@"id":@(id),@"type":@(noti.type)};
                    notification.userInfo = info;
                    [[UIApplication sharedApplication] presentLocalNotificationNow:notification];
                }
            }
        }
    }
}


-(void)CreateNotify:(NOTIFYTYPE)type Time:(NSDate *)date DateType:(DATETYPE)datetype
{
    if(type!=NOTIFYTYPE::CALL && type!=NOTIFYTYPE::WORKHELPEND & type!=NOTIFYTYPE::DATEITEMEND)
    {
        return;
    }
    sNotify noti;
    noti.type=(sNotify::TYPE)type;
    if(type==NOTIFYTYPE::CALL)
    {
        noti.sec=[date timeIntervalSince1970];
    }
    else if(type==NOTIFYTYPE::WORKHELPEND)
    {
        noti.sec=CoreTime::GetTimeSinceNow(1800).GetOriTime();
    }
    else if(type==NOTIFYTYPE::DATEITEMEND)
    {
        if((CoreDateBase::TYPE)type==CoreDateBase::FILM)
        {
            noti.sec=CoreTime::GetTimeSinceNow(3600).GetOriTime();
        }
        else if((CoreDateBase::TYPE)type==CoreDateBase::EAT)
        {
            noti.sec=CoreTime::GetTimeSinceNow(1800).GetOriTime();
        }
        else if((CoreDateBase::TYPE)type==CoreDateBase::PARK)
        {
            noti.sec=CoreTime::GetTimeSinceNow(3600).GetOriTime();
        }
        else if((CoreDateBase::TYPE)type==CoreDateBase::WALK)
        {
            noti.sec=CoreTime::GetTimeSinceNow(2400).GetOriTime();
        }
    }
    long id=NOTIFYCENTER->CreateNotify(&noti);
    NSString *strContent=[NSString stringWithUTF8String:NotifyDes[noti.type].data()];
    UILocalNotification *notification = [[UILocalNotification alloc] init];
    if (notification != nil)
    {
        notification.fireDate=[NSDate dateWithTimeIntervalSince1970:noti.sec];
        notification.timeZone = [NSTimeZone defaultTimeZone];
        notification.soundName = UILocalNotificationDefaultSoundName;
        notification.alertBody = strContent;
        NSDictionary *info = @{@"id":@(id),@"type":@(noti.type)};
        notification.userInfo = info;
        [[UIApplication sharedApplication] scheduleLocalNotification:notification];
    }

}

-(void)AdjustNotify
{
    UIApplicationState state = [UIApplication sharedApplication].applicationState;
    if(state!=UIApplicationStateActive)
    {
        return;
    }
    sNotify noti=NOTIFYCENTER->AdjustNotify();
    if(noti.type==sNotify::NONE)
    {
        return;
    }
    else if(CoreTime::DiffNowTime(noti.sec)<=600)
    {
        switch (noti.type) {
            case sNotify::CALL:
            {
                NSLog(@"%@",@"sNotify::CALL");
                break;
            }
            default:
                break;
        }
    }
}

-(BOOL)GetLove
{
    return app->GetPlayer()->GetLove();
}

-(void)RemoveNotify
{
    UIApplication *appDelagate = [UIApplication sharedApplication];
    NSArray *localArr = [appDelagate scheduledLocalNotifications];
    if (localArr)
    {
        for (UILocalNotification *noti in localArr)
        {
            NSDictionary *dict = noti.userInfo;
            if (dict)
            {
                long type = [[dict objectForKey:@"type"] intValue];
                if (type==(long)NOTIFYTYPE::CALL || type==(long)NOTIFYTYPE::WORKHELPEND || type==(long)NOTIFYTYPE::DATEITEMEND)
                {
                    [appDelagate cancelLocalNotification:noti];
                }
            }
        }
        
    }
    NOTIFYCENTER->RemoveNotify(sNotify::CALL);
    NOTIFYCENTER->RemoveNotify(sNotify::DATEITEMEND);
    NOTIFYCENTER->RemoveNotify(sNotify::WORKHELPEND);
    
}

-(void)Exit
{
    [self Update];
    [self Save];
    [[UIApplication sharedApplication] cancelAllLocalNotifications];
    
}

-(NSString*)GetStartStory
{
    sStory story=STORYCENTER->GetStartStory();
    if(story.id!=-1)
    {
        return [NSString stringWithUTF8String:story.strSrc.data()];
    }
    else
    {
        return nil;
    }
}
-(NSString*)GetStory
{
    sStory story=STORYCENTER->GetAvaliableStory();
    if(story.id!=-1)
    {
        return [NSString stringWithUTF8String:story.strSrc.data()];
    }
    else
    {
        return nil;
    }

}
@end













