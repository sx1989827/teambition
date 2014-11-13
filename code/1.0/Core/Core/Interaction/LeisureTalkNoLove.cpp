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
CoreInteraction*  CoreLeisureTalkNoLove::CreateInstance()
{
    return new CoreLeisureTalkNoLove;
}

void CoreLeisureTalkNoLove::Update()
{

}

bool CoreLeisureTalkNoLove::Enter()
{
    PLAYERINSTANCE->SetPhysical(PLAYERINSTANCE->GetPhysical()+g_dPhysical);
    return true;
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