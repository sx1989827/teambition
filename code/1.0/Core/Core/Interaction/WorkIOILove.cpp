//
//  WorkIOILove.cpp
//  Core
//
//  Created by 孙昕 on 14/11/11.
//
//

#include "WorkIOILove.h"
CoreInteraction*  CoreWorkIOILove::CreateInstance()
{
    return new CoreWorkIOILove;
}

void CoreWorkIOILove::Update()
{
    
}

bool CoreWorkIOILove::IsEnd()
{
    return false;
}

CoreInteraction::TYPE CoreWorkIOILove::GetType()
{
    return WORKIOILOVE;
}