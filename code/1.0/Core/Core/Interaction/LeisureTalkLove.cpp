//
//  LeisureTalkLove.cpp
//  Core
//
//  Created by 孙昕 on 14/11/11.
//
//

#include "LeisureTalkLove.h"
#include "../Person/Player.h"
const double g_dPhysical=-4;
const double g_dPrePhysical=5;
CoreInteraction*  CoreLeisureTalkLove::CreateInstance()
{
    return new CoreLeisureTalkLove;
}

void CoreLeisureTalkLove::Update()
{

}

void CoreLeisureTalkLove::Enter()
{
    PLAYERINSTANCE->SetPhysical(PLAYERINSTANCE->GetPhysical()+g_dPhysical);
}

bool CoreLeisureTalkLove::TryEnter()
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

void CoreLeisureTalkLove::Leave()
{
    
}


bool CoreLeisureTalkLove::IsNeedEnd()
{
    return false;
}

bool CoreLeisureTalkLove::IsEnd()
{
    return m_bEnd;
}

CoreInteraction::TYPE CoreLeisureTalkLove::GetType()
{
    return LEISURETALKLOVE;
}