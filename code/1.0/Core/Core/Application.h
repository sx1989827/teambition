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
class CoreApplication
{
public:
    CoreApplication();
    ~CoreApplication();
private:
    CoreNotify* m_pNotify;
    CoreSave* m_pSave;
    CoreObManage *m_pObManage;
    CoreLog *m_pLog;
};
#endif /* defined(__Core__Application__) */









