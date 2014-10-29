//
//  Notify.cpp
//  Core
//
//  Created by 孙昕 on 14-10-14.
//
//

#include "Notify.h"
#include <string.h>
char CoreNotify::cID[100];
long CoreNotify::pos=0;
CoreNotify::CoreNotify()
{
    memset((void*)cID, 0, sizeof(char)*100);
}
CoreNotify::~CoreNotify()
{
    
}
long CoreNotify::CreateNotify(sNotify* pNotify,long lStatus)
{
    int count=0;
    while (cID[pos]!=0) {
        pos++;
        count++;
        if(pos>=100)
        {
            pos=0;
        }
        if(count==100)
        {
            return -1;
        }
    }
    pNotify->id=pos;
    cID[pos]=1;
    m_Vector.push_back(*pNotify);
    if(lStatus==2)
    {
        auto it=std::find(m_AvailableWorkVec.begin(), m_AvailableWorkVec.end(), pNotify->type);
        if(it!=m_AvailableWorkVec.end())
        {
            m_AvailableWorkVec.erase(it);
        }
    }
    else if(lStatus==0)
    {
        auto it=std::find(m_AvailableLeisureVec.begin(), m_AvailableLeisureVec.end(), pNotify->type);
        if(it!=m_AvailableLeisureVec.end())
        {
            m_AvailableLeisureVec.erase(it);
        }
    }
    return pos;
}


sNotify CoreNotify::AdjustNotify()
{
    std::vector<sNotify> vec;
    for(auto it=m_Vector.begin();it!=m_Vector.end();)
    {
        if(CoreTime::DiffNowTime(it->sec)>=0)
        {
            vec.push_back(*it);
            it=vec.erase(it);
        }
        else
        {
            it++;
        }
    }
    sNotify noti;
    noti.sec=0;
    for(auto it=vec.begin();it!=vec.end();it++)
    {
        if(it->type==sNotify::CALL)
        {
            return *it;
        }
        else if (it->type==sNotify::DATEEND)
        {
            return *it;
        }
        else if(it->type!=sNotify::WORKEVENT && it->type!=sNotify::LEISUREEVENT)
        {
            if(it->sec>=noti.sec)
            {
                noti=*it;
            }
        }
    }
    return noti;
}

sNotify::TYPE CoreNotify::GetAvailableNotify(long lStatus)
{
    sNotify::TYPE type;
    if(lStatus==0 && m_AvailableLeisureVec.size()>0)
    {
        type=m_AvailableLeisureVec[random()%m_AvailableLeisureVec.size()];
    }
    else if (lStatus==2 && m_AvailableWorkVec.size()>0)
    {
        type=m_AvailableWorkVec[random()%m_AvailableWorkVec.size()];
    }
    else
    {
        type=sNotify::NONE;
    }
    return type;
}

void CoreNotify::Serializ(node* out)
{
    node* NotiNode=out->getXml()->createnode("Notify");
    node* work=NotiNode->getXml()->createnode("work");
    for(int i=0;i<m_AvailableWorkVec.size();i++)
    {
        node* item=NotiNode->getXml()->createnode("item");
        item->setattr("type", (long)m_AvailableWorkVec[i]);
        work->appned(item);
    }
    NotiNode->appned(work);
    node* leisure=NotiNode->getXml()->createnode("leisure");
    for(int i=0;i<m_AvailableLeisureVec.size();i++)
    {
        node* item=NotiNode->getXml()->createnode("item");
        item->setattr("type", (long)m_AvailableLeisureVec[i]);
        leisure->appned(item);
    }
    NotiNode->appned(leisure);
    out->appned(NotiNode);
}
void CoreNotify::UnSerializ(node* in)
{
    node* NotiNode=in->select("/Notify")->item(0);
    nodecollect *col=NotiNode->select("/work/item");
    for(int i=0;i<col->getcount();i++)
    {
        m_AvailableWorkVec.push_back((sNotify::TYPE)atol(col->item(i)->getattr("type").data()));
    }
    col=NotiNode->select("/leisure/item");
    for(int i=0;i<col->getcount();i++)
    {
        m_AvailableLeisureVec.push_back((sNotify::TYPE)atol(col->item(i)->getattr("type").data()));
    }
}

void CoreNotify::Reset(bool bLove)
{
    std::vector<sNotify::TYPE>().swap(m_AvailableLeisureVec);
    std::vector<sNotify::TYPE>().swap(m_AvailableWorkVec);
    if(bLove)
    {
        m_AvailableWorkVec.push_back(sNotify::WORKIOI);
        m_AvailableWorkVec.push_back(sNotify::WORKIOI);
        m_AvailableWorkVec.push_back(sNotify::WORKHELP);
        m_AvailableWorkVec.push_back(sNotify::WORKEVENT);
        m_AvailableLeisureVec.push_back(sNotify::LEISUREIOI);
        m_AvailableLeisureVec.push_back(sNotify::LEISUREIOI);
        m_AvailableLeisureVec.push_back(sNotify::LEISUREDATE);
        m_AvailableLeisureVec.push_back(sNotify::LEISUREDATE);
        m_AvailableLeisureVec.push_back(sNotify::LEISUREEVENT);
    }
    else
    {
        m_AvailableWorkVec.push_back(sNotify::WORKHELP);
        m_AvailableWorkVec.push_back(sNotify::WORKIOI);
        m_AvailableWorkVec.push_back(sNotify::WORKMEET);
        m_AvailableWorkVec.push_back(sNotify::WORKEVENT);
        m_AvailableLeisureVec.push_back(sNotify::LEISUREEVENT);
        m_AvailableLeisureVec.push_back(sNotify::LEISUREIOI);
    }
}


















