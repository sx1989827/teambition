//
//  Interaction.cpp
//  Core
//
//  Created by 孙昕 on 14/10/22.
//
//

#include "Interaction.h"
#include "WorkMeetNoLove.h"
#include "WorkIOINoLove.h"
#include "WorkHelpNoLove.h"
#include "WorkTalkNoLove.h"
#include "WorkTalkLove.h"
#include "WorkIOILove.h"
#include "WorkHelpLove.h"
#include "LeisureIOINoLove.h"
#include "LeisureTalkNoLove.h"
#include "LeisureIOILove.h"
#include "LeisureTalkLove.h"
#include "DateIOI.h"
#include "DateNoLove.h"
#include "DateLove.h"
bool CoreInteraction::bInit=false;
std::map<CoreInteraction::TYPE, CoreInteraction::Func> CoreInteraction::MapFunc;

CoreInteraction* CoreInteraction::CreateInstance(TYPE type)
{
    if(!bInit)
    {
        bInit=0;
        MapFunc[WORKMEETNOLOVE]=CoreWorkMeetNoLove::CreateInstance;
        MapFunc[WORKIOINOLOVE]=CoreWorkIOINoLove::CreateInstance;
        MapFunc[WORKHELPNOLOVE]=CoreWorkHelpNoLove::CreateInstance;
        MapFunc[WORKTALKNOLOVE]=CoreWorkTalkNoLove::CreateInstance;
        MapFunc[WORKTALKLOVE]=CoreWorkTalkLove::CreateInstance;
        MapFunc[WORKIOILOVE]=CoreWorkIOILove::CreateInstance;
        MapFunc[WORKHELPLOVE]=CoreWorkHelpLove::CreateInstance;
        MapFunc[LEISUREIOINOLOVE]=CoreLeisureIOINoLove::CreateInstance;
        MapFunc[LEISURETALKNOLOVE]=CoreLeisureTalkNoLove::CreateInstance;
        MapFunc[LEISUREIOILOVE]=CoreLeisureIOILove::CreateInstance;
        MapFunc[LEISURETALKLOVE]=CoreLeisureTalkLove::CreateInstance;
        MapFunc[DATEIOI]=CoreDateIOI::CreateInstance;
        MapFunc[DATENOLOVE]=CoreDateNoLove::CreateInstance;
        MapFunc[DATELOVE]=CoreDateLove::CreateInstance;
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

CoreInteraction::CoreInteraction()
{
    m_bEnd=false;
}






