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
    m_dIOI=0;
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
    WriteXml(root, m_dIOI, "ioi");
    m_pMood->Serializ(root);
    m_pFavorite->Serializ(root);
    out->appned(root);
}
void CoreGirl::UnSerializ(node* in)
{
    nodecollect *nc=in->select("/Girl");
     node* root=nc->item(0);
    nodecollect * ncType=root->select("/type");
    m_Type=(CoreGirl::TYPE)atol(ncType->item(0)->gettext().data());
    nodecollect *ncIOI=root->select("/ioi");
    m_dIOI=atof(ncIOI->item(0)->gettext().data());
    m_pMood->UnSerializ(root);
    m_pFavorite->UnSerializ(root);
    delete ncIOI;
    delete ncType;
    delete nc;
}


CorePersonBase::PERSONTYPE CoreGirl::GetType()
{
    return GIRL;
}

void CoreGirl::OnStatusChange(void *pObj, const char *name, void* value)
{
    
}

CoreMood *CoreGirl::GetMood()
{
    return m_pMood;
}
double CoreGirl::GetIOI()
{
    return m_dIOI;
}
void CoreGirl::SetIOI(double lIOI)
{
    m_dIOI=lIOI;
}
CoreGirl::TYPE CoreGirl::GetGirlType()
{
    return m_Type;
}
void CoreGirl::SetGirlType(CoreGirl::TYPE type)
{
    m_Type=type;
}
CoreFavorite* CoreGirl::GetFavorite()
{
    return m_pFavorite;
}

void CoreGirl::Reset(node* pNode,CoreGirl::TYPE type)
{
    nodecollect* nc=pNode->select("/girl");
    node* root=nc->item(0);
    std::string strType;
    if(type==LOLI)
    {
        strType="loli";
    }
    else if (type==MAID)
    {
        strType="maid";
    }
    else if (type==QUEEN)
    {
        strType="queen";
    }
    nodecollect *ncIOI=root->select("/"+strType+"/ioi");
    m_dIOI=atof(ncIOI->item(0)->gettext().data());
    m_pMood->Reset(root);
    m_pFavorite->Reset(root);
    delete ncIOI;
    delete nc;
}























