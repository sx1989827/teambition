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
    m_lPhysical=0;
    m_lMoney=0;
    m_bLove=false;
    m_pStatusController=new CoreStatusController;
    m_pStatusController->SetPlayer(this);
    
}
CorePlayer::~CorePlayer()
{
    delete m_pStatusController;
}

void CorePlayer::Serializ(node* out)
{
    
}
void CorePlayer::UnSerializ(node* in)
{
    
}

CorePersonBase::PERSONTYPE CorePlayer::GetType()
{
    return PLAYER;
}

CoreStatusController* CorePlayer::GetStatusController()
{
    return m_pStatusController;
}










