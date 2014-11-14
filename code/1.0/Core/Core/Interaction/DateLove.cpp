//
//  DateLove.cpp
//  Core
//
//  Created by 孙昕 on 14/11/11.
//
//

#include "DateLove.h"
#include "DateEat.h"
#include "DateFilm.h"
#include "DateWalk.h"
#include "DatePark.h"
CoreInteraction*  CoreDateLove::CreateInstance()
{
    return new CoreDateLove;
}

void CoreDateLove::Update()
{
    if(m_pDate)
    {
        m_pDate->Update();
    }
}

bool CoreDateLove::Enter()
{
    if(m_pDate)
    {
        return m_pDate->Enter();
    }
    return false;
}

void CoreDateLove::Leave()
{
    if(m_pDate)
    {
        m_pDate->Leave();
    }
}


bool CoreDateLove::IsNeedEnd()
{
    return true;
}

bool CoreDateLove::IsEnd()
{
    return m_bEnd;
}

CoreInteraction::TYPE CoreDateLove::GetType()
{
    return DATELOVE;
}

void CoreDateLove::SetDateType(CoreDateBase::TYPE type)
{
    if(m_pDate)
    {
        delete m_pDate;
    }
    if(type==CoreDateBase::EAT)
    {
        m_pDate=new CoreDateEat;
    }
    else if (type==CoreDateBase::FILM)
    {
        m_pDate=new CoreDateFilm;
    }
    else if (type==CoreDateBase::WALK)
    {
        m_pDate=new CoreDateWalk;
    }
    else if (type==CoreDateBase::PARK)
    {
        m_pDate=new CoreDatePark;
    }
}

CoreDateLove::~CoreDateLove()
{
    if(m_pDate)
    {
        delete m_pDate;
    }
}

CoreDateLove::CoreDateLove()
{
    m_pDate=0;
}















