//
//  LeisureIOINoLove.cpp
//  Core
//
//  Created by 孙昕 on 14/11/11.
//
//

#include "LeisureIOINoLove.h"
CoreInteraction*  CoreLeisureIOINoLove::CreateInstance()
{
    return new CoreLeisureIOINoLove;
}

void CoreLeisureIOINoLove::Update()
{
    
}

void CoreLeisureIOINoLove::Enter()
{
    
}

bool CoreLeisureIOINoLove::TryEnter()
{
    return true;
}

void CoreLeisureIOINoLove::Leave()
{
    
}


bool CoreLeisureIOINoLove::IsNeedEnd()
{
    return false;
}

bool CoreLeisureIOINoLove::IsEnd()
{
    return m_bEnd;
}

CoreInteraction::TYPE CoreLeisureIOINoLove::GetType()
{
    return LEISUREIOINOLOVE;
}