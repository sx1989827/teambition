//
//  StatusLeisure.h
//  Core
//
//  Created by 孙昕 on 14/10/24.
//
//

#ifndef __Core__StatusLeisure__
#define __Core__StatusLeisure__
#include "Status.h"
class CoreStatusLeisure:public CoreStatus
{
public:
    void OnEnter(CorePlayer *pPlayer);
    void OnUpdate(CorePlayer *pPlayer);
    void OnExit(CorePlayer* pPlayer);
    TYPE GetType();
};

#endif /* defined(__Core__StatusLeisure__) */
