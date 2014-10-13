//
//  main.cpp
//  Core
//
//  Created by 孙昕 on 14-10-13.
//
//

#include <iostream>
#include "util/Header.h"
int main(int argc, const char * argv[])
{
    CoreLog *pLog=new CoreLog;
    CoreLogSingleton::SetInstance(pLog);
    LOG("123");
    LOG1("%d",45);
    std::cout<<CoreTime::GetTimeSinceNow(60*60).GetTime().data()<<std::endl;
}
