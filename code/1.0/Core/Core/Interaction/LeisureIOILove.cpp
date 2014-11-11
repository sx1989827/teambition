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

bool CoreLeisureIOILove::IsEnd()
{
    return false;
}

CoreInteraction::TYPE CoreLeisureIOILove::GetType()
{
    return LEISUREIOILOVE;
}