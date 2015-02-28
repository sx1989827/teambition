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
    if(app->GetPlayer()->GetStatusController()->GetStatus()==CoreStatus::SLEEP)
    {
        return;
    }
    sNotify::TYPE type=NOTIFYCENTER->GetAvailableNotify();
    if(type!=sNotify::NONE)
    {
        sNotify noti;
        noti.type=type;
        noti.sec=time(0);
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
        noti.title=[strContent UTF8String];
        long notifyId=NOTIFYCENTER->CreateNotify(&noti);
        UILocalNotification *notification = [[UILocalNotification alloc] init];
        if (notification != nil) {
            notification.timeZone = [NSTimeZone defaultTimeZone];
            notification.soundName = UILocalNotificationDefaultSoundName;
            notification.alertBody = strContent;
            NSDictionary *info = @{@"id":@(notifyId),@"type":@(noti.type)};
            notification.userInfo = info;
            [[UIApplication sharedApplication] presentLocalNotificationNow:notification];
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
        if((CoreDateBase::TYPE)datetype==CoreDateBase::FILM)
        {
            noti.sec=CoreTime::GetTimeSinceNow(3600).GetOriTime();
        }
        else if((CoreDateBase::TYPE)datetype==CoreDateBase::EAT)
        {
            noti.sec=CoreTime::GetTimeSinceNow(1800).GetOriTime();
        }
        else if((CoreDateBase::TYPE)datetype==CoreDateBase::PARK)
        {
            noti.sec=CoreTime::GetTimeSinceNow(3600).GetOriTime();
        }
        else if((CoreDateBase::TYPE)datetype==CoreDateBase::WALK)
        {
            noti.sec=CoreTime::GetTimeSinceNow(2400).GetOriTime();
        }
    }
    NSString *strContent=[NSString stringWithUTF8String:NotifyDes[noti.type].data()];
    noti.title=[strContent UTF8String];
    long notifyId=NOTIFYCENTER->CreateNotify(&noti);
    UILocalNotification *notification = [[UILocalNotification alloc] init];
    if (notification != nil)
    {
        notification.fireDate=[NSDate dateWithTimeIntervalSince1970:noti.sec];
        notification.timeZone = [NSTimeZone defaultTimeZone];
        NSArray *arr=@[@"call1.wav",@"call2.wav"];
        NSString *sound=(type==NOTIFYTYPE::CALL)?arr[random()%2]:UILocalNotificationDefaultSoundName;
        notification.soundName = sound;
        notification.alertBody = strContent;
        NSDictionary *info = @{@"id":@(notifyId),@"type":@(noti.type)};
        notification.userInfo = info;
        [[UIApplication sharedApplication] scheduleLocalNotification:notification];
    }

}

-(void)AdjustNotify
{
    UIApplicationState state = [UIApplication sharedApplication].applicationState;
    if(state!=UIApplicationStateActive && state!=UIApplicationStateInactive)
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
            case sNotify::DATEITEMEND:
            {
                NSLog(@"%@",@"sNotify::DATEITEMEND");
                [[NSNotificationCenter defaultCenter] postNotificationName:MSGDATEITEMEND object:nil];
                break;
            }
            case sNotify::WORKEVENT:
            case sNotify::LEISUREEVENT:
            {
                NSLog(@"%@",@"sNotify::WORKLEISUREEVENT");
                [[NSNotificationCenter defaultCenter] postNotificationName:MSGEVENT object:[NSString stringWithUTF8String: noti.title.data()]];
                break;
            }
            case sNotify::WORKIOI:
            {
                NSLog(@"%@",@"sNotify::WORKIOI");
                [[NSNotificationCenter defaultCenter] postNotificationName:MSGWORKIOI object:nil];
                break;
            }
            case sNotify::WORKMEET:
            {
                NSLog(@"%@",@"sNotify::WORKMEET");
                [[NSNotificationCenter defaultCenter] postNotificationName:MSGWORKMEET object:nil];
                break;
            }
//            case sNotify::WORKHELP:
//            {
//                NSLog(@"%@",@"sNotify::WORKHELP");
//                [[NSNotificationCenter defaultCenter] postNotificationName:MSGWORKHELP object:nil];
//                break;
//            }
            case sNotify::LEISUREIOI:
            {
                NSLog(@"%@",@"sNotify::LEISUREIOI");
                [[NSNotificationCenter defaultCenter] postNotificationName:MSGLEISUREIOI object:nil];
                break;
            }
            case sNotify::LEISUREDATE:
            {
                NSLog(@"%@",@"sNotify::LEISUREDATE");
                [[NSNotificationCenter defaultCenter] postNotificationName:MSGLEISUREDATE object:nil];
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

-(PLAYERSTATE)GetPlayerState
{
    return (PLAYERSTATE)app->GetPlayer()->GetStatusController()->GetStatus();
}

-(void)ChangePlayerState:(PLAYERSTATE)state
{
    app->GetPlayer()->GetStatusController()->ChangeStatus((CoreStatus::TYPE)state);
}

-(NSString*)GetPlace
{
    return [NSString stringWithUTF8String:app->GetPlayer()->GetPlace().data()];
}

-(GIRLTYPE)GetGirlType
{
    return (GIRLTYPE)app->GetGirl()->GetGirlType();
}

-(BOOL)HandleActionEye:(ACTIONEYETYPE)type
{
    BOOL bRet= app->GetPlayer()->HandleActionEye((CoreActionEye::TYPE) type);
    return bRet;
}

-(void)HandleActionBody:(ACTIONBODYTYPE)type
{
	app->GetPlayer()->HandleActionBody((CoreActionBody::TYPE) type);
}

-(void)HandleActionTalk:(NSString*)type
{
    app->GetPlayer()->HandleActionTalk([type UTF8String]);
}

-(NSString*)GetGirlMoodDes
{
    return [NSString stringWithUTF8String: app->GetGirl()->GetMood()->GetStrDescription().data()];
}

-(CGRect)GetGirlFaceRect
{
    CoreGirl::sBodyRect rect=app->GetGirl()->GetFaceRect();
    return CGRectMake(rect.x, rect.y, rect.w, rect.h);
}

-(CGRect)GetGirlBreastRect
{
    CoreGirl::sBodyRect rect=app->GetGirl()->GetBreastRect();
    return CGRectMake(rect.x, rect.y, rect.w, rect.h);

}

-(NSArray*)GetAvalibleBodyAction
{
    NSArray *arr=@[@{
                       @"text":@"拍拍肩膀",
                       @"id":@(PATSHOULDER)
                       },@{
                       @"text":@"抚摸头发",
                       @"id":@(TOUCHHAIR)
                       },@{
                       @"text":@"碰下手臂",
                       @"id":@(TOUCHHAND)
                       },@{
                       @"text":@"捏捏脸",
                       @"id":@(KNEADFACE)
                       },@{
                       @"text":@"拥抱",
                       @"id":@(HUG)
                       },@{
                       @"text":@"Kiss",
                       @"id":@(KISS)
                       },@{
                       @"text":@"按摩",
                       @"id":@(MASSAGE)
                       },@{
                       @"text":@"拇指大战",
                       @"id":@(FINGERWAR)
                       },@{
                       @"text":@"搂腰",
                       @"id":@(HUGWAIST)
                       },@{
                       @"text":@"刮鼻子",
                       @"id":@(RUBNOSE)
                       },@{
                       @"text":@"牵手",
                       @"id":@(HANDINHAND)
                       },@{
                       @"text":@"搭肩",
                       @"id":@(LIFT)
                       }];
    std::vector<CoreActionBody::TYPE> vec=app->GetPlayer()->GetAvalibleActionBody();
    NSMutableArray *arrRet=[[NSMutableArray alloc] initWithCapacity:30];
    for(NSDictionary *dic in arr)
    {
        if(std::find(vec.begin(), vec.end(), [dic[@"id"] intValue])!=vec.end())
        {
            [arrRet addObject:dic];
        }
    }
    return arrRet;
}

-(NSArray*)GetAvalibleTalkAction
{
    NSMutableArray *arr=[[NSMutableArray alloc] initWithCapacity:30];
    std::vector<std::string> vec=app->GetPlayer()->GetAvalibleActionTalk();
    for(long i=0;i<vec.size();i++)
    {
        [arr addObject:@{@"text":[NSString stringWithUTF8String:vec[i].data()]}];
    }
    return arr;
}


-(BOOL)TryEnterInteraction:(INTERACTIONTYPE)interType DateType:(DATETYPE)dateType
{
    return app->GetPlayer()->TryEnterInteraction((CoreInteraction::TYPE)interType, (CoreDateBase::TYPE)dateType);
}

-(void)EnterInteraction:(INTERACTIONTYPE)interType DateType:(DATETYPE)dateType
{
	app->GetPlayer()->EnterInteraction((CoreInteraction::TYPE)interType, (CoreDateBase::TYPE)dateType);
    if(interType==DATEIOI || interType==DATELOVE || interType==DATENOLOVE)
    {
        [self CreateNotify:DATEITEMEND Time:nil DateType:dateType];
    }
}

-(void)LeaveInteraction
{
    app->GetPlayer()->LeaveInteraction();
    [self RemoveNotify];
}

-(void)Load
{
    app->Load();
}

-(NSArray*)GetAvalibleGift
{
    NSMutableArray *arr=[[NSMutableArray alloc] initWithCapacity:30];
    std::map<std::string,double> mapGift= GIFTCENTER->GetAllGift();
    auto it=mapGift.begin();
    for(;it!=mapGift.end();++it)
    {
        [arr addObject:@{
                        @"title":[NSString stringWithUTF8String:it->first.data()],
                        @"price":@(it->second)
                         }];
    }
    return arr;
}

-(NSDictionary*)HandleGift:(NSString*)title
{
    std::string err;
    BOOL bRet=GIFTCENTER->HandleGift([title UTF8String], err);
    if(bRet)
    {
        return @{
                 @"status":@"success"
                 };
    }
    else
    {
        return @{
                 @"status":@"fail",
                 @"error":[NSString stringWithUTF8String:err.data()]
                 };
    }
}

-(NSInteger)GetNotifyCount
{
    return NOTIFYCENTER->GetNotifyCount();
}

-(BOOL)isInteraction
{
    return app->GetPlayer()->IsInteraction();
}

-(INTERACTIONTYPE)GetInteractionType
{
    return (INTERACTIONTYPE)app->GetPlayer()->GetInteractionType();
}

-(NSString*)GetPlayerActionDes
{
    return [NSString stringWithUTF8String:app->GetPlayer()->GetActionDes().data()];
}

-(BOOL)HandleLove
{
	if(!app->GetPlayer()->GetLove() && app->GetGirl()->GetIOI()>=95 && app->GetGirl()->GetMood()->GetMoodType()==2)
    {
        app->GetPlayer()->SetLove(true);
        return true;
    }
    else
    {
        return false;
    }
}
@end













