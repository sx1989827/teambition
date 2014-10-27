//
//  Girl.cpp
//  Core
//
//  Created by 孙昕 on 14/10/22.
//
//

#include "Girl.h"
#include "../util/Constant.h"
CoreGirl::CoreGirl()
{
    m_lIOI=0;
    m_Type=CoreGirl::LOLI;
    m_pMood=new CoreMood;
    m_pFavorite=new CoreFavorite;
}

CoreGirl::~CoreGirl()
{
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






