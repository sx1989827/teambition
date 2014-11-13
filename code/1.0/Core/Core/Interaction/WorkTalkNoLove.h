//
//  WorkTalkNoLove.h
//  Core
//
//  Created by 孙昕 on 14/11/11.
//
//

#ifndef __Core__WorkTalkNoLove__
#define __Core__WorkTalkNoLove__

#include "Interaction.h"
class CoreWorkTalkNoLove:public CoreInteraction
{
public:
    static CoreInteraction* CreateInstance();
    void Update();
    bool IsEnd();
    TYPE GetType();
    bool IsNeedEnd();
};

#endif /* defined(__Core__WorkTalkNoLove__) */
