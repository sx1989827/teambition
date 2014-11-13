//
//  LeisureIOILove.h
//  Core
//
//  Created by 孙昕 on 14/11/11.
//
//

#ifndef __Core__LeisureIOILove__
#define __Core__LeisureIOILove__

#include "Interaction.h"
class CoreLeisureIOILove:public CoreInteraction
{
public:
    static CoreInteraction* CreateInstance();
    void Update();
    bool Enter();
    void Leave();
    bool IsEnd();
    TYPE GetType();
    bool IsNeedEnd();
};

#endif /* defined(__Core__LeisureIOILove__) */
