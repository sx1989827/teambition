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
    m_dPhysical=0;
    m_dMoney=0;
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
    WriteXml(root, m_dPhysical, "physical");
    WriteXml(root, m_dMoney, "money");
    out->appned(root);

}
void CorePlayer::UnSerializ(node* in)
{
    nodecollect *nc=in->select("/Player");
    node* root=nc->item(0);
    nodecollect *nc1=root->select("/love");
    m_bLove=(bool)atol(nc1->item(0)->gettext().data());
    nodecollect *nc2=root->select("/physical");
    m_dPhysical=atof(nc2->item(0)->gettext().data());
    nodecollect *nc3=root->select("/money");
    m_dMoney=atof(nc3->item(0)->gettext().data());
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

double CorePlayer::GetPhysical()
{
    return m_dPhysical;
}
void CorePlayer::SetPhysical(double val)
{
    m_dPhysical=val;
}
double CorePlayer::GetMoney()
{
    return m_dMoney;
}
void CorePlayer::SetMoney(double val)
{
    m_dMoney=val;
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
    nodecollect* nc=pNode->select("/player");
    node* root=nc->item(0);
    nodecollect *ncPhysical=root->select("/physical");
    m_dPhysical=atof(ncPhysical->item(0)->getattr("value").data());
    nodecollect *ncMoney=root->select("/money");
    m_dMoney=atof(ncMoney->item(0)->getattr("value").data());
    nodecollect *ncLove=root->select("/love");
    m_bLove=atol(ncLove->item(0)->gettext().data());
    delete ncLove;
    delete ncMoney;
    delete ncPhysical;
    delete nc;
}

















