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
#include "Header.h"
struct sNotify
{
    enum TYPE {CALL,DATEEND,ARDERIOI,WORKIOI,WORKMEET};
    long id;
    long sec;
    std::string str;
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
    void RemoveNotify(long id);
    void QueryOverdueNotify(std::list<sNotify> *map,long sec) const;
    void ClearAllNotify();
protected:
    void Serializ(std::map<std::string, std::string> *map);
    void UnSerializ(std::map<std::string, std::string> *map);
private:
    std::queue<sNotify> m_Queue;
    static char cID[100];
    static long pos;
};
#endif /* defined(__Core__Notify__) */







