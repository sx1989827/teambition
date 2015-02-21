//
//  DateWalk.cpp
//  Core
//
//  Created by 孙昕 on 14/11/13.
//
//

#include "DateWalk.h"
#include "../../Person/Player.h"
#include "../../Person/Girl.h"
const double g_time=10;
static double g_IOI=1;

const double g_dPhysical=-1;
void CoreDateWalk::Enter()
{
    SetOldPlace(PLAYERINSTANCE->GetPlace());
    if(GIRLINSTANCE->GetGirlType()==CoreGirl::MAID)
    {
        g_IOI=1.2;
    }
    else if(GIRLINSTANCE->GetGirlType()==CoreGirl::QUEEN)
    {
        g_IOI=1.5;
    }
    PLAYERINSTANCE->SetPlace("公园");
}

bool CoreDateWalk::TryEnter()
{
    if(PLAYERINSTANCE->GetPhysical()>=(m_bIOI?40:50))
    {
        return true;
    }
    else
    {
        return false;
    }

}

void CoreDateWalk::Update()
{
    if(!m_bEnd)
    {
        if(time(0)-m_StartTime.GetOriTime()>=2400)
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

void CoreDateWalk::Leave()
{
    PLAYERINSTANCE->SetPlace(GetOldPlace());
}

bool CoreDateWalk::IsEnd()
{
    return m_bEnd;
}

CoreDateBase::TYPE CoreDateWalk::GetType()
{
    return WALK;
}