//
//  WorkTalkLove.cpp
//  Core
//
//  Created by 孙昕 on 14/11/11.
//
//

#include "WorkTalkLove.h"
#include "../Person/Player.h"
const double g_dPhysical=-6;
CoreInteraction*  CoreWorkTalkLove::CreateInstance()
{
    return new CoreWorkTalkLove;
}

void CoreWorkTalkLove::Update()
{

}

void CoreWorkTalkLove::Enter()
{
    PLAYERINSTANCE->SetPhysical(PLAYERINSTANCE->GetPhysical()+g_dPhysical);
}

bool CoreWorkTalkLove::TryEnter()
{
    return true;
}

void CoreWorkTalkLove::Leave()
{
    
}


bool CoreWorkTalkLove::IsNeedEnd()
{
    return false;
}

bool CoreWorkTalkLove::IsEnd()
{
    return m_bEnd;
}

CoreInteraction::TYPE CoreWorkTalkLove::GetType()
{
    return WORKTALKLOVE;
}