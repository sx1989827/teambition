//
//  Player.h
//  Core
//
//  Created by 孙昕 on 14/10/22.
//
//

#ifndef __Core__Player__
#define __Core__Player__

#include "PersonBase.h"
#include "../Status/Status.h"
class CorePlayer:public CorePersonBase
{
public:
    CorePlayer();
    ~CorePlayer();
    PERSONTYPE GetType();
    void Serializ(node* out);
    void UnSerializ(node* in);
    void ChangeStatus(CoreStatus::TYPE type);
    CoreStatusController* GetStatusController();
    long GetPhysical();
    void SetPhysical(long val);
    long GetMoney();
    void SetMoney(long val);
    bool GetLove();
    void SetLove(bool bLove);
    void Reset(node* pNode);
private:
    long m_lPhysical;
    long m_lMoney;
    bool  m_bLove;
    CoreStatusController *m_pStatusController;
};

#endif /* defined(__Core__Player__) */
