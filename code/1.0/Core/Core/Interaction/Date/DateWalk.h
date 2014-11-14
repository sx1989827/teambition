//
//  DateWalk.h
//  Core
//
//  Created by 孙昕 on 14/11/13.
//
//

#ifndef __Core__DateWalk__
#define __Core__DateWalk__

#include "DateBase.h"
class CoreDateWalk:public CoreDateBase
{
public:
    bool Enter();
    void Update();
    void Leave();
    TYPE GetType();
    bool IsEnd();
};

#endif /* defined(__Core__DateWalk__) */
