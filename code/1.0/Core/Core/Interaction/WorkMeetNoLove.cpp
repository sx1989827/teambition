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


bool CoreWorkMeetNoLove::IsNeedEnd()
{
    return false;
}

void CoreWorkMeetNoLove::Update()
{
    
}

void CoreWorkMeetNoLove::Enter()
{

}

bool CoreWorkMeetNoLove::TryEnter()
{
    return true;
}

void CoreWorkMeetNoLove::Leave()
{
    
}

bool CoreWorkMeetNoLove::IsEnd()
{
    return m_bEnd;
}

CoreInteraction::TYPE CoreWorkMeetNoLove::GetType()
{
    return WORKMEETNOLOVE;
}