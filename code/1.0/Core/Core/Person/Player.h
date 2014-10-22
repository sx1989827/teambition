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
class CorePlayer:public CorePersonBase
{
public:
    void Serializ(node* out);
    void UnSerializ(node* in);
private:
    long m_lPhysical;
    long m_lMoney;
};

#endif /* defined(__Core__Player__) */
