//
//  ActionBody.cpp
//  Core
//
//  Created by 孙昕 on 14/11/28.
//
//

#include "ActionBody.h"
#include "../../util/Header.h"
#include "../../Person/Player.h"
#include "../../Person/Girl.h"
#include "../../Person/Mood.h"
CoreActionBody::CoreActionBody()
{
    std::map<std::string,TYPE> mapType;
    mapType["patshoulder"]=PATSHOULDER;
    mapType["touchhair"]=TOUCHHAIR;
    mapType["touchhand"]=TOUCHHAND;
    mapType["kneadface"]=KNEADFACE;
    mapType["hug"]=HUG;
    mapType["kiss"]=KISS;
    mapType["massage"]=MASSAGE;
    mapType["fingerwar"]=FINGERWAR;
    mapType["hugwaist"]=HUGWAIST;
    mapType["rubnose"]=RUBNOSE;
    mapType["handinhand"]=HANDINHAND;
    mapType["lift"]=LIFT;
    xml x;
    x.loadfile(ACTIONBODYFILE);
    nodecollect *ncRoot=x.select("/root");
    node *root=ncRoot->item(0)->getchild(0);
    do
    {
        sActionBody info;
        info.type=mapType[root->gettag()];
        info.bOpen=false;
        info.sPremise.strMood=root->getattr("mood");
        info.sPremise.dPhysical=atof(root->getattr("physical").data());
        info.sPremise.dIOI=atof(root->getattr("ioi").data());
        info.sPremise.dPhysicalOffset=atof(root->getattr("physicaloffset").data());
        node* n1=root->getchild(0);
        do
        {
            sActionBodyMood BodyMood;
            BodyMood.dOpenIOI=atof(n1->getattr("openioi").data());
            nodecollect *ncItem=n1->select("/item");
            for(long i=0;i<ncItem->getcount();i++)
            {
                sActionBodyMoodChange mood;
                node *item=ncItem->item(i);
                mood.strMood=item->getattr("mood");
                mood.strMoodTrend=item->getattr("moodtrend");
                mood.lMoodOffset=atoi(root->getattr("moodoffset").data());
                mood.dIOIOffset=atof(root->getattr("ioi").data());
                mood.strMoodDes=item->getattr("mooddes");
                BodyMood.mapMood[mood.strMood]=mood;
            }
            info.vecGirl.push_back(BodyMood);
            delete ncItem;
        }while((n1=n1->getnext()));
        m_MapAction[(TYPE)info.type]=info;
    }while ((root=root->getnext()));
    delete ncRoot;

}
void CoreActionBody::Serializ(node* out)
{
    
}
void CoreActionBody::UnSerializ(node* in)
{
    
}
std::vector<CoreActionBody::TYPE> CoreActionBody::GetAvalibleAction()
{
    
}
void CoreActionBody::Handle(TYPE type)
{
    
}


















