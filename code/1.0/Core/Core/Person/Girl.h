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
class CoreGirl:public CorePersonBase
{
public:
    enum TYPE {LOLI,MAID,QUEEN};
    CoreGirl();
    ~CoreGirl();
    void BuildFavorite();
    PERSONTYPE GetType();
    void Serializ(node* out);
    void UnSerializ(node* in);
private:
    CoreMood *m_pMood;
    long m_lIOI;
    TYPE m_Type;
    CoreFavorite *m_pFavorite;
    
};
#endif /* defined(__Core__Girl__) */
