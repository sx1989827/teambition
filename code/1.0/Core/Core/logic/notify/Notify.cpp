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
long CoreNotify::CreateNotify(sNotify* pNotify)
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
    m_Queue.push(*pNotify);
    return pos;
}
void CoreNotify::GetLastNotify(sNotify *pNotify) const
{
    if(m_Queue.empty())
    {
        pNotify->id=-1;
        return;
    }
    *pNotify=m_Queue.front();
}

void CoreNotify::PopNotify()
{
    if(!m_Queue.empty())
    {
        m_Queue.pop();
    }
}

void CoreNotify::ClearAllNotify()
{
    std::queue<sNotify> temp;
    m_Queue.swap(temp);
}
void CoreNotify::Serializ(node* out)
{
    node* NotiNode=out->getXml()->createnode("Notify");
    node* cIDNode=out->getXml()->createnode("cID");
    for(long i=0;i<100;i++)
    {
        if(cID[i]!=0)
        {
            node* used=out->getXml()->createnode("used");
            used->puttext(i);
            cIDNode->appned(used);
        }
    }
    NotiNode->appned(cIDNode);
    WriteXml(NotiNode, pos, "pos");
    node* QueueNode= NotiNode->getXml()->createnode("size");
    NotiNode->appned(QueueNode);
    std::queue<sNotify> queue=m_Queue;
    while(!queue.empty())
    {
        sNotify noti=queue.front();
        node *NotifyNode=QueueNode->getXml()->createnode("item");
        NotifyNode->setattr("id", noti.id);
        NotifyNode->setattr("sec", noti.sec);
        NotifyNode->setattr("szText", noti.szText);
        NotifyNode->setattr("type", (long)noti.type);
        NotifyNode->setattr("bEnabled", noti.bEnabled);
        NotifyNode->setattr("flag", noti.flag);
        QueueNode->appned(NotifyNode);
        queue.pop();
    }
    out->appned(NotiNode);
}
void CoreNotify::UnSerializ(node* in)
{
    ClearAllNotify();
    memset(cID, 0, 100);
    node* NotiNode=in->select("/Notify")->item(0);
    nodecollect *cIDCollect=NotiNode->getnodebyname("cID");
    for(long i=0;i<cIDCollect->getcount();i++)
    {
        cID[i]=1;
    }
    node *posNode=NotiNode->getnodebyname("pos")->item(0);
    pos=posNode?atoi(posNode->gettext().data()):0;
    node *sizeNode=NotiNode->getnodebyname("size")->item(0);
    if(sizeNode!=0)
    {
        nodecollect *itemCollect=sizeNode->getnodebyname("item");
        for(long i=0;i<itemCollect->getcount();i++)
        {
            sNotify noti;
            noti.id=atol(itemCollect->item(i)->getattr("id").data());
            noti.sec=atol(itemCollect->item(i)->getattr("sec").data());
            strcpy(noti.szText,itemCollect->item(i)->getattr("szText").data());
            noti.type=(sNotify::TYPE)atol(itemCollect->item(i)->getattr("type").data());
            noti.bEnabled=atol(itemCollect->item(i)->getattr("bEnabled").data());
            noti.flag=atol(itemCollect->item(i)->getattr("flag").data());
            m_Queue.push(noti);
        }
        
    }
}






