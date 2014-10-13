//
//  Time.h
//  Core
//
//  Created by 孙昕 on 14-10-13.
//
//

#ifndef __Core__Time__
#define __Core__Time__
#include <string>
class CoreTime
{
public:
    static std::string GetCurrentTime();
    static std::string GetCurrentDate();
    static std::string GetCurrentMoment();
    static CoreTime GetTimeSinceNow(int sec);
    CoreTime();
    std::string GetTime();
    std::string GetDate();
    std::string GetMoment();
    CoreTime GetTimeSince(int sec);
private:
    long m_lTime;
    
};

#endif /* defined(__Core__Time__) */
