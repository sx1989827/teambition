//
//  Oberserver.cpp
//  Core
//
//  Created by 孙昕 on 14-10-13.
//
//
#include <stdio.h>
#include "Oberserver.h"

void CoreObManage::PostOberserver(void *pObj,const std::string& name,void* value)
{
    char szName[TEXT_SIZE] = { 0 };
    sprintf(szName, "%ld#%s", (long)pObj, name.data());
    if (m_Map.find(szName) != m_Map.end())
    {
        auto pos = m_Map.equal_range(szName);
        while (pos.first != pos.second)
        {
            CoreFuncBase *pOB = pos.first->second;
            (*pOB)(pObj, name, value);
            pos.first++;
        }
    }

}







