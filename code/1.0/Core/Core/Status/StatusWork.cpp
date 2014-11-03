//
//  StatusWork.cpp
//  Core
//
//  Created by 孙昕 on 14/10/24.
//
//

#include "StatusWork.h"
void CoreStatusWork::OnEnter()
{
    m_StartTime.Reset();
}
void CoreStatusWork::OnUpdate()
{
    
}
void CoreStatusWork::OnExit()
{
    
}

CoreStatus::TYPE CoreStatusWork::GetType()
{
    return WORK;
}