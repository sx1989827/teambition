//
//  WorkTalkNoLove.cpp
//  Core
//
//  Created by 孙昕 on 14/11/11.
//
//

#include "WorkTalkNoLove.h"
#include "../Person/Player.h"
const double g_dPhysical=-8;
const double  g_dPrePhysical=10;
CoreInteraction*  CoreWorkTalkNoLove::CreateInstance()
{
    return new CoreWorkTalkNoLove;
}

void CoreWorkTalkNoLove::Update()
{

}

void CoreWorkTalkNoLove::Enter()
{
    PLAYERINSTANCE->SetPhysical(PLAYERINSTANCE->GetPhysical()+g_dPhysical);
}

bool CoreWorkTalkNoLove::TryEnter()
{
    if(PLAYERINSTANCE->GetPhysical()>=g_dPrePhysical)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void CoreWorkTalkNoLove::Leave()
{
    
}


bool CoreWorkTalkNoLove::IsNeedEnd()
{
    return false;
}

bool CoreWorkTalkNoLove::IsEnd()
{
    return m_bEnd;
}

CoreInteraction::TYPE CoreWorkTalkNoLove::GetType()
{
    return WORKTALKNOLOVE;
}