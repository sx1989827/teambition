//
//  Notify.cpp
//  Core
//
//  Created by 孙昕 on 14-10-14.
//
//

#include "Notify.h"
std::map<std::string,sNotify::TYPE> sNotify::mapNotify;
std::vector<sNotify::sInfo> sNotify::vecInfo;
char CoreNotify::cID[100];
long CoreNotify::pos=0;
CoreNotify::CoreNotify()
{
    memset((void*)cID, 0, sizeof(char)*100);
    sNotify::mapNotify["workioi"]=sNotify::WORKIOI;
    sNotify::mapNotify["leisureioi"]=sNotify::LEISUREIOI;
    sNotify::mapNotify["leisuredate"]=sNotify::LEISUREDATE;
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
            it=m_Vector.erase(it);
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

sNotify::TYPE CoreNotify::GetAvailableNotify(long lStatus,bool bLove,long lIOI)
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
    for(auto it=sNotify::vecInfo.begin();it!=sNotify::vecInfo.end();it++)
    {
        if(it->type==type && it->bLove==bLove)
        {
            if(lIOI<1)
            {
                lIOI=1;
            }
            else if (lIOI>100)
            {
                lIOI=100;
            }
            long val=it->cContext[lIOI-1];
            long rnd=random()%100+1;
            if(rnd>val)
            {
                type=sNotify::NONE;
            }
            break;
        }
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
    nodecollect *nc=in->select("/Notify");
    node* NotiNode=nc->item(0);
    nodecollect *col=NotiNode->select("/work/item");
    for(int i=0;i<col->getcount();i++)
    {
        m_AvailableWorkVec.push_back((sNotify::TYPE)atol(col->item(i)->getattr("type").data()));
    }
    delete col;
    col=NotiNode->select("/leisure/item");
    for(int i=0;i<col->getcount();i++)
    {
        m_AvailableLeisureVec.push_back((sNotify::TYPE)atol(col->item(i)->getattr("type").data()));
    }
    delete col;
    delete nc;
}

void CoreNotify::Adjust(bool bLove)
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

void CoreNotify::ClearNotify()
{
    std::vector<sNotify>().swap(m_Vector);
}

void CoreNotify::Reset(node* pNode)
{
    std::vector<sNotify::sInfo>().swap(sNotify::vecInfo);
    nodecollect *nc=pNode->select("/notify");
    node* root=nc->item(0);
    nodecollect * ncItem=root->select("/item");
    for(long i=0;i<ncItem->getcount();i++)
    {
        sNotify::sInfo info;
        node *n=ncItem->item(i);
        info.bLove=atol(n->getattr("love").data());
        info.type=sNotify::mapNotify[n->getattr("type")];
        nodecollect *ncValue=n->select("/value");
        memset(info.cContext, 0, 100*sizeof(char));
        for(long j=0;j<ncValue->getcount();j++)
        {
            node* nn=ncValue->item(j);
            long val=atol(nn->gettext().data());
            long min=atol(nn->getattr("min").data())-1;
            long max=atol(nn->getattr("max").data())-1;
            if(max==-2)
            {
                max=100;
            }
            for(long k=min;k<max;k++)
            {
                info.cContext[k]=val;
            }
        }
        sNotify::vecInfo.push_back(info);
        delete  ncValue;
    }
    delete ncItem;
    delete nc;
    Adjust(false);
}














