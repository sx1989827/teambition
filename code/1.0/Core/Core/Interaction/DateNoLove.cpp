//
//  DateNoLove.cpp
//  Core
//
//  Created by 孙昕 on 14/11/11.
//
//

#include "DateNoLove.h"
CoreInteraction*  CoreDateNoLove::CreateInstance()
{
    return new CoreDateNoLove;
}

void CoreDateNoLove::Update()
{
    
}

bool CoreDateNoLove::IsNeedEnd()
{
    return true;
}

bool CoreDateNoLove::IsEnd()
{
    return bEnd;
}

CoreInteraction::TYPE CoreDateNoLove::GetType()
{
    return DATENOLOVE;
}