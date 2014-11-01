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
#define PLAYERINSTANCE CorePlayerSingleton::GetInstance()
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
    double GetPhysical();
    void SetPhysical(double val);
    double GetMoney();
    void SetMoney(double val);
    bool GetLove();
    void SetLove(bool bLove);
    void Reset(node* pNode);
private:
    double m_dPhysical;
    double m_dMoney;
    bool  m_bLove;
    CoreStatusController *m_pStatusController;
};

class CorePlayerSingleton:public CoreSingleton<CorePlayer>
{
private:
    CorePlayerSingleton();
    CorePlayerSingleton(const CorePlayerSingleton&);
    ~CorePlayerSingleton();
    CorePlayerSingleton &operator=(const CorePlayerSingleton&);
    
};
#endif /* defined(__Core__Player__) */















