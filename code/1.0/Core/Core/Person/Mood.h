//
//  Mood.h
//  Core
//
//  Created by 孙昕 on 14/10/22.
//
//

#ifndef __Core__Mood__
#define __Core__Mood__
#include "../util/Serializ.h"
class CoreMood:public CoreSerializ
{
public:
    void Serializ(node* out);
    void UnSerializ(node* in);
};

#endif /* defined(__Core__Mood__) */
