//
//  ActionEye.cpp
//  Core
//
//  Created by 孙昕 on 14/11/27.
//
//

#include "ActionEye.h"
#include "../../util/Header.h"

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
    
}












