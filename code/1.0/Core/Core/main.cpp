//
//  main.cpp
//  Core
//
//  Created by 孙昕 on 14-10-13.
//
//

#include <iostream>
#include "Application.h"
int main(int argc, const char * argv[])
{
    CoreApplication app;
    sNotify noti;
    noti.sec=1000;
    strcpy(noti.szText,"第三方 drrer");
    noti.type=sNotify::WORKIOI;
    noti.bEnabled=true;
    noti.flag=222;
    NOTIFYCENTER->CreateNotify(&noti);
    SAVEINSTANCE->Save();
    SAVEINSTANCE->UnSave();
}







