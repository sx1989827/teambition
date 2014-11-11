//
//  DateNoLove.h
//  Core
//
//  Created by 孙昕 on 14/11/11.
//
//

#ifndef __Core__DateNoLove__
#define __Core__DateNoLove__

#include "Interaction.h"
class CoreDateNoLove:public CoreInteraction
{
public:
    static CoreInteraction* CreateInstance();
    void Update();
    bool IsEnd();
    TYPE GetType();
};

#endif /* defined(__Core__DateNoLove__) */
