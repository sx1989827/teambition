//
//  DateLove.h
//  Core
//
//  Created by 孙昕 on 14/11/11.
//
//

#ifndef __Core__DateLove__
#define __Core__DateLove__

#include "Interaction.h"
class CoreDateLove:public CoreInteraction
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

#endif /* defined(__Core__DateLove__) */
