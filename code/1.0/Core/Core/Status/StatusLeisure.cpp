//
//  StatusLeisure.cpp
//  Core
//
//  Created by 孙昕 on 14/10/24.
//
//

#include "StatusLeisure.h"
#include "../Person/Player.h"
#include "../logic/notify/Notify.h"
void CoreStatusLeisure::OnEnter()
{
    m_StartTime.Reset();
    PLAYERINSTANCE->SetPlace("家");
}
void CoreStatusLeisure::OnUpdate()
{

}
void CoreStatusLeisure::OnExit()
{
    OnUpdate();
    NOTIFYCENTER->ClearNotify();
}
CoreStatus::TYPE CoreStatusLeisure::GetType()
{
    return LEISURE;
}