//
//  Save.h
//  Core
//
//  Created by 孙昕 on 14-10-17.
//
//

#ifndef __Core__Save__
#define __Core__Save__
#include <vector>
#include "../util/header.h"
#define SAVEINSTANCE CoreSaveSingleton::GetInstance()
class CoreSave
{
public:
    void Save();
    void UnSave();
private:
    std::vector<CoreSerializ*> m_Vec;
public:
    void SetSaveObj(std::vector<CoreSerializ*> *pObj);
};

class CoreSaveSingleton:public CoreSingleton<CoreSave>
{
private:
    CoreSaveSingleton();
    CoreSaveSingleton(const CoreSaveSingleton&);
    ~CoreSaveSingleton();
    CoreSaveSingleton &operator=(const CoreSaveSingleton&);
};
#endif /* defined(__Core__Save__) */











