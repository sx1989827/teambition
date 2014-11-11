//
//  WorkHelpNoLove.cpp
//  Core
//
//  Created by 孙昕 on 14/11/11.
//
//

#include "WorkHelpNoLove.h"
CoreInteraction*  CoreWorkHelpNoLove::CreateInstance()
{
    return new CoreWorkHelpNoLove;
}

void CoreWorkHelpNoLove::Update()
{
    
}

bool CoreWorkHelpNoLove::IsEnd()
{
    return false;
}

CoreInteraction::TYPE CoreWorkHelpNoLove::GetType()
{
    return WORKHELPNOLOVE;
}