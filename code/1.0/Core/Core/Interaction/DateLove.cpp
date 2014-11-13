//
//  DateLove.cpp
//  Core
//
//  Created by 孙昕 on 14/11/11.
//
//

#include "DateLove.h"
CoreInteraction*  CoreDateLove::CreateInstance()
{
    return new CoreDateLove;
}

void CoreDateLove::Update()
{
    
}

bool CoreDateLove::IsNeedEnd()
{
    return true;
}

bool CoreDateLove::IsEnd()
{
    return bEnd;
}

CoreInteraction::TYPE CoreDateLove::GetType()
{
    return DATELOVE;
}