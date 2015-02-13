//
//  Save.cpp
//  Core
//
//  Created by 孙昕 on 14-10-17.
//
//
#include <assert.h>
#ifdef XCODE
#include <unistd.h>
#elif defined(VS)
#include <io.h>
#endif
#include "Save.h"
void CoreSave::Save()
{
    xml x;
    node *n=x.insertpi();
    n->setattr("encoding","utf-8");
    node * n1=x.createnode("root");
    x.append(n1);
    for(long i=0;i<m_Vec.size();i++)
    {
        m_Vec[i]->Serializ(n1);
    }
    x.savefile(GetCurrentDocDir()+ SAVEFILE) ;
}

void CoreSave::UnSave()
{
    if(access((GetCurrentDocDir()+SAVEFILE).data(), 0)==-1)
    {
        return;
    }
    xml x;
    x.loadfile(GetCurrentDataDir()+SAVEFILE);
    nodecollect *nc=x.getnodebyname("root");
    node *n1=nc->item(0);
    for(long i=0;i<m_Vec.size();i++)
    {
        m_Vec[i]->UnSerializ(n1);
    }
    delete nc;
}

void CoreSave::SetSaveObj(std::vector<CoreSerializ*> *pObj)
{
    m_Vec=*pObj;
}







