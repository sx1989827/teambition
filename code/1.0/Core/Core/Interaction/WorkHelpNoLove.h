//
//  WorkHelpNoLove.h
//  Core
//
//  Created by 孙昕 on 14/11/11.
//
//

#ifndef __Core__WorkHelpNoLove__
#define __Core__WorkHelpNoLove__

#include "Interaction.h"
class CoreWorkHelpNoLove:public CoreInteraction
{
public:
    static CoreInteraction* CreateInstance();
    void Update();
    bool IsEnd();
    TYPE GetType();
};

#endif /* defined(__Core__WorkHelpNoLove__) */
