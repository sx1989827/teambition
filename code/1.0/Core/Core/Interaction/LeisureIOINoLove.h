//
//  LeisureIOINoLove.h
//  Core
//
//  Created by 孙昕 on 14/11/11.
//
//

#ifndef __Core__LeisureIOINoLove__
#define __Core__LeisureIOINoLove__

#include "Interaction.h"
class CoreLeisureIOINoLove:public CoreInteraction
{
public:
    static CoreInteraction* CreateInstance();
    void Update();
    bool IsEnd();
    TYPE GetType();
};

#endif /* defined(__Core__LeisureIOINoLove__) */
