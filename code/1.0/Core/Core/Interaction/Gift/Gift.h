//
//  Gift.h
//  Core
//
//  Created by 孙昕 on 14/11/25.
//
//

#ifndef __Core__Gift__
#define __Core__Gift__
#include "../../util/Header.h"
#include "../../Person/Girl.h"
#define  GIFTCENTER CoreGiftSingleton::GetInstance()
class CoreGift
{
public:
    CoreGift();
    std::map<std::string,double> GetAllGift();
    bool HandleGift(std::string strName,std::string& err);
private:
    std::map<std::string,double> m_MapGift;
    char m_cLoliChance[100];
    char m_cMaidChance[100];
    char m_cQueenChance[100];
    struct sGap
    {
        long min;
        long max;
    };
    std::map<CoreGirl::TYPE,sGap> m_MapGap;
};

class CoreGiftSingleton:public CoreSingleton<CoreGift>
{
private:
    CoreGiftSingleton();
    CoreGiftSingleton(const CoreGiftSingleton&);
    ~CoreGiftSingleton();
    CoreGiftSingleton &operator=(const CoreGiftSingleton&);
    
};
#endif /* defined(__Core__Gift__) */










