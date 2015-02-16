//
//  DateFilm.cpp
//  Core
//
//  Created by 孙昕 on 14/11/13.
//
//

#include "DateFilm.h"
#include "../../Person/Player.h"
#include "../../Person/Girl.h"
const double g_time=10;
double g_IOIMin=0.6;
double g_IOIMax=1;
const double g_dPhysical=1;
void CoreDateFilm::Enter()
{
    if(GIRLINSTANCE->GetGirlType()==CoreGirl::MAID)
    {
        g_IOIMin=0.6;
        g_IOIMax=0.8;
    }
    else if(GIRLINSTANCE->GetGirlType()==CoreGirl::QUEEN)
    {
        g_IOIMin=0.8;
        g_IOIMax=1.6;
    }
    PLAYERINSTANCE->SetPlace("电影院");
}

bool CoreDateFilm::TryEnter()
{
    if(PLAYERINSTANCE->GetPhysical()>=(m_bIOI?30:40))
    {
        return true;
    }
    else
    {
        return false;
    }

}

void CoreDateFilm::Update()
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
            GIRLINSTANCE->SetIOI(GIRLINSTANCE->GetIOI()+GetIOIValue(g_IOIMin, g_IOIMax));
        }
    }

}

void CoreDateFilm::Leave()
{

}

bool CoreDateFilm::IsEnd()
{
    return m_bEnd;
}

CoreDateBase::TYPE CoreDateFilm::GetType()
{
    return FILM;
}