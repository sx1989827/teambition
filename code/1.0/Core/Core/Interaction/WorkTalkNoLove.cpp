//
//  WorkTalkNoLove.cpp
//  Core
//
//  Created by 孙昕 on 14/11/11.
//
//

#include "WorkTalkNoLove.h"
CoreInteraction*  CoreWorkTalkNoLove::CreateInstance()
{
    return new CoreWorkTalkNoLove;
}

void CoreWorkTalkNoLove::Update()
{
    
}

bool CoreWorkTalkNoLove::IsNeedEnd()
{
    return false;
}

bool CoreWorkTalkNoLove::IsEnd()
{
    return bEnd;
}

CoreInteraction::TYPE CoreWorkTalkNoLove::GetType()
{
    return WORKTALKNOLOVE;
}