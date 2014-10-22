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
    m_pSave=new CoreSave;
    std::vector<CoreSerializ*> vec;
    vec.push_back(NOTIFYCENTER);
    m_pSave->SetSaveObj(&vec);
    CoreSaveSingleton::SetInstance(m_pSave);
    
}

CoreApplication::~CoreApplication()
{
    CoreSaveSingleton::Release();
    CoreObManageSingleton::Release();
    CoreNotifySingleton::Release();
    CoreLogSingleton::Release();
    delete m_pSave;
    delete m_pObManage;
    delete m_pNotify;
    delete m_pLog;
}









