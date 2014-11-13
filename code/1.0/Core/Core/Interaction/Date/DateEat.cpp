//
//  DateEat.cpp
//  Core
//
//  Created by 孙昕 on 14/11/13.
//
//

#include "DateEat.h"
#include "../../Person/Player.h"
#include "../../Person/Girl.h"
const double g_time=10;
const double g_IOIMin=0.6;
const double g_IOIMax=1;
const double g_dPhysical=1;
bool CoreDateEat::Enter()
{
    if(PLAYERINSTANCE->GetPhysical()>=20)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void CoreDateEat::Update()
{
    if(!m_bEnd)
    {
        if(time(0)-m_StartTime.GetOriTime()>=1800)
        {
            m_bEnd=true;
        }
        if(time(0)-m_FlagTime.GetOriTime()>=600)
        {
            m_FlagTime.Reset();
            PLAYERINSTANCE->SetPhysical(PLAYERINSTANCE->GetPhysical()+g_dPhysical);
            GIRLINSTANCE->SetIOI(GIRLINSTANCE->GetIOI()+GetIOIValue(g_IOIMin, g_IOIMax));
        }
    }
}

void CoreDateEat::Leave()
{
    
}

bool CoreDateEat::IsEnd()
{
    return m_bEnd;
}

CoreDateBase::TYPE CoreDateEat::GetType()
{
    return EAT;
}







