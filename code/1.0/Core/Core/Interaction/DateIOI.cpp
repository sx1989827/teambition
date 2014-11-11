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

bool CoreDateIOI::IsEnd()
{
    return false;
}

CoreInteraction::TYPE CoreDateIOI::GetType()
{
    return DATEIOI;
}