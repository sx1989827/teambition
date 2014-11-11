//
//  WorkTalkLove.h
//  Core
//
//  Created by 孙昕 on 14/11/11.
//
//

#ifndef __Core__WorkTalkLove__
#define __Core__WorkTalkLove__

#include "Interaction.h"
class CoreWorkTalkLove:public CoreInteraction
{
public:
    static CoreInteraction* CreateInstance();
    void Update();
    bool IsEnd();
    TYPE GetType();
};

#endif /* defined(__Core__WorkTalkLove__) */
