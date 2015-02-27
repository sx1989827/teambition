//
//  ActionEye.h
//  Core
//
//  Created by 孙昕 on 14/11/27.
//
//

#ifndef __Core__ActionEye__
#define __Core__ActionEye__
#include <string>
#include <vector>
#include <map>
struct sActionEyePremise
{
    double dPhysical;
    double dIOI;
    std::string strMood;
    double dPhysicalOffset;
};
struct sActionEyeMoodChange
{
    std::string strMood;
    std::string strMoodTrend;
    std::string strMoodDes;
    long lMoodOffset;
    double dIOIOffset;
    std::string strPlayerAction;
};

struct sActionEye
{
    long type;
    sActionEyePremise sPremise;
    std::vector<std::map<std::string, sActionEyeMoodChange>> vecGirl;
};
class CoreActionEye
{
public:
    enum TYPE {LOOKFACE,GAZEFACE,LOOKBREAST,GAZEBREAST};
    CoreActionEye();
    bool Handle(TYPE type);
private:
    std::map<TYPE,sActionEye> m_MapAction;
};

#endif /* defined(__Core__ActionEye__) */













