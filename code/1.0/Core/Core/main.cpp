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
    noti.type=sNotify::DATEEND;
    noti.flag=222;
    NOTIFYCENTER->CreateNotify(&noti,0);
    NOTIFYCENTER->AdjustNotify();
    SAVEINSTANCE->Save();
    SAVEINSTANCE->UnSave();
    
}







