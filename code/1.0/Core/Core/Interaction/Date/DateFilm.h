//
//  DateFilm.h
//  Core
//
//  Created by 孙昕 on 14/11/13.
//
//

#ifndef __Core__DateFilm__
#define __Core__DateFilm__

#include "DateBase.h"
class CoreDateFilm:public CoreDateBase
{
public:
    void Enter();
    bool TryEnter();
    void Update();
    void Leave();
    TYPE GetType();
    bool IsEnd();
};

#endif /* defined(__Core__DateFilm__) */
