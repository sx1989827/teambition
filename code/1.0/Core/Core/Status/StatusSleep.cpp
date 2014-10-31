//
//  StatusSleep.cpp
//  Core
//
//  Created by 孙昕 on 14/10/24.
//
//

#include "StatusSleep.h"
void CoreStatusSleep::OnEnter(CorePlayer *pPlayer)
{
    m_StartTime.Reset();
    
}
void CoreStatusSleep::OnUpdate(CorePlayer *pPlayer)
{
    
}
void CoreStatusSleep::OnExit(CorePlayer* pPlayer)
{
    
}

CoreStatus::TYPE CoreStatusSleep::GetType()
{
    return SLEEP;
}