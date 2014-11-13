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
}