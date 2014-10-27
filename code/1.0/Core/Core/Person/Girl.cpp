//
//  Girl.cpp
//  Core
//
//  Created by 孙昕 on 14/10/22.
//
//

#include "Girl.h"
#include "../util/Constant.h"
#include "../util/Oberserver.h"
CoreGirl::CoreGirl()
{
    m_lIOI=0;
    m_Type=CoreGirl::LOLI;
    m_pMood=new CoreMood;
    m_pFavorite=new CoreFavorite;
    OBINSTANCE->AddOberserver(MSG_LEISUREENTER, this, &CoreGirl::OnStatusChange);
    OBINSTANCE->AddOberserver(MSG_LEISUREUPDATE, this, &CoreGirl::OnStatusChange);
    OBINSTANCE->AddOberserver(MSG_LEISUREEXIT, this, &CoreGirl::OnStatusChange);
    OBINSTANCE->AddOberserver(MSG_SLEEPENTER, this, &CoreGirl::OnStatusChange);
    OBINSTANCE->AddOberserver(MSG_SLEEPUPDATE, this, &CoreGirl::OnStatusChange);
    OBINSTANCE->AddOberserver(MSG_SLEEPEXIT, this, &CoreGirl::OnStatusChange);
    OBINSTANCE->AddOberserver(MSG_WORKENTER, this, &CoreGirl::OnStatusChange);
    OBINSTANCE->AddOberserver(MSG_WORKUPDATE, this, &CoreGirl::OnStatusChange);
    OBINSTANCE->AddOberserver(MSG_SLEEPEXIT, this, &CoreGirl::OnStatusChange);
}

CoreGirl::~CoreGirl()
{
    OBINSTANCE->RemoveOberserver(MSG_LEISUREENTER, this);
    OBINSTANCE->RemoveOberserver(MSG_LEISUREUPDATE, this);
    OBINSTANCE->RemoveOberserver(MSG_LEISUREEXIT, this);
    OBINSTANCE->RemoveOberserver(MSG_SLEEPENTER, this);
    OBINSTANCE->RemoveOberserver(MSG_SLEEPUPDATE, this);
    OBINSTANCE->RemoveOberserver(MSG_SLEEPEXIT, this);
    OBINSTANCE->RemoveOberserver(MSG_WORKENTER, this);
    OBINSTANCE->RemoveOberserver(MSG_WORKUPDATE, this);
    OBINSTANCE->RemoveOberserver(MSG_SLEEPEXIT, this);
    delete m_pFavorite;
    delete m_pMood;
}

void CoreGirl::Serializ(node* out)
{
    node* root=out->getXml()->createnode("Girl");
    WriteXml(root, (long)m_Type, "type");
    WriteXml(root, m_lIOI, "ioi");
    m_pMood->Serializ(root);
    m_pFavorite->Serializ(root);
    out->appned(root);
}
void CoreGirl::UnSerializ(node* in)
{
     node* root=in->select("/Girl")->item(0);
    m_Type=(CoreGirl::TYPE)atol(root->select("/type")->item(0)->gettext().data());
    m_lIOI=atol(root->select("/ioi")->item(0)->gettext().data());
    m_pMood->UnSerializ(root);
    m_pFavorite->UnSerializ(root);
}

void CoreGirl::BuildFavorite()
{
    m_pFavorite->Build(FAVFILE);
}

CorePersonBase::PERSONTYPE CoreGirl::GetType()
{
    return GIRL;
}

void CoreGirl::OnStatusChange(void *pObj, const char *name, void* value)
{
    
}














