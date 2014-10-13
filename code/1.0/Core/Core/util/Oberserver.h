//
//  Oberserver.h
//  Core
//
//  Created by 孙昕 on 14-10-13.
//
//

#ifndef __Core__Oberserver__
#define __Core__Oberserver__

#include <stdio.h>
#include<map>
#include<string>
#include "Singleton.h"
template<class T1,class T2>
class CoreObFunc
{
private:
    T1 m_pObj;
    T2 m_func;
public:
    CoreObFunc(T1 pObj,T2 pFunc);
    void operator() (void *pObj,const char *name,void* oldValue,void* newValue)
    {
        (m_pObj->*m_func)(pObj,oldValue,newValue);
    }
};

class CoreOb
{
    
};

class CoreObManage
{
public:
    void PostOberserver(void *pObj,const char *name,void* oldValue,void * newValue);
    template<class T1,class T2>
    void AddOberserver(void *pObj,const char* name,T1 pObj1,T2 func)
    {
        
    }
    template<class T1,class T2>
    void RemoveOberserver(void *pObj,const char* name,T1 pObj1,T2 func)
    {
        
    }
};
class CoreObManageSingleton:public CoreSingleton<CoreObManage>
{
private:
    CoreObManageSingleton();
    CoreObManageSingleton(const CoreObManageSingleton&);
    ~CoreObManageSingleton();
    CoreObManageSingleton &operator=(const CoreObManageSingleton&);
    
};

#endif /* defined(__Core__Oberserver__) */
