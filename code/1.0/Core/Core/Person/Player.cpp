//
//  Player.cpp
//  Core
//
//  Created by 孙昕 on 14/10/22.
//
//

#include "Player.h"
#include "../Status/StatusController.h"
#include  <cmath>
#include <CoreFoundation/CoreFoundation.h>
CorePlayer::CorePlayer()
{
    m_dPhysical=0;
    m_dMoney=0;
    m_bLove=false;
    m_pInteraction=0;
    m_pStatusController=new CoreStatusController;
    m_pActionEye=new CoreActionEye;
    m_pActionBody=new CoreActionBody;
    m_pActionTalk=new CoreActionTalk;
}
CorePlayer::~CorePlayer()
{
    delete m_pStatusController;
    if(m_pInteraction)
    {
        delete m_pInteraction;
    }
    if(m_pActionEye)
    {
        delete m_pActionEye;
    }
    if(m_pActionBody)
    {
        delete m_pActionBody;
    }
    if(m_pActionTalk)
    {
        delete m_pActionTalk;
    }
}

void CorePlayer::Serializ(node* out)
{
    node* root=out->getXml()->createnode("Player");
    WriteXml(root, m_bLove, "love");
    WriteXml(root, m_dPhysical, "physical");
    WriteXml(root, m_dMoney, "money");
    m_pActionBody->Serializ(root);
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
    m_pActionBody->UnSerializ(root);
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
    double oldValue=m_dPhysical;
    m_dPhysical=val;
    if(m_dPhysical<1)
    {
        m_dPhysical=1;
    }
    else if (m_dPhysical>100)
    {
        m_dPhysical=100;
    }
    if(fabs(m_dPhysical-oldValue)>0.000001)
    {
        CFNotificationCenterPostNotification(CFNotificationCenterGetLocalCenter(), CFSTR("MsgPhysicalChange"), 0, 0, true);
    }
}
double CorePlayer::GetMoney()
{
    return m_dMoney;
}
void CorePlayer::SetMoney(double val)
{
    double oldValue=m_dMoney;
    m_dMoney=val;
    if(m_dMoney<0)
    {
        m_dMoney=0;
    }
    if(fabs(m_dMoney-oldValue)>0.000001)
    {
        CFNotificationCenterPostNotification(CFNotificationCenterGetLocalCenter(), CFSTR("MsgMoneyChange"), 0, 0, true);
    }
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
    node *nodeType=ncPhysical->item(0);
    while (nodeType) {
        nodecollect *ncSleep=nodeType->select("/sleep");
        nodecollect *ncWork=nodeType->select("/work");
        if(ncSleep->getcount()>0)
        {
            sPlayInfo info={atol(ncSleep->item(0)->getattr("time").data()),atof(ncSleep->item(0)->getattr("val").data())};
            if(nodeType->gettag()=="money")
            {
                m_mapMoney[CoreStatus::SLEEP]=info;
            }
            else if(nodeType->gettag()=="physical")
            {
                m_mapPhysical[CoreStatus::SLEEP]=info;
            }
        }
        if(ncWork->getcount()>0)
        {
            sPlayInfo info={atol(ncWork->item(0)->getattr("time").data()),atof(ncWork->item(0)->getattr("val").data())};
            if(nodeType->gettag()=="money")
            {
                m_mapMoney[CoreStatus::WORK]=info;
            }
            else if(nodeType->gettag()=="physical")
            {
                m_mapPhysical[CoreStatus::WORK]=info;
            }
        }
        delete ncWork;
        delete ncSleep;
        nodeType=nodeType->getnext();
    }
    m_bLove=atol(root->getattr("love").data());
    delete ncMoney;
    delete ncPhysical;
    delete nc;
}

const sPlayInfo* CorePlayer::GetPhysicalInfo(CoreStatus::TYPE type)
{
    auto it=m_mapPhysical.find(type);
    if(it!=m_mapPhysical.end())
    {
        return (sPlayInfo*)&(it->second);
    }
    else
    {
        return 0;
    }
}
const sPlayInfo* CorePlayer::GetMoneyInfo(CoreStatus::TYPE type)
{
    auto it=m_mapMoney.find(type);
    if(it!=m_mapMoney.end())
    {
        return (sPlayInfo*)&(it->second);
    }
    else
    {
        return 0;
    }
}

bool CorePlayer::IsInteraction()
{
    if(m_pInteraction)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void CorePlayer::Update()
{
    if(m_pInteraction)
    {
        if(m_pInteraction->IsNeedEnd())
        {
            if(!m_pInteraction->IsEnd())
            {
                m_pInteraction->Update();
            }
            if(m_pInteraction->IsEnd())
            {
                m_pInteraction->Leave();
                delete m_pInteraction;
                m_pInteraction=0;
                m_pStatusController->Update();
            }
        }
        else
        {
            m_pInteraction->Update();
        }
    }
    else
    {
        m_pStatusController->Update();
    }
}

bool CorePlayer::EnterInteraction(CoreInteraction::TYPE type)
{
    if(m_pInteraction)
    {
        m_pInteraction->Leave();
        delete m_pInteraction;
        m_pInteraction=0;
    }
    m_pStatusController->Update();
    m_pInteraction=CoreInteraction::CreateInstance(type);
    m_pInteraction->Enter();
    if(m_pInteraction!=0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void CorePlayer::LeaveInteraction()
{
    if(m_pInteraction)
    {
        m_pInteraction->Leave();
        delete m_pInteraction;
        m_pInteraction=0;
    }
    m_pStatusController->ResetTime(time(0));
}

void CorePlayer::SetPlace(std::string strPlace)
{
    m_strPlace=strPlace;
}
std::string CorePlayer::GetPlace()
{
    return m_strPlace;
}

bool CorePlayer::HandleActionEye(CoreActionEye::TYPE type)
{
    return m_pActionEye->Handle(type);
}
void CorePlayer::HandleActionBody(CoreActionBody::TYPE type)
{
    m_pActionBody->Handle(type);
}
void CorePlayer::HandleActionTalk(std::string type)
{
    m_pActionTalk->Handle(type);
}

std::vector<CoreActionBody::TYPE> CorePlayer::GetAvalibleActionBody()
{
    return m_pActionBody->GetAvalibleAction();
}

std::vector<std::string> CorePlayer::GetAvalibleActionTalk()
{
    return m_pActionTalk->GetAvalibleTalk();
}







