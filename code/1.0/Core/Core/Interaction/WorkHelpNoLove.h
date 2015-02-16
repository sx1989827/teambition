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
    void Enter();
    bool TryEnter();
    void Leave();
    bool IsEnd();
    TYPE GetType();
    bool IsNeedEnd();
};

#endif /* defined(__Core__WorkHelpNoLove__) */
