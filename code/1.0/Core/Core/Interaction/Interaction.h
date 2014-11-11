//
//  Interaction.h
//  Core
//
//  Created by 孙昕 on 14/10/22.
//
//

#ifndef __Core__Interaction__
#define __Core__Interaction__
#include <map>
#include "../util/Time.h"
class CoreInteraction
{
public:
    enum TYPE {WORKMEETNOLOVE,WORKIOINOLOVE,WORKHELPNOLOVE,WORKTALKNOLOVE,WORKTALKLOVE,WORKIOILOVE,WORKHELPLOVE,LEISUREIOINOLOVE,LEISURETALKNOLOVE,LEISUREIOILOVE,LEISURETALKLOVE,DATEIOI,DATENOLOVE,DATELOVE};
    static CoreInteraction* CreateInstance(TYPE type);
    virtual void Update()=0;
    virtual bool IsEnd()=0;
    virtual TYPE GetType()=0;
protected:
    CoreTime m_StartTime;
private:
    static bool bInit;
    typedef  CoreInteraction* (*Func)();
    static std::map<TYPE, Func> MapFunc;
};

#endif /* defined(__Core__Interaction__) */
