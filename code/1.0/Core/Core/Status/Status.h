//
//  Status.h
//  Core
//
//  Created by 孙昕 on 14/10/22.
//
//

#ifndef __Core__Status__
#define __Core__Status__
#include "../util/Header.h"
class CorePlayer;
class CoreStatus
{
public:
    enum TYPE {LEISURE,SLEEP,WORK};
    virtual ~CoreStatus(){}
    virtual void OnEnter()=0;
    virtual void OnUpdate()=0;
    virtual void OnExit()=0;
    virtual TYPE GetType()=0;
protected:
    CoreTime m_StartTime;
};

#endif /* defined(__Core__Status__) */
