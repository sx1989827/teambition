//
//  main.cpp
//  Core
//

//  Created by ������ on 14-10-13.

//
//

#include <iostream>
#include "Application.h"
int main(int argc, const char * argv[])
{
    CoreApplication app;
    sNotify noti;
    noti.sec=1000;
    strcpy(noti.szText,"都是都是 drrer");
    noti.type=sNotify::WORKIOI;
    noti.bEnabled=true;
    noti.flag=222;
    NOTIFYCENTER->CreateNotify(&noti);
    SAVEINSTANCE->Save();
    SAVEINSTANCE->UnSave();
	printf("%s", "啊实打实的 ");
}







