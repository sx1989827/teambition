//
//  Serializ.h
//  Core
//
//  Created by 孙昕 on 14-10-14.
//
//

#ifndef __Core__Serializ__
#define __Core__Serializ__

#include <stdio.h>
#include <map>
class CoreSerializ
{
protected:
    virtual void Serializ(std::map<std::string, std::string> &map)=0;
    virtual void UnSerializ(std::map<std::string, std::string> &map)=0;
};
#endif /* defined(__Core__Serializ__) */
