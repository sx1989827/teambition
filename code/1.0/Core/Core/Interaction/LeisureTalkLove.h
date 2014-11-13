//
//  LeisureTalkLove.h
//  Core
//
//  Created by 孙昕 on 14/11/11.
//
//

#ifndef __Core__LeisureTalkLove__
#define __Core__LeisureTalkLove__

#include "Interaction.h"
class CoreLeisureTalkLove:public CoreInteraction
{
public:
    static CoreInteraction* CreateInstance();
    void Update();
    bool IsEnd();
    TYPE GetType();
    bool IsNeedEnd();
};

#endif /* defined(__Core__LeisureTalkLove__) */
