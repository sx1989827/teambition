//
//  WorkMeetNoLove.h
//  Core
//
//  Created by 孙昕 on 14/11/11.
//
//

#ifndef __Core__WorkMeetNoLove__
#define __Core__WorkMeetNoLove__

#include "Interaction.h"
class CoreWorkMeetNoLove:public CoreInteraction
{
public:
    static CoreInteraction* CreateInstance();
    void Update();
    bool IsEnd();
    TYPE GetType();
};

#endif /* defined(__Core__WorkMeetNoLove__) */
