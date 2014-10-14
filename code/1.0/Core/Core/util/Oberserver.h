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
#include "Constant.h"
#define  OBINSTANCE CoreObManageSingleton::GetInstance()
#define OBMETHEDBEGIN(name,param)  \
void Set_##name(decltype(name) param) \
{\
    OBINSTANCE->PostOberserver(this, #name, &name, &param);
#define OBMETHEDEND }
class CoreFuncBase
{
public:
	virtual void operator() (void *pObj, const char *name, void* oldValue, void* newValue) = 0;
	virtual long GetID() = 0;
	virtual ~CoreFuncBase()
	{

	}
};
template<class T1,class T2>
class CoreObFunc :public CoreFuncBase
{
private:
    T1 m_pObj;
    T2 m_func;
public:
	CoreObFunc(T1 pObj, T2 pFunc)
	{
		m_pObj = pObj;
		m_func = pFunc;
	}
    void operator() (void *pObj,const char *name,void* oldValue,void* newValue)
    {
        (m_pObj->*m_func)(pObj,name,oldValue,newValue);
    }
	long GetID()
	{
		return (long)m_pObj;
	}
};

class CoreObManage
{
public:
    void PostOberserver(void *pObj,const char *name,void* oldValue,void * newValue);
    template<class T1,class T2>
    void AddOberserver(void *pObj,const char* name,T1 pObj1,T2 func)
    {
		char szName[TEXT_SIZE] = { 0 };
		sprintf(szName, "%ld#%s", (long)pObj, name);
		CoreFuncBase *pOb = new CoreObFunc<T1, T2>(pObj1, func);
		m_Map.insert(std::make_pair(szName, pOb));
    }
    void RemoveOberserver(void *pObj,const char* name,void* pObj1)
    {
		char szName[TEXT_SIZE] = { 0 };
		sprintf(szName, "%ld#%s", (long)pObj, name);
		auto pos = m_Map.equal_range(szName);
		while (pos.first != pos.second)
		{
			if (pos.first->second->GetID() == (long)pObj1)
			{
				CoreFuncBase* pOb = pos.first->second;
				pos.first=m_Map.erase(pos.first);
				delete pOb;
			}
			else
			{
				++pos.first;
			}
		}

		
    }
private:
	std::multimap<std::string, CoreFuncBase*> m_Map;
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
