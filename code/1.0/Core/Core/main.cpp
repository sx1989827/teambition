//
//  main.cpp
//  Core
//
//  Created by 孙昕 on 14-10-13.
//
//

#include <iostream>
#include <sys/time.h>
#include "util/Header.h"
#include "logic/notify/Notify.h"
#include "save/Save.h"
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
    CoreSave *save=new CoreSave;
    std::vector<CoreSerializ*> vec;
    vec.push_back(NOTIFYCENTER);
    save->SetSaveObj(&vec);
    CoreSaveSingleton::SetInstance(save);
    SAVEINSTANCE->Save();
    SAVEINSTANCE->UnSave();

}







