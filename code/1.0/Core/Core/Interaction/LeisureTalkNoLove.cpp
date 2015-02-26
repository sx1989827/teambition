//
//  LeisureTalkNoLove.cpp
//  Core
//
//  Created by 孙昕 on 14/11/11.
//
//

#include "LeisureTalkNoLove.h"
#include "../Person/Player.h"
const double g_dPhysical=-4;
const double g_dPrePhysical=10;
CoreInteraction*  CoreLeisureTalkNoLove::CreateInstance()
{
    return new CoreLeisureTalkNoLove;
}

void CoreLeisureTalkNoLove::Update()
{

}

void CoreLeisureTalkNoLove::Enter()
{
    PLAYERINSTANCE->SetPhysical(PLAYERINSTANCE->GetPhysical()+g_dPhysical);
}

bool CoreLeisureTalkNoLove::TryEnter()
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

void CoreLeisureTalkNoLove::Leave()
{
    
}


bool CoreLeisureTalkNoLove::IsNeedEnd()
{
    return false;
}

bool CoreLeisureTalkNoLove::IsEnd()
{
    return m_bEnd;
}

CoreInteraction::TYPE CoreLeisureTalkNoLove::GetType()
{
    return LEISURETALKNOLOVE;
}