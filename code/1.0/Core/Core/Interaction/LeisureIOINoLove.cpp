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

bool CoreLeisureIOINoLove::IsEnd()
{
    return false;
}

CoreInteraction::TYPE CoreLeisureIOINoLove::GetType()
{
    return LEISUREIOINOLOVE;
}