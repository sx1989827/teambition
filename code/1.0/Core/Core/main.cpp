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
    app.Reset(CoreGirl::LOLI);
    sNotify noti;
    noti.sec=1000;
    noti.type=sNotify::DATEITEMEND;
    noti.flag=222;
    NOTIFYCENTER->CreateNotify(&noti);
    NOTIFYCENTER->AdjustNotify();
    SAVEINSTANCE->Save();
    SAVEINSTANCE->UnSave();
    
}







