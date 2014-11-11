//
//  WorkMeetNoLove.cpp
//  Core
//
//  Created by 孙昕 on 14/11/11.
//
//

#include "WorkMeetNoLove.h"
CoreInteraction*  CoreWorkMeetNoLove::CreateInstance()
{
    return new CoreWorkMeetNoLove;
}

void CoreWorkMeetNoLove::Update()
{
    
}

bool CoreWorkMeetNoLove::IsEnd()
{
    return false;
}

CoreInteraction::TYPE CoreWorkMeetNoLove::GetType()
{
    return WORKMEETNOLOVE;
}