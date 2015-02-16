//
//  LeisureIOILove.cpp
//  Core
//
//  Created by 孙昕 on 14/11/11.
//
//

#include "LeisureIOILove.h"
CoreInteraction*  CoreLeisureIOILove::CreateInstance()
{
    return new CoreLeisureIOILove;
}

void CoreLeisureIOILove::Update()
{
    
}

void CoreLeisureIOILove::Enter()
{
  
}

bool CoreLeisureIOILove::TryEnter()
{
    return true;
}

void CoreLeisureIOILove::Leave()
{
    
}


bool CoreLeisureIOILove::IsNeedEnd()
{
    return false;
}

bool CoreLeisureIOILove::IsEnd()
{
    return m_bEnd;
}

CoreInteraction::TYPE CoreLeisureIOILove::GetType()
{
    return LEISUREIOILOVE;
}