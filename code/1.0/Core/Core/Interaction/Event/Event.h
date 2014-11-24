//
//  Event.h
//  Core
//
//  Created by 孙昕 on 14/11/24.
//
//

#ifndef __Core__Event__
#define __Core__Event__
#include "../../util/Header.h"
struct sEvent
{
    std::string strDes;
    std::string  strMood;
    double dLoliVal;
    double dMaidVal;
    double dQueenVal;
};
class CoreEvent
{
public:
    CoreEvent();
    sEvent GetAvaliableEvent();
    void  HandleEvent(sEvent eve);
private:
    std::vector<sEvent> m_VecWorkEvent;
    std::vector<sEvent> m_VecLeisureEvent;
};

class CoreEventSingleton:public CoreSingleton<CoreEvent>
{
private:
    CoreEventSingleton();
    CoreEventSingleton(const CoreEventSingleton&);
    ~CoreEventSingleton();
    CoreEventSingleton &operator=(const CoreEventSingleton&);
    
};
#endif /* defined(__Core__Event__) */
