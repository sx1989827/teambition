//
//  DatePark.h
//  Core
//
//  Created by 孙昕 on 14/11/13.
//
//

#ifndef __Core__DatePark__
#define __Core__DatePark__

#include "DateBase.h"
class CoreDatePark:public CoreDateBase
{
public:
    void Enter();
    bool TryEnter();
    void Update();
    void Leave();
    TYPE GetType();
    bool IsEnd();
};

#endif /* defined(__Core__DatePark__) */
