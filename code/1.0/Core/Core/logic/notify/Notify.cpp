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
void CoreNotify::Serializ(FILE* out)
{
    fwrite(cID,1,100*sizeof(char),out);
    fwrite(&pos,sizeof(pos),1,out);
    long size=m_Queue.size();
    fwrite(&size,sizeof(size),1,out);
    std::queue<sNotify> queue=m_Queue;
    while(!queue.empty())
    {
        sNotify noti=queue.front();
        fwrite(&noti.id,sizeof(noti.id),1,out);
        fwrite(&noti.sec,sizeof(noti.sec),1,out);
        fwrite(&noti.szText,1,100*sizeof(char),out);
        fwrite(&noti.type,sizeof(noti.type),1,out);
        fwrite(&noti.bEnabled,sizeof(noti.bEnabled),1,out);
        fwrite(&noti.flag,sizeof(noti.flag),1,out);
        queue.pop();
    }
}
void CoreNotify::UnSerializ(FILE* in)
{
    ClearAllNotify();
    fread(cID, 1,100*sizeof(char),in);
    fread(&pos,sizeof(pos),1,in);
    long count;
    fread(&count,sizeof(count),1,in);
    while(count-->0)
    {
        sNotify noti;
        fread(&noti.id,sizeof(noti.id),1,in);
        fread(&noti.sec,sizeof(noti.sec),1,in);
        fread(&noti.szText,1,100*sizeof(char),in);
        fread(&noti.type,sizeof(noti.type),1,in);
        fread(&noti.bEnabled,sizeof(noti.bEnabled),1,in);
        fread(&noti.flag,sizeof(noti.flag),1,in);
        m_Queue.push(noti);
    }
}






