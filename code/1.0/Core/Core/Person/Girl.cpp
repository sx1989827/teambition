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
#include <cmath>
#include <CoreFoundation/CoreFoundation.h>
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
    node *nodeFace=out->getXml()->createnode("face");
    nodeFace->setattr("x", m_FaceRect.x);
    nodeFace->setattr("y", m_FaceRect.y);
    nodeFace->setattr("w", m_FaceRect.w);
    nodeFace->setattr("h", m_FaceRect.h);
    root->appned(nodeFace);
    node *nodeBreast=out->getXml()->createnode("breast");
    nodeBreast->setattr("x", m_BreastRect.x);
    nodeBreast->setattr("y", m_BreastRect.y);
    nodeBreast->setattr("w", m_BreastRect.w);
    nodeBreast->setattr("h", m_BreastRect.h);
    root->appned(nodeBreast);
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
    nodecollect *ncFace=root->select("/face");
    m_FaceRect.x=atoi(ncFace->item(0)->getattr("x").data());
    m_FaceRect.y=atoi(ncFace->item(0)->getattr("y").data());
    m_FaceRect.w=atoi(ncFace->item(0)->getattr("w").data());
    m_FaceRect.h=atoi(ncFace->item(0)->getattr("h").data());
    nodecollect *ncBreast=root->select("/breast");
    m_BreastRect.x=atoi(ncBreast->item(0)->getattr("x").data());
    m_BreastRect.y=atoi(ncBreast->item(0)->getattr("y").data());
    m_BreastRect.w=atoi(ncBreast->item(0)->getattr("w").data());
    m_BreastRect.h=atoi(ncBreast->item(0)->getattr("h").data());
    m_pMood->UnSerializ(root);
    m_pFavorite->UnSerializ(root);
    delete ncFace;
    delete ncBreast;
    delete ncIOI;
    delete ncType;
    delete nc;
}


CorePersonBase::PERSONTYPE CoreGirl::GetType()
{
    return GIRL;
}

void CoreGirl::OnStatusChange(void *pObj, const std::string& name, void* value)
{
    if(name==MSG_SLEEPENTER)
    {
        m_StartTime.Reset();
    }
    else if (name==MSG_SLEEPUPDATE)
    {
        long count=(time(0)-m_StartTime.GetOriTime())/m_lOffsetTime;
        if(count>0)
        {
            m_dIOI+=count*m_dOffset;
            m_StartTime.Reset();
        }
    }
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
    double oldValue=m_dIOI;
    m_dIOI=lIOI;
    if(lIOI<1)
    {
        lIOI=1;
    }
    if(fabs(m_dIOI-oldValue)>0.000001)
    {
        CFNotificationCenterPostNotification(CFNotificationCenterGetLocalCenter(), CFSTR("MsgIOIChange"), 0, 0, true);
    }
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
    m_Type=type;
    nodecollect *ncFace=root->select("/"+strType+"/face");
    m_FaceRect.x=atoi(ncFace->item(0)->getattr("x").data());
    m_FaceRect.y=atoi(ncFace->item(0)->getattr("y").data());
    m_FaceRect.w=atoi(ncFace->item(0)->getattr("w").data());
    m_FaceRect.h=atoi(ncFace->item(0)->getattr("h").data());
    nodecollect *ncBreast=root->select("/"+strType+"/breast");
    m_BreastRect.x=atoi(ncBreast->item(0)->getattr("x").data());
    m_BreastRect.y=atoi(ncBreast->item(0)->getattr("y").data());
    m_BreastRect.w=atoi(ncBreast->item(0)->getattr("w").data());
    m_BreastRect.h=atoi(ncBreast->item(0)->getattr("h").data());
    nodecollect *ncIOI=root->select("/"+strType+"/ioi");
    m_dIOI=atof(ncIOI->item(0)->getattr("value").data());
    m_lOffsetTime=atol(ncIOI->item(0)->getattr("time").data());
    m_dOffset=atof(ncIOI->item(0)->getattr("offset").data());
    m_pMood->Reset(root);
    m_pFavorite->Reset(root);
    delete ncFace;
    delete ncBreast;
    delete ncIOI;
    delete nc;
}

long CoreGirl::GetOffsetTime()
{
    return m_lOffsetTime;
}
double CoreGirl::GetOffset()
{
    return m_dOffset;
}

CoreGirl::sBodyRect CoreGirl::GetFaceRect()
{
    return m_FaceRect;
}

CoreGirl::sBodyRect CoreGirl::GetBreastRect()
{
    return m_BreastRect;
}



















