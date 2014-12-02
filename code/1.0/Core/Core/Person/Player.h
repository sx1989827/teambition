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
#include "../Interaction/Interaction.h"
#include "../Interaction/Action/ActionEye.h"
#include "../Interaction/Action/ActionBody.h"
#include "../Interaction/Action/ActionTalk.h"
#define PLAYERINSTANCE CorePlayerSingleton::GetInstance()
struct sPlayInfo
{
    long time;
    double offset;
};
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
    const sPlayInfo* GetPhysicalInfo(CoreStatus::TYPE type);
    const sPlayInfo* GetMoneyInfo(CoreStatus::TYPE type);
    bool IsInteraction();
    void Update();
    bool EnterInteraction(CoreInteraction::TYPE type);
    void LeaveInteraction();
    void SetPlace(std::string strPlace);
    std::string GetPlace();
private:
    double m_dPhysical;
    double m_dMoney;
    bool  m_bLove;
    CoreStatusController *m_pStatusController;
    std::map<CoreStatus::TYPE,sPlayInfo> m_mapPhysical;
    std::map<CoreStatus::TYPE,sPlayInfo> m_mapMoney;
    CoreInteraction *m_pInteraction;
    CoreActionEye *m_pActionEye;
    CoreActionBody *m_pActionBody;
    CoreActionTalk *m_pActionTalk;
    std::string m_strPlace;
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















