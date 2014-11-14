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
#include "DateBase.h"
class CoreDateIOI:public CoreInteraction
{
public:
    static CoreInteraction* CreateInstance();
    void Update();
    bool Enter();
    void Leave();
    bool IsEnd();
    TYPE GetType();
    bool IsNeedEnd();
    void SetDateType(CoreDateBase::TYPE type);
    ~CoreDateIOI();
    CoreDateIOI();
private:
    CoreDateBase *m_pDate;
};

#endif /* defined(__Core__DateIOI__) */
