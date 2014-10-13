//
//  Oberserver.cpp
//  Core
//
//  Created by 孙昕 on 14-10-13.
//
//

#include "Oberserver.h"
#include "Constant.h"
class Func
{
    
public:
    void operator() (void *pObj,const char *name,void* oldValue,void* newValue)
    {
        
    }
};
void CoreObManage::PostOberserver(void *pObj, const char *name, void *oldValue, void *newValue)
{
	char szName[TEXT_SIZE] = { 0 };

}