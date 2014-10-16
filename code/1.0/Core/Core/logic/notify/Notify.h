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
#include <queue>
#include <string>
#include <list>
#include "../../util/Header.h"
#define  NOTIFYCENTER CoreNotifySingleton::GetInstance()
struct sNotify
{
    enum TYPE {CALL,DATEEND,ARDERIOI,WORKIOI,WORKMEET};
    long id;
    long sec;
    char szText[100];
    TYPE type;
    bool bEnabled;
    long flag;
};
class CoreNotify:public CoreSerializ
{
public:
    CoreNotify();
    ~CoreNotify();
    long CreateNotify(sNotify* pNotify);
    void GetLastNotify(sNotify *pNotify) const;
    void PopNotify();
    void ClearAllNotify();
    void Serializ(FILE* out);
    void UnSerializ(FILE* in);
private:
    std::queue<sNotify> m_Queue;
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







