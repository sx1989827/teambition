//
//  WorkHelpLove.h
//  Core
//
//  Created by 孙昕 on 14/11/11.
//
//

#ifndef __Core__WorkHelpLove__
#define __Core__WorkHelpLove__

#include "Interaction.h"
class CoreWorkHelpLove:public CoreInteraction
{
public:
    static CoreInteraction* CreateInstance();
    void Update();
    bool IsEnd();
    TYPE GetType();
    bool IsNeedEnd();
};

#endif /* defined(__Core__WorkHelpLove__) */
