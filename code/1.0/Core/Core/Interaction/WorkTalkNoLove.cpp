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

bool CoreWorkTalkNoLove::IsEnd()
{
    return false;
}

CoreInteraction::TYPE CoreWorkTalkNoLove::GetType()
{
    return WORKTALKNOLOVE;
}