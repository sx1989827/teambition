//
//  ActionEye.cpp
//  Core
//
//  Created by 孙昕 on 14/11/27.
//
//

#include "ActionEye.h"
#include "../../util/Header.h"
#include "../../Person/Player.h"
#include "../../Person/Girl.h"
#include "../../Person/Mood.h"
CoreActionEye::CoreActionEye()
{
    xml x;
    x.loadfile(ACTIONEYEFILE);
    nodecollect *ncRoot=x.select("/root");
    node *root=ncRoot->item(0)->getchild(0);
    do
    {
        sActionEye info;
        if(root->gettag()=="lookface")
        {
            info.type=LOOKFACE;
        }
        else if (root->gettag()=="gazeface")
        {
            info.type=GAZEFACE;
        }
        else if (root->gettag()=="lookbreast")
        {
            info.type=LOOKBREAST;
        }
        else if (root->gettag()=="gazebreast")
        {
            info.type=GAZEBREAST;
        }
        info.sPremise.strMood=root->getattr("mood");
        info.sPremise.dPhysical=atof(root->getattr("physical").data());
        info.sPremise.dIOI=atof(root->getattr("ioi").data());
        info.sPremise.dPhysicalOffset=atof(root->getattr("physicaloffset").data());
        node* n1=root->getchild(0);
        do
        {
            std::map<std::string, sActionEyeMoodChange> mapMood;
            nodecollect *ncItem=n1->select("/item");
            for(long i=0;i<ncItem->getcount();i++)
            {
                sActionEyeMoodChange mood;
                node *item=ncItem->item(i);
                mood.strMood=item->getattr("mood");
                mood.strMoodTrend=item->getattr("moodtrend");
                mood.lMoodOffset=atoi(root->getattr("moodoffset").data());
                mood.dIOIOffset=atof(root->getattr("ioi").data());
                mood.strMoodDes=item->getattr("mooddes");
                mapMood[mood.strMood]=mood;
            }
            info.vecGirl.push_back(mapMood);
        }while((n1=n1->getnext()));
        m_MapAction[(TYPE)info.type]=info;
    }while ((root=root->getnext()));
    delete ncRoot;
}

bool CoreActionEye::Handle(CoreActionEye::TYPE type)
{
    auto it=m_MapAction.find(type);
    if(it==m_MapAction.end())
    {
        return false;
    }
    if(PLAYERINSTANCE->GetPhysical()<it->second.sPremise.dPhysical || (it->second.sPremise.strMood.size()>0 && strstr(it->second.sPremise.strMood.data(),GIRLINSTANCE->GetMood()->GetStrMood().data())==0) || GIRLINSTANCE->GetIOI()<it->second.sPremise.dIOI)
    {
        return false;
    }
    long i=0;
    switch (GIRLINSTANCE->GetGirlType()) {
        case CoreGirl::LOLI:
            i=0;
            break;
        case CoreGirl::MAID:
            i=1;
            break;
        case CoreGirl::QUEEN:
            i=2;
            break;
        default:
            break;
    }
    PLAYERINSTANCE->SetPhysical(PLAYERINSTANCE->GetPhysical()+it->second.sPremise.dPhysicalOffset);
    sActionEyeMoodChange mood=it->second.vecGirl[i][GIRLINSTANCE->GetMood()->GetStrMood()];
    double off=PLAYERINSTANCE->GetMoney()*0.0001+(GIRLINSTANCE->GetIOI()-50)/100.0f;
    GIRLINSTANCE->SetIOI(GIRLINSTANCE->GetIOI()+mood.dIOIOffset+off);
    if(it->first==GAZEFACE || it->first==LOOKBREAST || it->first==GAZEBREAST)
    {
        sMood MoodTransfer;
        MoodTransfer.strDes=mood.strMoodDes;
        MoodTransfer.strMood=mood.strMoodTrend;
        MoodTransfer.lOffset=mood.lMoodOffset;
        GIRLINSTANCE->GetMood()->Transfer(&MoodTransfer);
    }
    return true;
}
















