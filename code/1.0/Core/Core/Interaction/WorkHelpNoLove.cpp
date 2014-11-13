//
//  WorkHelpNoLove.cpp
//  Core
//
//  Created by 孙昕 on 14/11/11.
//
//

#include "WorkHelpNoLove.h"
#include "../Person/Player.h"
#include "../Person/Girl.h"
#include "../Status/StatusController.h"
const double g_dPhysical=-5;
const double g_dIOI=5;
CoreInteraction*  CoreWorkHelpNoLove::CreateInstance()
{
    return new CoreWorkHelpNoLove;
}

void CoreWorkHelpNoLove::Update()
{
    if(!bEnd)
    {
        if(time(0)-m_StartTime.GetOriTime()>=1800)
        {
            bEnd=true;
            PLAYERINSTANCE->SetPhysical(PLAYERINSTANCE->GetPhysical()+g_dPhysical);
            GIRLINSTANCE->SetIOI(GIRLINSTANCE->GetIOI()+g_dIOI);
            PLAYERINSTANCE->GetStatusController()->ResetTime(m_StartTime.GetOriTime()+1800);
        }
    }
}

bool CoreWorkHelpNoLove::IsEnd()
{
    return bEnd;
}

bool CoreWorkHelpNoLove::IsNeedEnd()
{
    return true;
}

CoreInteraction::TYPE CoreWorkHelpNoLove::GetType()
{
    return WORKHELPNOLOVE;
}





