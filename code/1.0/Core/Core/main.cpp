//
//  main.cpp
//  Core
//

#include <iostream>
#include "Application.h"
#include "Person/Favorite.h"
int main(int argc, const char * argv[])
{
    CoreApplication app;
    app.GetGirl()->BuildFavorite();
    sNotify noti;
    noti.sec=1000;
    strcpy(noti.szText,"都是都f是 drrer");
    noti.type=sNotify::DATEEND;
    noti.bEnabled=true;
    noti.flag=222;
    NOTIFYCENTER->CreateNotify(&noti);
    SAVEINSTANCE->Save();
    SAVEINSTANCE->UnSave();
    
}







