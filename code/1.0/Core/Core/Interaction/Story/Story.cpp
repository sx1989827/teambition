//
//  Story.cpp
//  Core
//
//  Created by 孙昕 on 14/11/24.
//
//

#include "Story.h"
#include "../../Person/Player.h"
#include "../../Person/Girl.h"
CoreStory::CoreStory()
{
    xml x;
    x.loadfile(GetCurrentDataDir()+STORYFILE);
    nodecollect *nc=x.select("//item");
    for(long i=0;i<nc->getcount();i++)
    {
        sStory info;
        info.id=atoi(nc->item(i)->getattr("id").data());
        info.dIOI=atof(nc->item(i)->getattr("ioi").data());
        info.dMoney=atof(nc->item(i)->getattr("money").data());
        info.dPhysical=atof(nc->item(i)->getattr("physical").data());
        info.lCount=atoi(nc->item(i)->getattr("count").data());
        info.strSrc=nc->item(i)->getattr("src").data();
        info.bLove=atoi(nc->item(i)->getattr("love").data());
        m_VecStory.push_back(info);
    }
    delete nc;
}
void CoreStory::Serializ(node* out)
{
    node* root=out->getXml()->createnode("Story");
    for(int i=0;i<m_VecUsedStory.size();i++)
    {
        node* item=root->getXml()->createnode("item");
        item->setattr("id", (long)m_VecUsedStory[i]);
        root->appned(item);
    }
    out->appned(root);
}

void CoreStory::UnSerializ(node* in)
{
    std::vector<long>().swap(m_VecUsedStory);
    nodecollect *nc=in->select("/Story");
    node* StoryNode=nc->item(0);
    nodecollect *col=StoryNode->select("/item");
    for(int i=0;i<col->getcount();i++)
    {
        long id=atoi(col->item(i)->getattr("id").data());
        m_VecUsedStory.push_back(id);
        for(long j=0;j<m_VecStory.size();j++)
        {
            if(m_VecStory[j].id==id)
            {
                m_VecStory.erase(m_VecStory.begin()+j);
                break;
            }
        }
    }
    delete col;
    delete nc;
}

sStory CoreStory::GetAvaliableStory()
{
    std::vector<sStory> vec;
    for(long i=0;i<m_VecStory.size();i++)
    {
        if(PLAYERINSTANCE->GetLove()==m_VecStory[i].bLove && PLAYERINSTANCE->GetMoney()>=m_VecStory[i].dMoney && PLAYERINSTANCE->GetPhysical()>=m_VecStory[i].dPhysical && GIRLINSTANCE->GetIOI()>=m_VecStory[i].dIOI && m_VecStory[i].strSrc!="start")
        {
            vec.push_back(m_VecStory[i]);
        }
    }
    if(m_VecStory.size()>0)
    {
        long i=random()%m_VecStory.size();
        sStory info=m_VecStory[i];
        m_VecStory.erase(m_VecStory.begin()+i);
        m_VecUsedStory.push_back(info.id);
        return info;
    }
    else
    {
        sStory info;
        info.id=-1;
        return info;
    }
}

sStory CoreStory::GetStartStory()
{
    sStory info;
    info.id=-1;
    for(long i=0;i<m_VecStory.size();i++)
    {
        if(m_VecStory[i].strSrc=="start")
        {
            info=m_VecStory[i];
            break;
        }
    }
    return info;
}












