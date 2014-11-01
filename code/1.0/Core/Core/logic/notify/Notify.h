//
//  Notify.h
//  Core
//
//  Created by 孙昕 on 14-10-14.
//
//

#ifndef __Core__Notify__
#define __Core__Notify__

#include <stdio.h>
#include <vector>
#include <string>
#include <list>
#include <map>
#include "../../util/Header.h"
#define  NOTIFYCENTER CoreNotifySingleton::GetInstance()
struct sNotify
{
    enum TYPE {CALL,DATEEND,WORKIOI,WORKMEET,WORKHELP,LEISUREIOI,LEISUREDATE,WORKEVENT,LEISUREEVENT,NONE};
    long id;
    long sec;
    TYPE type;
    long flag;
    struct sInfo
    {
        TYPE type;
        bool bLove;
        char cContext[100];
    };
    static std::vector<sInfo> vecInfo;
    static std::map<std::string,sNotify::TYPE> mapNotify;
};


class CoreNotify:public CoreSerializ
{
public:
    CoreNotify();
    ~CoreNotify();
    void Adjust(bool bLove);
    void Reset(node* pNode);
    long CreateNotify(sNotify* pNotify,long lStatus);//0:leisure,1:sleep,2:work
    sNotify AdjustNotify();
    sNotify::TYPE GetAvailableNotify(long lStatus,bool bLove,long lIOI);
    void ClearNotify();
    void Serializ(node* out);
    void UnSerializ(node* in);
private:
    std::vector<sNotify> m_Vector;
    std::vector<sNotify::TYPE> m_AvailableWorkVec;
    std::vector<sNotify::TYPE> m_AvailableLeisureVec;
    static char cID[100];
    static long pos;
};

class CoreNotifySingleton:public CoreSingleton<CoreNotify>
{
private:
    CoreNotifySingleton();
    CoreNotifySingleton(const CoreNotifySingleton&);
    ~CoreNotifySingleton();
    CoreNotifySingleton &operator=(const CoreNotifySingleton&);
    
};
#endif /* defined(__Core__Notify__) */







