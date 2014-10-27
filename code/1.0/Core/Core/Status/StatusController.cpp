//
//  StatusController.cpp
//  Core
//
//  Created by 孙昕 on 14/10/22.
//
//

#include "StatusController.h"
#include "StatusLeisure.h"
#include "StatusSleep.h"
#include "StatusWork.h"
#include "../Person/Player.h"
#include <assert.h>
CoreStatusController::CoreStatusController()
{
    m_pStatus=0;
    m_pPreStatus=0;
    m_pPlayer=0;
}
CoreStatusController::~CoreStatusController()
{
    if(m_pStatus)
    {
        delete m_pStatus;
    }
    if(m_pPreStatus)
    {
        delete m_pPreStatus;
    }
}
CoreStatus::TYPE CoreStatusController::GetStatus()
{
    return m_pStatus->GetType();
}
void CoreStatusController::Rollback()
{
    if(m_pPreStatus==0)
    {
        return;
    }
    CoreStatus::TYPE type=m_pPreStatus->GetType();
    CoreStatus *pStatus;
    if(type==CoreStatus::LEISURE)
    {
        pStatus=new CoreStatusLeisure;
    }
    else if (type==CoreStatus::SLEEP)
    {
        pStatus=new CoreStatusSleep;
    }
    else if (type==CoreStatus::WORK)
    {
        pStatus=new CoreStatusWork;
    }
    ChangeStatus(m_pPreStatus->GetType());
}
void CoreStatusController::ChangeStatus(CoreStatus::TYPE type)
{
    assert(m_pPlayer!=0);
    if(m_pStatus!=0 && m_pStatus->GetType()==type)
    {
        return;
    }
    if(m_pPreStatus)
    {
        delete m_pPreStatus;
        m_pPreStatus=0;
    }
    CoreStatus *pStatus=0;
    if(type==CoreStatus::LEISURE)
    {
        pStatus=new CoreStatusLeisure;
    }
    else if (type==CoreStatus::SLEEP)
    {
        pStatus=new CoreStatusSleep;
    }
    else if (type==CoreStatus::WORK)
    {
        pStatus=new CoreStatusWork;
    }
    m_pStatus->OnExit(m_pPlayer);
    m_pPreStatus=m_pStatus;
    m_pStatus=pStatus;
    m_pStatus->OnEnter(m_pPlayer);
}

void CoreStatusController::SetPlayer(CorePlayer *pPlayer)
{
    m_pPlayer=pPlayer;
}








