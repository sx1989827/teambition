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
class node;
class CoreGirl:public CorePersonBase
{
public:
    enum TYPE {LOLI,MAID,QUEEN};
    CoreGirl();
    ~CoreGirl();
    void BuildFavorite(node* pNode);
    PERSONTYPE GetType();
    void Serializ(node* out);
    void UnSerializ(node* in);
    CoreMood *GetMood();
    long GetIOI();
    void SetIOI(long lIOI);
    TYPE GetGirlType();
    void SetGirlType(TYPE type);
    CoreFavorite* GetFavorite();
private:
    CoreMood *m_pMood;
    long m_lIOI;
    TYPE m_Type;
    CoreFavorite *m_pFavorite;
    void OnStatusChange(void *pObj, const char *name, void* value);
};
#endif /* defined(__Core__Girl__) */
