//
//  StatusController.h
//  Core
//
//  Created by 孙昕 on 14/10/22.
//
//

#ifndef __Core__StatusController__
#define __Core__StatusController__
#include "Status.h"
class CorePlayer;
class CoreStatusController
{
public:
    CoreStatusController();
    ~CoreStatusController();
    CoreStatus::TYPE GetStatus();
    void Rollback();
    void ChangeStatus(CoreStatus::TYPE type);
    void Update();
private:
    CoreStatus *m_pStatus;
    CoreStatus *m_pPreStatus;
};

#endif /* defined(__Core__StatusController__) */
