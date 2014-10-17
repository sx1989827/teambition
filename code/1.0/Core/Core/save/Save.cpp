//
//  Save.cpp
//  Core
//
//  Created by 孙昕 on 14-10-17.
//
//
#include <assert.h>
#include "Save.h"
void CoreSave::Save()
{
    xml x;
    node *n=x.insertpi();
    n->setattr("encoding","gb2312");
    node * n1=x.createnode("root");
    x.append(n1);
    for(long i=0;i<m_Vec.size();i++)
    {
        m_Vec[i]->Serializ(n1);
    }
    x.savefile(SAVEFILE);
}

void CoreSave::UnSave()
{
    xml x;
    x.loadfile(SAVEFILE);
    node *n1=x.getnodebyname("root")->item(0);
    for(long i=0;i<m_Vec.size();i++)
    {
        m_Vec[i]->UnSerializ(n1);
    }
}

void CoreSave::SetSaveObj(std::vector<CoreSerializ*> *pObj)
{
    m_Vec=*pObj;
}







