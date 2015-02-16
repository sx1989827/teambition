//
//  DateNoLove.h
//  Core
//
//  Created by 孙昕 on 14/11/11.
//
//

#ifndef __Core__DateNoLove__
#define __Core__DateNoLove__

#include "Interaction.h"
#include "DateBase.h"
class CoreDateNoLove:public CoreInteraction
{
public:
    static CoreInteraction* CreateInstance();
    void Update();
    void Enter();
    bool TryEnter();
    void Leave();
    bool IsEnd();
    TYPE GetType();
    bool IsNeedEnd();
    void SetDateType(CoreDateBase::TYPE type);
    ~CoreDateNoLove();
    CoreDateNoLove();
private:
    CoreDateBase *m_pDate;
};

#endif /* defined(__Core__DateNoLove__) */
