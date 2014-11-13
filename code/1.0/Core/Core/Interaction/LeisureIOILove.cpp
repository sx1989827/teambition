//
//  LeisureIOILove.cpp
//  Core
//
//  Created by 孙昕 on 14/11/11.
//
//

#include "LeisureIOILove.h"
CoreInteraction*  CoreLeisureIOILove::CreateInstance()
{
    return new CoreLeisureIOILove;
}

void CoreLeisureIOILove::Update()
{
    
}

bool CoreLeisureIOILove::IsNeedEnd()
{
    return false;
}

bool CoreLeisureIOILove::IsEnd()
{
    return bEnd;
}

CoreInteraction::TYPE CoreLeisureIOILove::GetType()
{
    return LEISUREIOILOVE;
}