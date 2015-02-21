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
    virtual void Enter()=0;
    virtual bool TryEnter()=0;
    virtual void Update()=0;
    virtual void Leave()=0;
    virtual TYPE GetType()=0;
    virtual bool IsEnd()=0;
    void SetIOI(bool bIOI);
    CoreDateBase();
    virtual ~CoreDateBase(){}
    void SetOldPlace(std::string strPlace);
    std::string GetOldPlace();
protected:
    double GetIOIValue(double min,double max);
    CoreTime m_StartTime;
    CoreTime m_FlagTime;
    bool m_bEnd;
    bool m_bIOI;
    std::string m_strOldPlace;
};

#endif /* defined(__Core__DateBase__) */












