//
//  Log.cpp
//  Core
//
//  Created by 孙昕 on 14-10-13.
//
//

#include "Log.h"
#include <assert.h>
void CoreLog::Out(const char *str,...)
{
    va_list args;
    va_start(args, str);
    vprintf(str, args);
    va_end(args);
    printf("\n");
}

void CoreLog::OutFile(const char *str,...)
{
    assert(m_File!=0);
    va_list args;
    va_start(args, str);
    vfprintf(m_File,str, args);
    va_end(args);
    fprintf(m_File, "\n");
}

CoreLog::CoreLog()
{
    m_File=0;
}

CoreLog::~CoreLog()
{
    if(m_File!=0)
    {
        fclose(m_File);
    }
}

bool CoreLog::SetFile(const char* path)
{
    if(m_File!=0)
    {
        fclose(m_File);
    }
    m_File=fopen(path, "ab");
    if(m_File)
    {
        return true;
    }
    else
    {
        return false;
    }
}





