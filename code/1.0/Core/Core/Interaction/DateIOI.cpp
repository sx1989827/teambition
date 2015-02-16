//
//  DateIOI.cpp
//  Core
//
//  Created by 孙昕 on 14/11/11.
//
//

#include "DateIOI.h"
#include "DateEat.h"
#include "DateFilm.h"
#include "DateWalk.h"
#include "DatePark.h"
CoreInteraction*  CoreDateIOI::CreateInstance()
{
    return new CoreDateIOI;
}

void CoreDateIOI::Update()
{
    if(m_pDate)
    {
        m_pDate->Update();
    }
}

bool CoreDateIOI::TryEnter()
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

void CoreDateIOI::Enter()
{
    if(m_pDate)
    {
        m_pDate->Enter();
    }
}

void CoreDateIOI::Leave()
{
    if(m_pDate)
    {
        m_pDate->Leave();
    }
}


bool CoreDateIOI::IsNeedEnd()
{
    return true;
}


bool CoreDateIOI::IsEnd()
{
    return m_bEnd;
}

CoreInteraction::TYPE CoreDateIOI::GetType()
{
    return DATEIOI;
}

void CoreDateIOI::SetDateType(CoreDateBase::TYPE type)
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
    m_pDate->SetIOI(true);
}

CoreDateIOI::~CoreDateIOI()
{
    if(m_pDate)
    {
        delete m_pDate;
    }
}

CoreDateIOI::CoreDateIOI()
{
    m_pDate=0;
}












