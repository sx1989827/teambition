//
//  DatePark.cpp
//  Core
//
//  Created by 孙昕 on 14/11/13.
//
//

#include "DatePark.h"
#include "../../Person/Player.h"
#include "../../Person/Girl.h"
const double g_time=10;
static double g_IOI=1.5;
const double g_dPhysical=-1;
void CoreDatePark::Enter()
{
    SetOldPlace(PLAYERINSTANCE->GetPlace());
    if(GIRLINSTANCE->GetGirlType()==CoreGirl::MAID)
    {
        g_IOI=1;
    }
    else if(GIRLINSTANCE->GetGirlType()==CoreGirl::QUEEN)
    {
        g_IOI=0.5;
    }
    PLAYERINSTANCE->SetPlace("游乐场");

}

bool CoreDatePark::TryEnter()
{
    if(PLAYERINSTANCE->GetPhysical()>=(m_bIOI?50:60))
    {
        return true;
    }
    else
    {
        return false;
    }

}

void CoreDatePark::Update()
{
    if(!m_bEnd)
    {
        if(time(0)-m_StartTime.GetOriTime()>=3600)
        {
            m_bEnd=true;
        }
        if(time(0)-m_FlagTime.GetOriTime()>=g_time*60)
        {
            m_FlagTime.Reset();
            PLAYERINSTANCE->SetPhysical(PLAYERINSTANCE->GetPhysical()+g_dPhysical);
            GIRLINSTANCE->SetIOI(GIRLINSTANCE->GetIOI()+g_IOI);
        }
    }

}

void CoreDatePark::Leave()
{
    PLAYERINSTANCE->SetPlace(GetOldPlace());
}

bool CoreDatePark::IsEnd()
{
    return m_bEnd;
}


CoreDateBase::TYPE CoreDatePark::GetType()
{
    return PARK;
}