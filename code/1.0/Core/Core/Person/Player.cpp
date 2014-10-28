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
    node* root=out->getXml()->createnode("Player");
    WriteXml(root, m_bLove, "love");
    WriteXml(root, m_lPhysical, "physical");
    WriteXml(root, m_lMoney, "money");
    out->appned(root);

}
void CorePlayer::UnSerializ(node* in)
{
    node* root=in->select("/Player")->item(0);
    m_bLove=(bool)atol(root->select("/love")->item(0)->gettext().data());
    m_lPhysical=atol(root->select("/physical")->item(0)->gettext().data());
    m_lMoney=atol(root->select("/money")->item(0)->gettext().data());
}

CorePersonBase::PERSONTYPE CorePlayer::GetType()
{
    return PLAYER;
}

CoreStatusController* CorePlayer::GetStatusController()
{
    return m_pStatusController;
}

void CorePlayer::ChangeStatus(CoreStatus::TYPE type)
{
    m_pStatusController->ChangeStatus(type);
}









