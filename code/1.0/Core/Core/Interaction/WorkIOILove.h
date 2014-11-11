//
//  WorkIOILove.h
//  Core
//
//  Created by 孙昕 on 14/11/11.
//
//

#ifndef __Core__WorkIOILove__
#define __Core__WorkIOILove__

#include "Interaction.h"
class CoreWorkIOILove:public CoreInteraction
{
public:
    static CoreInteraction* CreateInstance();
    void Update();
    bool IsEnd();
    TYPE GetType();
};

#endif /* defined(__Core__WorkIOILove__) */
