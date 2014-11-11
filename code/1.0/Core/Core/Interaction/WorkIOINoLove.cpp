//
//  WorkIOINoLove.cpp
//  Core
//
//  Created by 孙昕 on 14/11/11.
//
//

#include "WorkIOINoLove.h"
CoreInteraction*  CoreWorkIOINoLove::CreateInstance()
{
    return new CoreWorkIOINoLove;
}

void CoreWorkIOINoLove::Update()
{
    
}

bool CoreWorkIOINoLove::IsEnd()
{
    return false;
}

CoreInteraction::TYPE CoreWorkIOINoLove::GetType()
{
    return WORKIOINOLOVE;
}