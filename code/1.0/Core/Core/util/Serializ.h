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
#include "Xml.h"

class CoreSerializ
{
public:
    virtual void Serializ(node* out)=0;
    virtual void UnSerializ(node* in)=0;
protected:
    template <class T>
    node* WriteXml(node* out,T v,const char* str)
    {
        node* n=out->getXml()->createnode(str);
        n->puttext(v);
        out->appned(n);
        return n;
    }
};
#endif /* defined(__Core__Serializ__) */






