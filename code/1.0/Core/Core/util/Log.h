//
//  Log.h
//  Core
//
//  Created by 孙昕 on 14-10-13.
//
//

#ifndef __Core__Log__
#define __Core__Log__

#include <stdio.h>
#include <iosfwd>
#include "Singleton.h"
#define LOG(STR) CoreLogSingleton::GetInstance()->Out(STR)
#define LOG1(STR,...) CoreLogSingleton::GetInstance()->Out(STR,__VA_ARGS__)
#define LOGF(FILE,STR) CoreLogSingleton::GetInstance()->OutFile(FILE,STR)
#define LOGF1(STR,...) CoreLogSingleton::GetInstance()->OutFile(STR,__VA_ARGS__)
class CoreLog
{
private:
    FILE *m_File;
    CoreLog(const CoreLog&);
    CoreLog& operator =(const CoreLog&);
public:
    CoreLog();
    ~CoreLog();
    bool SetFile(const char* path);
    void Out(const char *,...);
    void OutFile(const char *,...);

};
class CoreLogSingleton:public CoreSingleton<CoreLog>
{
private:
    CoreLogSingleton();
    CoreLogSingleton(const CoreLogSingleton&);
    ~CoreLogSingleton();
    CoreLogSingleton &operator=(const CoreLogSingleton&);
    
};
#endif /* defined(__Core__Log__) */
