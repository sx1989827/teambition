//
//  DateBase.cpp
//  Core
//
//  Created by 孙昕 on 14/11/13.
//
//

#include "DateBase.h"
#include <stdlib.h>
double CoreDateBase::GetIOIValue(double min,double max)
{
    min=(random()%(long)((max-min)*10+1))/10.0;
    return min;
}

CoreDateBase::CoreDateBase()
{
    m_bEnd=false;
    m_bIOI=false;
}

void CoreDateBase::SetIOI(bool bIOI)
{
    m_bIOI=bIOI;
}

void CoreDateBase::SetOldPlace(std::string strPlace)
{
    m_strOldPlace=strPlace;
}

std::string CoreDateBase::GetOldPlace()
{
    return m_strOldPlace;
}












