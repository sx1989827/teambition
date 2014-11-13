//
//  WorkHelpLove.cpp
//  Core
//
//  Created by 孙昕 on 14/11/11.
//
//

#include "WorkHelpLove.h"
CoreInteraction*  CoreWorkHelpLove::CreateInstance()
{
    return new CoreWorkHelpLove;
}

void CoreWorkHelpLove::Update()
{
    
}

bool CoreWorkHelpLove::IsNeedEnd()
{
    return true;
}

bool CoreWorkHelpLove::IsEnd()
{
    return bEnd;
}

CoreInteraction::TYPE CoreWorkHelpLove::GetType()
{
    return WORKHELPLOVE;
}





