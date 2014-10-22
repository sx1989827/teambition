//
//  PersonBase.h
//  Core
//
//  Created by 孙昕 on 14/10/21.
//
//

#ifndef __Core__PersonBase__
#define __Core__PersonBase__

#include "../util/Serializ.h"
#include "../Status/StatusController.h"
class CorePersonBase:public CoreSerializ
{
protected:
    CoreStatusController * m_pStatusController;
};
#endif /* defined(__Core__PersonBase__) */
