//
//  DateIOI.h
//  Core
//
//  Created by 孙昕 on 14/11/11.
//
//

#ifndef __Core__DateIOI__
#define __Core__DateIOI__

#include "Interaction.h"
class CoreDateIOI:public CoreInteraction
{
public:
    static CoreInteraction* CreateInstance();
    void Update();
    bool IsEnd();
    TYPE GetType();
};

#endif /* defined(__Core__DateIOI__) */
