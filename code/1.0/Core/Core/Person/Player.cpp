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
    nodecollect *nc=in->select("/Player");
    node* root=nc->item(0);
    nodecollect *nc1=root->select("/love");
    m_bLove=(bool)atol(nc1->item(0)->gettext().data());
    nodecollect *nc2=root->select("/physical");
    m_lPhysical=atol(nc2->item(0)->gettext().data());
    nodecollect *nc3=root->select("/money");
    m_lMoney=atol(nc3->item(0)->gettext().data());
    delete nc3;
    delete nc2;
    delete nc1;
    delete nc;
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

long CorePlayer::GetPhysical()
{
    return m_lPhysical;
}
void CorePlayer::SetPhysical(long val)
{
    m_lPhysical=val;
}
long CorePlayer::GetMoney()
{
    return m_lMoney;
}
void CorePlayer::SetMoney(long val)
{
    m_lMoney=val;
}
bool CorePlayer::GetLove()
{
    return m_bLove;
}
void CorePlayer::SetLove(bool bLove)
{
    m_bLove=bLove;
}

void CorePlayer::Reset(node *pNode)
{
    
}

















