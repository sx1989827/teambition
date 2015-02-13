//
//  Mood.cpp
//  Core
//
//  Created by 孙昕 on 14/10/22.
//
//

#include "Mood.h"
#include "../util/Oberserver.h"
CoreMood::CoreMood()
{
    m_MoodMap["平静"]=1;
    m_MoodMap["开心"]=2;
    m_MoodMap["害羞"]=2;
    m_MoodMap["撒娇"]=2;
    m_MoodMap["伤心"]=0;
    m_MoodMap["生气"]=0;
    m_MoodMap["烦躁"]=0;
    m_MoodMap["紧张"]=0;
    m_strCurMood="平静";
    m_lCurMood=5;
    
}
CoreMood::~CoreMood()
{
    
}

void CoreMood::Adjust()
{
    long v=m_MoodMap[m_strCurMood];
    if(v==0)
    {
        m_lCurMood+=4;
        if(m_lCurMood>-1)
        {
            m_lCurMood++;
            m_strCurMood="平静";
        }
    }
    else if (v==2)
    {
        m_lCurMood-=4;
        if(m_lCurMood<1)
        {
            m_lCurMood=10+m_lCurMood;
            m_strCurMood="平静";
        }
    }
}

void CoreMood::Transfer(sMood *pMood)
{
    if(pMood->strMood.empty())
    {
        m_lCurMood+=pMood->lOffset;
        if(m_lCurMood>10)
        {
            m_lCurMood=10;
        }
        else if (m_lCurMood<-10)
        {
            m_lCurMood=-10;
        }
    }
    else if(m_MoodMap[m_strCurMood]==m_MoodMap[pMood->strMood])
    {
        if(m_strCurMood==pMood->strMood)
        {
            m_lCurMood+=pMood->lOffset;
            if(m_lCurMood>10)
            {
                m_lCurMood=10;
            }
            else if (m_lCurMood<-10)
            {
                m_lCurMood=-10;
            }
        }
        else
        {
            m_strCurMood=pMood->strMood;
            m_strDescription=pMood->strDes;
        }
    }
    else
    {
        long v=m_MoodMap[m_strCurMood];
        if(v==0)
        {
            m_lCurMood+=pMood->lOffset;
            if(m_lCurMood>-1)
            {
                m_lCurMood++;
                m_strCurMood=pMood->strMood;
                m_strDescription=pMood->strDes;
            }
        }
        else if (v==1)
        {
            m_lCurMood+=pMood->lOffset;
            if(m_lCurMood>10)
            {
                m_lCurMood-=10;
                m_strCurMood=pMood->strMood;
                m_strDescription=pMood->strDes;
            }
            else if (m_lCurMood<1)
            {
                m_lCurMood--;
                m_strCurMood=pMood->strMood;
                m_strDescription=pMood->strDes;
            }
        }
        else if (v==2)
        {
            m_lCurMood+=pMood->lOffset;
            if(m_lCurMood<1)
            {
                m_lCurMood--;
                m_strCurMood=pMood->strMood;
                m_strDescription=pMood->strDes;
            }
        }
    }
}
void CoreMood::Serializ(node* out)
{
    node* root=out->getXml()->createnode("Mood");
    WriteXml(root, m_strCurMood, "curmood");
    WriteXml(root, m_lCurMood, "curvalue");
    WriteXml(root, m_strDescription, "des");
    out->appned(root);
}
void CoreMood::UnSerializ(node* in)
{
    nodecollect *nc=in->select("/Mood");
    node* root=nc->item(0);
    nodecollect *nc1=root->select("/curmood");
    m_strCurMood=nc1->item(0)->gettext();
    nodecollect *nc2=root->select("/curvalue");
    m_lCurMood=atol(nc2->item(0)->gettext().data());
    nodecollect *nc3=root->select("/des");
    m_strDescription=nc3->item(0)->gettext();
    delete nc3;
    delete nc2;
    delete nc1;
    delete nc;
}

void CoreMood::Reset(node* pNode)
{
    nodecollect* nc=pNode->select("/mood");
    node* root=nc->item(0);
    nodecollect *nc1=root->select("/type");
    m_strCurMood=nc1->item(0)->gettext();
    nodecollect *nc2=root->select("/value");
    m_lCurMood=atol(nc2->item(0)->gettext().data());
    nodecollect *nc3=root->select("/des");
    m_strDescription=nc3->item(0)->gettext();
    delete nc1;
    delete nc2;
    delete nc3;
    delete nc;
}

std::string CoreMood::GetStrMood()
{
    return m_strCurMood;
}

long CoreMood::QueryMoodType(std::string strMood)
{
    auto it=m_MoodMap.find(strMood);
    if(it==m_MoodMap.end())
    {
        return -1;
    }
    return it->second;
}





