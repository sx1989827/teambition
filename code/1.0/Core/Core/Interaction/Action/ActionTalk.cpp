//
//  ActionTalk.cpp
//  Core
//
//  Created by 孙昕 on 14/12/2.
//
//

#include "ActionTalk.h"
#include "../../Person/Girl.h"
#include "../../Person/Mood.h"
CoreActionTalk::CoreActionTalk()
{
    xml x;
    x.loadfile(GetCurrentDataDir()+ACTIONTALKFILE);
    nodecollect *ncRoot=x.select("/root");
    node *root=ncRoot->item(0)->getchild(0);
    nodecollect *ncMood=root->select("/mood");
    for(long i=0;i<ncMood->getcount();i++)
    {
        sActionTalk talk;
        talk.strMood=ncMood->item(i)->getattr("name");
        nodecollect *ncItem=ncMood->item(i)->select("/action");
        for(long j=0;j<ncItem->getcount();j++)
        {
            sActionTalkInfo info;
            info.strAction=ncItem->item(j)->getattr("name");
            info.dIOI[0]=atof(ncItem->item(j)->getattr("loli").data());
            info.dIOI[1]=atof(ncItem->item(j)->getattr("maid").data());
            info.dIOI[2]=atof(ncItem->item(j)->getattr("queen").data());
            talk.mapInfo[info.strAction]=info;
        }
        delete ncItem;
        m_ActionMap[talk.strMood]=talk;
    }
    delete ncMood;
    delete ncRoot;
}
std::vector<std::string> CoreActionTalk::GetAvalibleTalk()
{
    std::vector<std::string> vec;
    sActionTalk talk=m_ActionMap[GIRLINSTANCE->GetMood()->GetStrMood()];
    for(auto it=talk.mapInfo.begin();it!=talk.mapInfo.end();it++)
    {
        vec.push_back(it->first);
    }
    return vec;
}
void CoreActionTalk::Handle(std::string strAction)
{
    sActionTalkInfo info=m_ActionMap[GIRLINSTANCE->GetMood()->GetStrMood()].mapInfo[strAction];
    GIRLINSTANCE->SetIOI(GIRLINSTANCE->GetIOI()+info.dIOI[GIRLINSTANCE->GetGirlType()]);
}











