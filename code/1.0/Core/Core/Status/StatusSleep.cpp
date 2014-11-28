//
//  StatusSleep.cpp
//  Core
//
//  Created by 孙昕 on 14/10/24.
//
//

#include "StatusSleep.h"
#include "../Person/Player.h"
#include "../logic/notify/Notify.h"
void CoreStatusSleep::OnEnter()
{
    m_StartTime.Reset();
    PLAYERINSTANCE->SetPlace("家");
    OBINSTANCE->PostOberserver(this, MSG_SLEEPENTER, 0);
}
void CoreStatusSleep::OnUpdate()
{
   const  sPlayInfo *info=PLAYERINSTANCE->GetPhysicalInfo(CoreStatus::SLEEP);
    if(info)
    {
        long count=(time(0)-m_StartTime.GetOriTime())/info->time;
        if(count>0)
        {
            PLAYERINSTANCE->SetPhysical(PLAYERINSTANCE->GetPhysical()+(count*info->offset));
            m_StartTime.Reset();
        }
    }
    OBINSTANCE->PostOberserver(this, MSG_SLEEPUPDATE, 0);
}
void CoreStatusSleep::OnExit()
{
    OnUpdate();
    NOTIFYCENTER->ClearNotify();
}

CoreStatus::TYPE CoreStatusSleep::GetType()
{
    return SLEEP;
}