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

CoreWorkMeetNoLove::CoreWorkMeetNoLove()
{
    bEnd=false;
}

bool CoreWorkMeetNoLove::IsNeedEnd()
{
    return false;
}

void CoreWorkMeetNoLove::Update()
{
    
}

bool CoreWorkMeetNoLove::IsEnd()
{
    return bEnd;
}

CoreInteraction::TYPE CoreWorkMeetNoLove::GetType()
{
    return WORKMEETNOLOVE;
}