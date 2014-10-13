//
//  Oberserver.cpp
//  Core
//
//  Created by 孙昕 on 14-10-13.
//
//
#include <stdio.h>
#include "Oberserver.h"

void CoreObManage::PostOberserver(void *pObj, const char *name, void *oldValue, void *newValue)
{
	char szName[TEXT_SIZE] = { 0 };
	sprintf(szName, "%d#%s", (long)pObj, name);
	if (m_Map.find(szName) != m_Map.end())
	{
		auto pos = m_Map.equal_range(szName);
		while (pos.first != pos.second)
		{
			CoreFuncBase *pOB = pos.first->second;
			(*pOB)(pObj, name, oldValue, newValue);
			pos.first++;
		}
	}
}