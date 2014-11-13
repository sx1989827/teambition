//
//  WorkIOINoLove.h
//  Core
//
//  Created by 孙昕 on 14/11/11.
//
//

#ifndef __Core__WorkIOINoLove__
#define __Core__WorkIOINoLove__

#include "Interaction.h"
class CoreWorkIOINoLove:public CoreInteraction
{
public:
    static CoreInteraction* CreateInstance();
    void Update();
    bool IsEnd();
    TYPE GetType();
    bool IsNeedEnd();
};

#endif /* defined(__Core__WorkIOINoLove__) */
