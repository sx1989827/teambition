//
//  Status.cpp
//  Core
//
//  Created by 孙昕 on 14/10/22.
//
//

#include "Status.h"
void CoreStatus::ResetTime(long lTime)
{
    m_StartTime.Attach(lTime);
}