//
//  Girl.h
//  Core
//
//  Created by 孙昕 on 14/10/22.
//
//

#ifndef __Core__Girl__
#define __Core__Girl__

#include "PersonBase.h"
#include "Mood.h"
#include "Favorite.h"
#include "../util/Header.h"
#define GIRLINSTANCE CoreGirlSingleton::GetInstance()
class node;
class CoreGirl:public CorePersonBase
{
public:
    enum TYPE {LOLI,MAID,QUEEN};
    CoreGirl();
    ~CoreGirl();
    PERSONTYPE GetType();
    void Serializ(node* out);
    void UnSerializ(node* in);
    CoreMood *GetMood();
    double GetIOI();
    void SetIOI(double lIOI);
    TYPE GetGirlType();
    void SetGirlType(TYPE type);
    CoreFavorite* GetFavorite();
    void Reset(node* pNode,TYPE type);
    long GetOffsetTime();
    double GetOffset();
private:
    CoreMood *m_pMood;
    double m_dIOI;
    TYPE m_Type;
    CoreFavorite *m_pFavorite;
    void OnStatusChange(void *pObj, const std::string& name, void* value);
    long m_lOffsetTime;
    double m_dOffset;
    CoreTime m_StartTime;
};

class CoreGirlSingleton:public CoreSingleton<CoreGirl>
{
private:
    CoreGirlSingleton();
    CoreGirlSingleton(const CoreGirlSingleton&);
    ~CoreGirlSingleton();
    CoreGirlSingleton &operator=(const CoreGirlSingleton&);
    
};
#endif /* defined(__Core__Girl__) */















