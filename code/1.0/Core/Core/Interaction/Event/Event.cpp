//
//  Event.cpp
//  Core
//
//  Created by 孙昕 on 14/11/24.
//
//

#include "Event.h"
#include "../../Person/Player.h"
#include "../../Status/StatusController.h"
#include "../../Person/Girl.h"
CoreEvent::CoreEvent()
{
    xml x;
    x.loadfile(EVENTFILE);
    nodecollect *nc=x.select("//item");
    for(long i=0;i<nc->getcount();i++)
    {
        sEvent eve;
        eve.strDes=nc->item(i)->getattr("des");
        eve.strMood=nc->item(i)->getattr("mood");
        eve.dLoliVal=atof(nc->item(i)->getattr("loli").data());
        eve.dMaidVal=atof(nc->item(i)->getattr("maid").data());
        eve.dQueenVal=atoi(nc->item(i)->getattr("queen").data());
        std::string status=nc->item(i)->getattr("status");
        if(status=="work")
        {
            m_VecWorkEvent.push_back(eve);
        }
        else if (status=="leisure")
        {
            m_VecLeisureEvent.push_back(eve);
        }
    }
    delete nc;
}

sEvent CoreEvent::GetAvaliableEvent()
{
    sEvent eve;
    if(PLAYERINSTANCE->GetStatusController()->GetStatus()==CoreStatus::WORK)
    {
        if(m_VecWorkEvent.empty())
        {
            xml x;
            x.loadfile(EVENTFILE);
            nodecollect *nc=x.select("//item");
            for(long i=0;i<nc->getcount();i++)
            {
                sEvent eve;
                eve.strDes=nc->item(i)->getattr("des");
                eve.strMood=nc->item(i)->getattr("mood");
                eve.dLoliVal=atof(nc->item(i)->getattr("loli").data());
                eve.dMaidVal=atof(nc->item(i)->getattr("maid").data());
                eve.dQueenVal=atoi(nc->item(i)->getattr("queen").data());
                std::string status=nc->item(i)->getattr("status");
                if(status=="work")
                {
                    m_VecWorkEvent.push_back(eve);
                }
            }
            delete nc;
        }
        long i=random()%m_VecWorkEvent.size();
        eve=m_VecWorkEvent[i];
        m_VecWorkEvent.erase(m_VecWorkEvent.begin()+i);
    }
    else if(PLAYERINSTANCE->GetStatusController()->GetStatus()==CoreStatus::LEISURE)
    {
        if(m_VecLeisureEvent.empty())
        {
            xml x;
            x.loadfile(EVENTFILE);
            nodecollect *nc=x.select("//item");
            for(long i=0;i<nc->getcount();i++)
            {
                sEvent eve;
                eve.strDes=nc->item(i)->getattr("des");
                eve.strMood=nc->item(i)->getattr("mood");
                eve.dLoliVal=atof(nc->item(i)->getattr("loli").data());
                eve.dMaidVal=atof(nc->item(i)->getattr("maid").data());
                eve.dQueenVal=atoi(nc->item(i)->getattr("queen").data());
                std::string status=nc->item(i)->getattr("status");
                if(status=="leisure")
                {
                    m_VecLeisureEvent.push_back(eve);
                }
            }
            delete nc;
        }
        long i=random()%m_VecLeisureEvent.size();
        eve=m_VecLeisureEvent[i];
        m_VecLeisureEvent.erase(m_VecLeisureEvent.begin()+i);
    }
    return eve;
}

void  CoreEvent::HandleEvent(sEvent eve)
{
    sMood mood;
    mood.strDes=eve.strDes;
    mood.strMood=eve.strMood;
    if(GIRLINSTANCE->GetGirlType()==CoreGirl::LOLI)
    {
        mood.lOffset=eve.dLoliVal;
    }
    else if (GIRLINSTANCE->GetGirlType()==CoreGirl::MAID)
    {
        mood.lOffset=eve.dMaidVal;
    }
    else if (GIRLINSTANCE->GetGirlType()==CoreGirl::QUEEN)
    {
        mood.lOffset=eve.dQueenVal;
    }
    GIRLINSTANCE->GetMood()->Transfer(&mood);

}


















