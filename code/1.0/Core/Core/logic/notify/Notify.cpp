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
    m_Queue.push(*pNotify);
    return pos;
}
void CoreNotify::RemoveNotify(long id)
{
    
}
void CoreNotify::QueryOverdueNotify(std::list<sNotify> *map,long sec) const
{
    
}
void CoreNotify::ClearAllNotify()
{
    std::queue<sNotify> temp;
    m_Queue.swap(temp);
}
void CoreNotify::Serializ(std::map<std::string, std::string> *map)
{
    
}
void CoreNotify::UnSerializ(std::map<std::string, std::string> *map)
{
    
}






