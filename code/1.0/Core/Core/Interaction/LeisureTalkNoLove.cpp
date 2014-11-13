//
//  LeisureTalkNoLove.cpp
//  Core
//
//  Created by 孙昕 on 14/11/11.
//
//

#include "LeisureTalkNoLove.h"
CoreInteraction*  CoreLeisureTalkNoLove::CreateInstance()
{
    return new CoreLeisureTalkNoLove;
}

void CoreLeisureTalkNoLove::Update()
{
    
}

bool CoreLeisureTalkNoLove::IsNeedEnd()
{
    return false;
}

bool CoreLeisureTalkNoLove::IsEnd()
{
    return bEnd;
}

CoreInteraction::TYPE CoreLeisureTalkNoLove::GetType()
{
    return LEISURETALKNOLOVE;
}