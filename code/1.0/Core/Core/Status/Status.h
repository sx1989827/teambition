//
//  Status.h
//  Core
//
//  Created by 孙昕 on 14/10/22.
//
//

#ifndef __Core__Status__
#define __Core__Status__
#include "../Person/Player.h"
#include "../util/Header.h"
class CoreStatus
{
public:
    enum TYPE {LEISURE,SLEEP,WORK};
    virtual void OnEnter(CorePlayer *pPlayer);
    virtual void OnUpdate(CorePlayer *pPlayer);
    virtual void OnExit(CorePlayer* pPlayer);
    virtual TYPE GetType();
protected:
    CoreTime m_StartTime;
};

#endif /* defined(__Core__Status__) */
