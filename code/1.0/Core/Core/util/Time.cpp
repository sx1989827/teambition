//
//  Time.cpp
//  Core
//
//  Created by 孙昕 on 14-10-13.
//
//

#include "Time.h"

#include "Constant.h"
std::string CoreTime::GetCurrentTime()
{
    long lTime=time(0);
    tm *pTime= localtime((const time_t*)&lTime);
    char szTime[TEXT_SIZE]={0};
    sprintf(szTime, "%d-%d-%d %02d:%02d:%02d",1900+pTime->tm_year,pTime->tm_mon+1,pTime->tm_mday,pTime->tm_hour,pTime->tm_min,pTime->tm_sec);
    return std::string(szTime);
}

std::string CoreTime::GetCurrentDate()
{
    long lTime=time(0);
    tm *pTime= localtime((const time_t*)&lTime);
    char szTime[TEXT_SIZE]={0};
	sprintf(szTime,"%d-%d-%d ",1900+pTime->tm_year,pTime->tm_mon+1,pTime->tm_mday);
    return std::string(szTime);
}

std::string CoreTime::GetCurrentMoment()
{
    long lTime=time(0);
    tm *pTime= localtime((const time_t*)&lTime);
    char szTime[TEXT_SIZE]={0};
    sprintf(szTime, "%02d:%02d:%02d",pTime->tm_hour,pTime->tm_min,pTime->tm_sec);
    return std::string(szTime);
}

CoreTime CoreTime::GetTimeSinceNow(int sec)
{
    long  lTime=time(0);
    long newTime=lTime+sec;
    CoreTime obj;
    obj.m_lTime=newTime;
    return obj;
}

CoreTime::CoreTime()
{
    m_lTime=time(0);
}

std::string CoreTime::GetTime()
{
    tm *pTime= localtime((const time_t*)&m_lTime);
    char szTime[TEXT_SIZE]={0};
    sprintf(szTime, "%d-%d-%d %02d:%02d:%02d",1900+pTime->tm_year,pTime->tm_mon+1,pTime->tm_mday,pTime->tm_hour,pTime->tm_min,pTime->tm_sec);
    return std::string(szTime);
}

std::string CoreTime::GetDate()
{
    tm *pTime= localtime((const time_t*)&m_lTime);
    char szTime[TEXT_SIZE]={0};
    sprintf(szTime, "%d-%d-%d ",1900+pTime->tm_year,pTime->tm_mon+1,pTime->tm_mday);
    return std::string(szTime);
}

std::string CoreTime::GetMoment()
{
    tm *pTime= localtime((const time_t*)&m_lTime);
    char szTime[TEXT_SIZE]={0};
    sprintf(szTime, "%02d:%02d:%02d",pTime->tm_hour,pTime->tm_min,pTime->tm_sec);
    return std::string(szTime);
}

CoreTime CoreTime::GetTimeSince(int sec)
{
    long newTime=m_lTime+sec;
    CoreTime obj;
    obj.m_lTime=newTime;
    return obj;
}



