//
//  ActionTalk.h
//  Core
//
//  Created by 孙昕 on 14/12/2.
//
//

#ifndef __Core__ActionTalk__
#define __Core__ActionTalk__
#include <vector>
#include <map>
#include <string>
struct sActionTalkInfo
{
    std::string strAction;
    double dIOI[3];
};

struct sActionTalk
{
    std::string strMood;
    std::map<std::string,sActionTalkInfo> mapInfo;
};

class CoreActionTalk
{
public:
    CoreActionTalk();
    std::vector<std::string> GetAvalibleTalk();
    void Handle(std::string strAction);
private:
    std::map<std::string,sActionTalk> m_ActionMap;
    
};

#endif /* defined(__Core__ActionTalk__) */
