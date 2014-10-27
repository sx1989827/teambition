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
class CoreStatusController;
class CorePersonBase:public CoreSerializ
{
public:
    enum PERSONTYPE {PLAYER,GIRL};
    virtual ~CorePersonBase(){}
    virtual PERSONTYPE GetType()=0;
};
#endif /* defined(__Core__PersonBase__) */
