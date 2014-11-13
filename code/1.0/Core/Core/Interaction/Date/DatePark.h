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
    virtual bool Enter()=0;
    virtual void Update()=0;
    virtual void Leave()=0;
    TYPE GetType();
    bool IsEnd();
};

#endif /* defined(__Core__DatePark__) */
