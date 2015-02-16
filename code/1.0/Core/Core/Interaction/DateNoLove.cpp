//
//  DateNoLove.cpp
//  Core
//
//  Created by 孙昕 on 14/11/11.
//
//

#include "DateNoLove.h"
#include "DateEat.h"
#include "DateFilm.h"
#include "DateWalk.h"
#include "DatePark.h"
CoreInteraction*  CoreDateNoLove::CreateInstance()
{
    return new CoreDateNoLove;
}

void CoreDateNoLove::Update()
{
    if(m_pDate)
    {
        m_pDate->Update();
    }
}

bool CoreDateNoLove::TryEnter()
{
    if(m_pDate)
    {
        return m_pDate->TryEnter();
    }
    else
    {
        return false;
    }
}

void CoreDateNoLove::Enter()
{
    if(m_pDate)
    {
        m_pDate->Enter();
    }
}

void CoreDateNoLove::Leave()
{
    if(m_pDate)
    {
        m_pDate->Leave();
    }
}


bool CoreDateNoLove::IsNeedEnd()
{
    return true;
}

bool CoreDateNoLove::IsEnd()
{
    return m_bEnd;
}

CoreInteraction::TYPE CoreDateNoLove::GetType()
{
    return DATENOLOVE;
}

void CoreDateNoLove::SetDateType(CoreDateBase::TYPE type)
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

CoreDateNoLove::~CoreDateNoLove()
{
    if(m_pDate)
    {
        delete m_pDate;
    }
}

CoreDateNoLove::CoreDateNoLove()
{
    m_pDate=0;
}




















