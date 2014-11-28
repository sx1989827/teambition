//
//  ActionBody.h
//  Core
//
//  Created by 孙昕 on 14/11/28.
//
//

#ifndef __Core__ActionBody__
#define __Core__ActionBody__
#include "../../util/Header.h"
#include <string>
#include <vector>
#include <map>
struct sActionBodyPremise
{
    double dPhysical;
    double dIOI;
    std::string strMood;
    double dPhysicalOffset;
    std::string strPlace;
    bool bLove;
};
struct sActionBodyMoodChange
{
    std::string strMood;
    std::string strMoodTrend;
    std::string strMoodDes;
    long lMoodOffset;
    double dIOIOffset;
};

struct sActionBodyMood
{
    double dOpenIOI;
    std::map<std::string, sActionBodyMoodChange> mapMood;
};

struct sActionBody
{
    long type;
    bool bOpen;
    sActionBodyPremise sPremise;
    std::vector<sActionBodyMood> vecGirl;
};



class CoreActionBody:public CoreSerializ
{
public:
    enum TYPE {PATSHOULDER,TOUCHHAIR,TOUCHHAND,KNEADFACE,HUG,KISS,MASSAGE,FINGERWAR,HUGWAIST,RUBNOSE,HANDINHAND,LIFT  };
    CoreActionBody();
    void Serializ(node* out);
    void UnSerializ(node* in);
    std::vector<TYPE> GetAvalibleAction();
    void Handle(TYPE type);
private:
    std::map<TYPE,sActionBody> m_MapAction;
};

#endif /* defined(__Core__ActionBody__) */










