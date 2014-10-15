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
class CoreSerializ
{
public:
    virtual void Serializ(FILE* out)=0;
    virtual void UnSerializ(FILE* in)=0;
};
#endif /* defined(__Core__Serializ__) */
