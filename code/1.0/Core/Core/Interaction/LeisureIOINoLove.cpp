//
//  LeisureIOINoLove.cpp
//  Core
//
//  Created by 孙昕 on 14/11/11.
//
//

#include "LeisureIOINoLove.h"
CoreInteraction*  CoreLeisureIOINoLove::CreateInstance()
{
    return new CoreLeisureIOINoLove;
}

void CoreLeisureIOINoLove::Update()
{
    
}

bool CoreLeisureIOINoLove::IsNeedEnd()
{
    return false;
}

bool CoreLeisureIOINoLove::IsEnd()
{
    return bEnd;
}

CoreInteraction::TYPE CoreLeisureIOINoLove::GetType()
{
    return LEISUREIOINOLOVE;
}