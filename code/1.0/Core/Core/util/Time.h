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
#include <time.h>
class CoreTime
{
public:
    static std::string GetCurrentTime();
    static std::string GetCurrentDate();
    static std::string GetCurrentMoment();
    static CoreTime GetTimeSinceNow(long sec);
    CoreTime();
    std::string GetTime() const;
    std::string GetDate() const;
    std::string GetMoment() const;
    CoreTime GetTimeSince(long sec) const;
private:
    time_t m_lTime;
    
};

#endif /* defined(__Core__Time__) */
