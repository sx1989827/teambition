//
//  LeisureTalkLove.cpp
//  Core
//
//  Created by 孙昕 on 14/11/11.
//
//

#include "LeisureTalkLove.h"
CoreInteraction*  CoreLeisureTalkLove::CreateInstance()
{
    return new CoreLeisureTalkLove;
}

void CoreLeisureTalkLove::Update()
{
    
}

bool CoreLeisureTalkLove::IsNeedEnd()
{
    return false;
}

bool CoreLeisureTalkLove::IsEnd()
{
    return bEnd;
}

CoreInteraction::TYPE CoreLeisureTalkLove::GetType()
{
    return LEISURETALKLOVE;
}