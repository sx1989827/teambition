//
//  main.cpp
//  Core
//
//  Created by 孙昕 on 14-10-13.
//
//

#include <iostream>
#include "util/Header.h"
class A
{
public:
	A()
	{
		a = 0;
	}
	void SetA(long v)
	{
		OBINSTANCE->PostOberserver(this, "a", &a, &v);
		a = v;
	}
private:
	long a;
};
class B
{
public:
	B(A *a)
	{
		OBINSTANCE->AddOberserver(a, "a", this, &B::p);

	}
	void Remove(A *a)
	{
		OBINSTANCE->RemoveOberserver(a, "a",this);
	}
	void p(void *pObj, const char *name, void *oldValue, void *newValue)
	{
		std::cout << name << " " << *(long*)oldValue << " " << *(long*)newValue << std::endl;
	}
};
class C
{
public:
	C(A *a)
	{
		OBINSTANCE->AddOberserver(a, "a", this, &C::p1);

	}
	void Remove(A *a)
	{
		OBINSTANCE->RemoveOberserver(a, "a", this);
	}
	void p1(void *pObj, const char *name, void *oldValue, void *newValue)
	{
		std::cout << name << " " << *(long*)oldValue << " " << *(long*)newValue << std::endl;
	}
};
int main(int argc, const char * argv[])
{

    CoreLog *pLog=new CoreLog;
    CoreLogSingleton::SetInstance(pLog);
	CoreObManage *pOb = new CoreObManage;
	CoreObManageSingleton::SetInstance(pOb);
    LOG("123");
    LOG1("%d",45);
    std::cout<<CoreTime::GetTimeSinceNow(60*60).GetTime().data()<<std::endl;
	A a;
	B b(&a);
	C c(&a);
	a.SetA(10);
	b.Remove(&a);
	c.Remove(&a);
}
