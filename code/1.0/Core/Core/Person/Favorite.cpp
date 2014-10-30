//
//  Favorite.cpp
//  Core
//
//  Created by 孙昕 on 14/10/22.
//
//

#include "Favorite.h"
#include "../util/Constant.h"
#include <algorithm>
void CoreFavorite::Serializ(node* out)
{
    node *root=out->getXml()->createnode("Favorite");
    node *like=out->getXml()->createnode("like");
    for(int i=0;i<m_VecLike.size();i++)
    {
        node *item=out->getXml()->createnode("item");
        item->setattr("type", m_VecLike[i].type);
        item->setattr("name", m_VecLike[i].name);
        item->setattr("flag", m_VecLike[i].flag);
        like->appned(item);
    }
    root->appned(like);
    node *dislike=out->getXml()->createnode("dislike");
    for(int i=0;i<m_VecDisLike.size();i++)
    {
        node *item=out->getXml()->createnode("item");
        item->setattr("type", m_VecLike[i].type);
        item->setattr("name", m_VecLike[i].name);
        item->setattr("flag", m_VecLike[i].flag);
        dislike->appned(item);
    }
    root->appned(dislike);
    out->appned(root);
}
void CoreFavorite::UnSerializ(node* in)
{
    std::vector<sFavItem>().swap(m_VecLike);
    std::vector<sFavItem>().swap(m_VecDisLike);
    nodecollect *nc=in->select("/Favorite");
    node* root=nc->item(0);
    nodecollect *like=root->select("/like/item");
    for(long i=0;i<like->getcount();i++)
    {
        sFavItem item;
        item.type=like->item(i)->getattr("type");
        item.name=like->item(i)->getattr("name");
        item.flag=atol(like->item(i)->getattr("flag").data());
        m_VecLike.push_back(item);
    }
    delete like;
    nodecollect *dislike=root->select("/dislike/item");
    for(long i=0;i<dislike->getcount();i++)
    {
        sFavItem item;
        item.type=dislike->item(i)->getattr("type");
        item.name=dislike->item(i)->getattr("name");
        item.flag=atol(dislike->item(i)->getattr("flag").data());
        m_VecDisLike.push_back(item);
    }
    delete dislike;
    delete nc;
}
bool CoreFavorite::QueryLike(const sFavItem* str)
{
    for(int i=0;i<m_VecLike.size();i++)
    {
        if(m_VecLike[i].type==str->type && m_VecLike[i].name==str->name)
        {
            return true;
        }
    }
    return false;
}
bool CoreFavorite::QueryDisLike(const sFavItem* str)
{
    for(int i=0;i<m_VecDisLike.size();i++)
    {
        if(m_VecDisLike[i].type==str->type && m_VecDisLike[i].name==str->name)
        {
            return true;
        }
    }
    return false;
}
void CoreFavorite::Build(node* pNode)
{
    nodecollect *nc=pNode->select("/favorite");
    node* root=nc->item(0)->getchild(0);
    do{
        std::string tag=root->gettag();
        vector<sFavItem> vec;
        nodecollect *col= root->select("/item");
        for(int i=0;i<col->getcount();i++)
        {
            sFavItem item;
            item.type=tag;
            item.name=col->item(i)->gettext();
            if(tag=="gift")
            {
                item.flag=atol(col->item(i)->getattr("price").data());
            }
            else
            {
                item.flag=0;
            }
            vec.push_back(item);
        }
        delete col;
        if(vec.size()>0)
        {
            long i=2;
            while (i-- && !vec.empty()) {
                long rnd=random()%vec.size();
                m_VecLike.push_back(vec[rnd]);
                vec.erase(vec.begin()+rnd);
            }
            if(tag!="gift")
            {
                i=2;
                while (i-- && !vec.empty()) {
                    long rnd=random()%vec.size();
                    m_VecDisLike.push_back(vec[rnd]);
                    vec.erase(vec.begin()+rnd);
                }
            }
            
        }

    }while ((root=root->getnext())!=0) ;
    delete nc;
}


















