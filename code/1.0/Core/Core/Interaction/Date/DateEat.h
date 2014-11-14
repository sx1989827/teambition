//
//  DateEat.h
//  Core
//
//  Created by 孙昕 on 14/11/13.
//
//

#ifndef __Core__DateEat__
#define __Core__DateEat__

#include "DateBase.h"
class CoreDateEat:public CoreDateBase
{
public:
    bool Enter();
    void Update();
    void Leave();
    TYPE GetType();
    bool IsEnd();
};

#endif /* defined(__Core__DateEat__) */
