//
//  WorkHelpLove.cpp
//  Core
//
//  Created by 孙昕 on 14/11/11.
//
//

#include "WorkHelpLove.h"
#include "../Person/Player.h"
#include "../Person/Girl.h"
#include "../Status/StatusController.h"
const double g_dPhysical=-3;
const double g_dIOI=3;
CoreInteraction*  CoreWorkHelpLove::CreateInstance()
{
    return new CoreWorkHelpLove;
}

void CoreWorkHelpLove::Update()
{
    if(!m_bEnd)
    {
        if(time(0)-m_StartTime.GetOriTime()>=1800)
        {
            m_bEnd=true;
        }
    }
}

void CoreWorkHelpLove::Enter()
{
}

bool CoreWorkHelpLove::TryEnter()
{
    return true;
}

void CoreWorkHelpLove::Leave()
{
    PLAYERINSTANCE->SetPhysical(PLAYERINSTANCE->GetPhysical()+g_dPhysical);
    GIRLINSTANCE->SetIOI(GIRLINSTANCE->GetIOI()+g_dIOI);
    PLAYERINSTANCE->GetStatusController()->ResetTime(m_StartTime.GetOriTime()+1800);
}


bool CoreWorkHelpLove::IsNeedEnd()
{
    return true;
}

bool CoreWorkHelpLove::IsEnd()
{
    return m_bEnd;
}

CoreInteraction::TYPE CoreWorkHelpLove::GetType()
{
    return WORKHELPLOVE;
}





