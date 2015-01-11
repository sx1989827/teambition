//
//  Story.h
//  Core
//
//  Created by 孙昕 on 14/11/24.
//
//

#ifndef __Core__Story__
#define __Core__Story__
#include <string>
#include <vector>
#include "../../util/Header.h"

struct sStory
{
    long id;
    double dIOI;
    double dMoney;
    double dPhysical;
    long lCount;
    bool bLove;
    std::string strSrc;
};

class CoreStory:public CoreSerializ
{
public:
    CoreStory();
    void Serializ(node* out);
    void UnSerializ(node* in);
    sStory GetAvaliableStory();
private:
    std::vector<sStory> m_VecStory;
    std::vector<long> m_VecUsedStory;
    
};

class CoreStorySingleton:public CoreSingleton<CoreStory>
{
private:
    CoreStorySingleton();
    CoreStorySingleton(const CoreStorySingleton&);
    ~CoreStorySingleton();
    CoreStorySingleton &operator=(const CoreStorySingleton&);
    
};

#endif /* defined(__Core__Story__) */
