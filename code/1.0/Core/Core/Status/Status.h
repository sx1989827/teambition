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
class CoreStatus
{
public:
    enum TYPE {LEISURE,SLEEP,WORK};
    virtual void OnEnter(CorePlayer *pPlayer);
    virtual void OnUpdate(CorePlayer *pPlayer);
    virtual void OnExit(CorePlayer* pPlayer);
    virtual void ChangeStatus(CorePlayer* pPlayer,TYPE type);
};

#endif /* defined(__Core__Status__) */
