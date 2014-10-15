//
//  main.cpp
//  Core
//
//  Created by 孙昕 on 14-10-13.
//
//

#include <iostream>
#include "util/Header.h"
#include "logic/notify/Notify.h"
int main(int argc, const char * argv[])
{
    
    CoreNotify *notiobj=new CoreNotify;
    CoreNotifySingleton::SetInstance(notiobj);
    sNotify noti;
    noti.sec=1000;
    strcpy(noti.szText,"二维饿飞翁rrer");
    noti.type=sNotify::WORKIOI;
    noti.bEnabled=true;
    noti.flag=222;
    NOTIFYCENTER->CreateNotify(&noti);
    FILE *f1= fopen("/Users/sunxin/me/teambition/code/1.0/Core/data.txt","wb");
    NOTIFYCENTER->Serializ(f1);
    fclose(f1);
    FILE *f2= fopen("/Users/sunxin/me/teambition/code/1.0/Core/data.txt","rb");
    NOTIFYCENTER->UnSerializ(f2);
    fclose(f2);
}







