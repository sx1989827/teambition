//
//  Application.h
//  Core
//
//  Created by 孙昕 on 14-10-17.
//
//

#ifndef __Core__Application__
#define __Core__Application__
#include "util/Header.h"
#include "save/Save.h"
#include "logic/notify/Notify.h"
#include "Person/Girl.h"
#include "Person/Player.h"
class CoreApplication
{
public:
    CoreApplication();
    ~CoreApplication();
    CoreGirl *GetGirl();
    CorePlayer* GetPlayer();
private:
    CoreNotify* m_pNotify;
    CoreSave* m_pSave;
    CoreObManage *m_pObManage;
    CoreLog *m_pLog;
    CoreGirl *m_pGirl;
    CorePlayer *m_pPlayer;
};
#endif /* defined(__Core__Application__) */









