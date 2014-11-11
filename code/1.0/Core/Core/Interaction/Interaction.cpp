//
//  Interaction.cpp
//  Core
//
//  Created by 孙昕 on 14/10/22.
//
//

#include "Interaction.h"
#include "WorkMeetNoLove.h"
bool CoreInteraction::bInit=false;
std::map<CoreInteraction::TYPE, CoreInteraction::Func> CoreInteraction::MapFunc;

CoreInteraction* CoreInteraction::CreateInstance(TYPE type)
{
    if(!bInit)
    {
        bInit=0;
        MapFunc[WORKMEETNOLOVE]=CoreWorkMeetNoLove::CreateInstance;
    }
    if(MapFunc.find(type)!=MapFunc.end())
    {
        return MapFunc[type]();
    }
    else
    {
        return 0;
    }
}








