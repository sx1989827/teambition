//
//  Gift.cpp
//  Core
//
//  Created by 孙昕 on 14/11/25.
//
//

#include "Gift.h"
#include "../../Person/Player.h"
#include "../../Person/Girl.h"
#include "../../Person/Favorite.h"
CoreGift::CoreGift()
{
    xml x;
    x.loadfile(GIFTFILE);
    nodecollect *nc=x.select("//item");
    for(long i=0;i<nc->getcount();i++)
    {
        std::string name=nc->item(i)->getattr("name");
        double price=atoi(nc->item(i)->getattr("price").data());
        m_MapGift[name]=price;
    }
    delete nc;
    memset(m_cLoliChance, 0, 19);
    memset(m_cLoliChance+19, 40, 9);
    memset(m_cLoliChance+29, 60, 9);
    memset(m_cLoliChance+39, 70, 9);
    memset(m_cLoliChance+49, 100, 50);
    memset(m_cMaidChance, 0, 29);
    memset(m_cMaidChance+29, 40, 9);
    memset(m_cMaidChance+39, 60, 9);
    memset(m_cMaidChance+49, 80, 9);
    memset(m_cMaidChance+59, 100, 40);
    memset(m_cQueenChance, 0, 39);
    memset(m_cQueenChance+39, 40, 9);
    memset(m_cQueenChance+49, 60, 9);
    memset(m_cQueenChance+59, 80, 9);
    memset(m_cQueenChance+69, 100, 30);
    m_MapGap[CoreGirl::LOLI]={4,10};
    m_MapGap[CoreGirl::MAID]={4,8};
    m_MapGap[CoreGirl::QUEEN]={4,6};
}

std::map<std::string,double> CoreGift::GetAllGift()
{
    return m_MapGift;
}

bool CoreGift::HandleGift(std::string strName,std::string& err)
{
    auto it=m_MapGift.find(strName);
    if(it==m_MapGift.end())
    {
        err="没有该礼物";
        return false;
    }
    if(PLAYERINSTANCE->GetMoney()<it->second)
    {
        err="余额不足";
        return false;
    }
    char *cChance;
    if(GIRLINSTANCE->GetGirlType()==CoreGirl::LOLI)
    {
        cChance=m_cLoliChance;
    }
    else if (GIRLINSTANCE->GetGirlType()==CoreGirl::MAID)
    {
        cChance=m_cMaidChance;
    }
    else if (GIRLINSTANCE->GetGirlType()==CoreGirl::QUEEN)
    {
        cChance=m_cQueenChance;
    }
    long chance=cChance[(long)GIRLINSTANCE->GetIOI()-1];
    long rnd=random()%100;
    if(rnd>chance)
    {
        err="女主不接受";
        return false;
    }
    sGap gap=m_MapGap[GIRLINSTANCE->GetGirlType()];
    double dIOI=gap.min+random()%(gap.max-gap.min+1);
    sFavItem item;
    item.type="gift";
    item.name=strName;
    if(GIRLINSTANCE->GetFavorite()->QueryLike(&item))
    {
        dIOI*=2;
    }
    GIRLINSTANCE->SetIOI(GIRLINSTANCE->GetIOI()+dIOI);
    return true;
}














