//
//  DateIOI.cpp
//  Core
//
//  Created by 孙昕 on 14/11/11.
//
//

#include "DateIOI.h"
CoreInteraction*  CoreDateIOI::CreateInstance()
{
    return new CoreDateIOI;
}

void CoreDateIOI::Update()
{
    
}

bool CoreDateIOI::Enter()
{
    
}

void CoreDateIOI::Leave()
{
    
}


bool CoreDateIOI::IsNeedEnd()
{
    return true;
}


bool CoreDateIOI::IsEnd()
{
    return m_bEnd;
}

CoreInteraction::TYPE CoreDateIOI::GetType()
{
    return DATEIOI;
}