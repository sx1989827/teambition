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
#include <map>
#include <string>
struct sMood
{
    std::string strDes;
    std::string strMood;
    long lOffset;
};
class CoreMood:public CoreSerializ
{
public:
    CoreMood();
    ~CoreMood();
    void Adjust();
    void Transfer(sMood* pMood);
    void Serializ(node* out);
    void UnSerializ(node* in);
    void Reset(node* pNode);
    std::string GetStrMood();
    long QueryMoodType(std::string strMood);
private:
    std::map<std::string, long> m_MoodMap;
    std::string m_strCurMood;
    long m_lCurMood;
    std::string m_strDescription;
};

#endif /* defined(__Core__Mood__) */
