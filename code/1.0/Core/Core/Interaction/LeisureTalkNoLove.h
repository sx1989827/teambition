//
//  LeisureTalkNoLove.h
//  Core
//
//  Created by 孙昕 on 14/11/11.
//
//

#ifndef __Core__LeisureTalkNoLove__
#define __Core__LeisureTalkNoLove__

#include "Interaction.h"
class CoreLeisureTalkNoLove:public CoreInteraction
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

#endif /* defined(__Core__LeisureTalkNoLove__) */
