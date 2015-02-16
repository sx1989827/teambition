//
//  WorkIOINoLove.cpp
//  Core
//
//  Created by 孙昕 on 14/11/11.
//
//

#include "WorkIOINoLove.h"
CoreInteraction*  CoreWorkIOINoLove::CreateInstance()
{
    return new CoreWorkIOINoLove;
}

void CoreWorkIOINoLove::Update()
{
    
}

void CoreWorkIOINoLove::Enter()
{
    
}

bool CoreWorkIOINoLove::TryEnter()
{
    return true;
}

void CoreWorkIOINoLove::Leave()
{
    
}


bool CoreWorkIOINoLove::IsNeedEnd()
{
    return false;
}

bool CoreWorkIOINoLove::IsEnd()
{
    return m_bEnd;
}

CoreInteraction::TYPE CoreWorkIOINoLove::GetType()
{
    return WORKIOINOLOVE;
}