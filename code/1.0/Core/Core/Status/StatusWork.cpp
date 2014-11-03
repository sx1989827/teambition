//
//  StatusWork.cpp
//  Core
//
//  Created by 孙昕 on 14/10/24.
//
//

#include "StatusWork.h"
#include "../Person/Player.h"
#include "../logic/notify/Notify.h"
void CoreStatusWork::OnEnter()
{
    m_StartTime.Reset();
}
void CoreStatusWork::OnUpdate()
{
    if(PLAYERINSTANCE->IsInteraction())
    {
        
    }
    else
    {
        const  sPlayInfo *info=PLAYERINSTANCE->GetPhysicalInfo(CoreStatus::WORK);
        if(info)
        {
            long count=(time(0)-m_StartTime.GetOriTime())/info->time;
            if(count>0)
            {
                PLAYERINSTANCE->SetPhysical(PLAYERINSTANCE->GetPhysical()+(count*info->offset));
                m_StartTime.Reset();
            }
        }
        info=PLAYERINSTANCE->GetMoneyInfo(CoreStatus::WORK);
        if(info)
        {
            long count=(time(0)-m_StartTime.GetOriTime())/info->time;
            if(count>0)
            {
                PLAYERINSTANCE->SetMoney(PLAYERINSTANCE->GetMoney()+(count*info->offset));
                m_StartTime.Reset();
            }
        }
    }
}

void CoreStatusWork::OnExit()
{
    OnUpdate();
    NOTIFYCENTER->ClearNotify();
}

CoreStatus::TYPE CoreStatusWork::GetType()
{
    return WORK;
}







