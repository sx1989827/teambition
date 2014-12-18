//
//  FUApplication.m
//  ForU
//
//  Created by 孙昕 on 14/12/16.
//  Copyright (c) 2014年 孙昕. All rights reserved.
//

#import "FUApplication.h"
#include "Application.h"
@interface FUApplication()
{
    CoreApplication *app;
}
@end
@implementation FUApplication
-(id)init
{
    if(self=[super init])
    {
        app=new CoreApplication;
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

-(void)Reset:(GIRLTYPE)girltype
{
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
    
}

-(void)CreateNotify
{
    
}
@end











