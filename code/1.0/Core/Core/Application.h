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
#include "Person/Mood.h"
#include "Person/Player.h"
#include "Status/Status.h"
#include "Status/StatusController.h"
#include "Interaction/Gift/Gift.h"
#include "Interaction/Event/Event.h"
#include "Interaction/Story/Story.h"
#include "Interaction/Date/DateBase.h"
class CoreApplication
{
public:
    CoreApplication();
    ~CoreApplication();
    CoreGirl *GetGirl();
    CorePlayer* GetPlayer();
    void Reset(CoreGirl::TYPE type);
    void Update();
private:
    CoreNotify* m_pNotify;
    CoreSave* m_pSave;
    CoreObManage *m_pObManage;
    CoreLog *m_pLog;
    CoreGirl *m_pGirl;
    CorePlayer *m_pPlayer;
    CoreGift *m_pGift;
    CoreEvent *m_pEvent;
    CoreStory *m_pStory;
};


#endif /* defined(__Core__Application__) */









