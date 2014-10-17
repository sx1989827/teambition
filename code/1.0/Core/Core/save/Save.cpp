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
    FILE *file=fopen(SAVEFILE, "wb");
    assert(file!=0);
    for(long i=0;i<m_Vec.size();i++)
    {
        m_Vec[i]->Serializ(file);
    }
    fclose(file);
}

void CoreSave::UnSave()
{
    FILE *file=fopen(SAVEFILE, "rb");
    assert(file!=0);
    for(long i=0;i<m_Vec.size();i++)
    {
        m_Vec[i]->UnSerializ(file);
    }
    fclose(file);
}

void CoreSave::SetSaveObj(std::vector<CoreSerializ*> *pObj)
{
    m_Vec=*pObj;
}







