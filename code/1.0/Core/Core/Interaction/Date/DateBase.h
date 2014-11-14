//
//  DateBase.h
//  Core
//
//  Created by 孙昕 on 14/11/13.
//
//

#ifndef __Core__DateBase__
#define __Core__DateBase__
#include "../../util/Time.h"
class CoreDateBase
{
public:
    enum TYPE {EAT,FILM,WALK,PARK};
    virtual bool Enter()=0;
    virtual void Update()=0;
    virtual void Leave()=0;
    virtual TYPE GetType()=0;
    virtual bool IsEnd()=0;
    void SetIOI(bool bIOI);
    CoreDateBase();
    virtual ~CoreDateBase(){}
protected:
    double GetIOIValue(double min,double max);
    CoreTime m_StartTime;
    CoreTime m_FlagTime;
    bool m_bEnd;
    bool m_bIOI;
};

#endif /* defined(__Core__DateBase__) */












