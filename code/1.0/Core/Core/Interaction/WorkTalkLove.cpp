//
//  WorkTalkLove.cpp
//  Core
//
//  Created by 孙昕 on 14/11/11.
//
//

#include "WorkTalkLove.h"
CoreInteraction*  CoreWorkTalkLove::CreateInstance()
{
    return new CoreWorkTalkLove;
}

void CoreWorkTalkLove::Update()
{
    
}

bool CoreWorkTalkLove::IsEnd()
{
    return false;
}

CoreInteraction::TYPE CoreWorkTalkLove::GetType()
{
    return WORKTALKLOVE;
}