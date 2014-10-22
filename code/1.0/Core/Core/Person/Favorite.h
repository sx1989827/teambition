//
//  Favorite.h
//  Core
//
//  Created by 孙昕 on 14/10/22.
//
//

#ifndef __Core__Favorite__
#define __Core__Favorite__
#include "../util/Serializ.h"
#include <vector>
#include <string>
struct sFavItem
{
    std::string type;
    std::string name;
    long flag;
};
class CoreFavorite:public CoreSerializ
{
public:
    void Serializ(node* out);
    void UnSerializ(node* in);
    bool QueryLike(const sFavItem* str);
    bool QueryDisLike(const sFavItem* str);
    void Build(const std::string& str);
private:
    std::vector<sFavItem> m_VecLike;
    std::vector<sFavItem> m_VecDisLike;
};

#endif /* defined(__Core__Favorite__) */
