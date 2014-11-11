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
    bool IsEnd();
    TYPE GetType();
};

#endif /* defined(__Core__LeisureTalkNoLove__) */
