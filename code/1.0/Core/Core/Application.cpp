//
//  Application.cpp
//  Core
//
//  Created by 孙昕 on 14-10-17.
//
//
#include "Application.h"

CoreApplication::CoreApplication()
{
    srandom((unsigned)time(0));
    m_pLog=new CoreLog;
    CoreLogSingleton::SetInstance(m_pLog);
    m_pNotify=new CoreNotify;
    CoreNotifySingleton::SetInstance(m_pNotify);
    m_pObManage=new CoreObManage;
    CoreObManageSingleton::SetInstance(m_pObManage);
    std::vector<CoreSerializ*> vec;
    m_pSave=new CoreSave;
    vec.push_back(NOTIFYCENTER);
    m_pPlayer=new CorePlayer;
    CorePlayerSingleton::SetInstance(m_pPlayer);
    vec.push_back(m_pPlayer);
    m_pGirl=new CoreGirl;
    CoreGirlSingleton::SetInstance(m_pGirl);
    vec.push_back(m_pGirl);
    m_pSave->SetSaveObj(&vec);
    CoreSaveSingleton::SetInstance(m_pSave);
    m_pPlayer->ChangeStatus(CoreStatus::LEISURE);
}

CoreApplication::~CoreApplication()
{
    delete m_pGirl;
    delete m_pPlayer;
    CoreSaveSingleton::Release();
    CoreObManageSingleton::Release();
    CoreNotifySingleton::Release();
    CoreLogSingleton::Release();
    CoreGirlSingleton::Release();
    CorePlayerSingleton::Release();
    delete m_pSave;
    delete m_pObManage;
    delete m_pNotify;
    delete m_pLog;
}

CoreGirl* CoreApplication::GetGirl()
{
    return m_pGirl;
}

CorePlayer* CoreApplication::GetPlayer()
{
    return m_pPlayer;
}

void CoreApplication::Reset(CoreGirl::TYPE type)
{
    xml  x;
    x.loadfile(INITFILE);
    nodecollect *nc=x.getnodebyname("root");
    node *n1=nc->item(0);
    m_pGirl->Reset(n1,type);
    m_pPlayer->Reset(n1);
    m_pNotify->Reset(n1);
    delete nc;
}














