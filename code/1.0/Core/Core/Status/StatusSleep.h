//
//  StatusSleep.h
//  Core
//
//  Created by 孙昕 on 14/10/24.
//
//

#ifndef __Core__StatusSleep__
#define __Core__StatusSleep__

#include "Status.h"
class CoreStatusSleep:public CoreStatus
{
public:
    void OnEnter(CorePlayer *pPlayer);
    void OnUpdate(CorePlayer *pPlayer);
    void OnExit(CorePlayer* pPlayer);
    TYPE GetType();
};

#endif /* defined(__Core__StatusSleep__) */
