//
//  Player.cpp
//  Core
//
//  Created by 孙昕 on 14/10/22.
//
//

#include "Player.h"
#include "../Status/StatusController.h"
CorePlayer::CorePlayer()
{
    m_pStatusController=new CoreStatusController;
    m_pStatusController->SetPlayer(this);
    m_pStatusController->ChangeStatus(CoreStatus::LEISURE);
    
}
CorePlayer::~CorePlayer()
{
    delete m_pStatusController;
}