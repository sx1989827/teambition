//
//  main.cpp
//  Core
//

#include <iostream>
#include "Application.h"
#include "Favorite.h"
int main(int argc, const char * argv[])
{
    CoreApplication app;
    sNotify noti;
    noti.sec=1000;
    strcpy(noti.szText,"都是都f是 drrer");
    noti.type=sNotify::WORKIOI;
    noti.bEnabled=true;
    noti.flag=222;
    NOTIFYCENTER->CreateNotify(&noti);
    SAVEINSTANCE->Save();
    SAVEINSTANCE->UnSave();
    CoreFavorite f;
    f.Build(FAVFILE);
}







