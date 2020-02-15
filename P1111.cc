// 运用启发式合并(将一棵点数与深度都较小的集合树连接到一棵更大的集合树下) 
// 显然相比于另一种连接方案 其期望复杂度更优也会带来更优的最坏复杂度
// 由于路径压缩单次合并可能造成大量修改，有时路径压缩并不适合使用
// 参考:https://oi-wiki.org/ds/dsu/
#include <iostream>
#include <algorithm>
using std::swap;
using index_t=unsigned int;
struct record
{
    index_t towna=0;
    index_t townb=0;
    index_t time=0;
};
index_t towncnt, recordcnt;
index_t size[1010], parents[1010];
record records[100010];
index_t Find(index_t k,index_t parents[])
{
    if (k==parents[k]) return k;
    return parents[k]=Find(parents[k],parents);
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cout.sync_with_stdio(false);
    std::cin>>towncnt>>recordcnt;
    for (index_t i=0;i<recordcnt;++i)
    {
        std::cin>>records[i].towna>>records[i].townb>>records[i].time;
    }
    for (index_t i=0;i<towncnt;++i)
    {
        parents[i]=i;
        size[i]=1;
    }
    std::sort(records,records+recordcnt,[](const record& lhs,const record& rhs){return lhs.time<rhs.time;});
    for (index_t i=0;i<recordcnt;++i)
    {
        int townaparent=Find(records[i].towna,parents);
        int townbparent=Find(records[i].townb,parents);
        if (townaparent!=townbparent)
        {
            if (size[townaparent]>size[townbparent])
                swap(townaparent,townbparent);
            parents[townaparent]=townbparent;
            size[townbparent]+=size[townaparent];
        }
        if (size[townbparent]==towncnt)
        {
            std::cout<<records[i].time<<std::endl;
            return 0;
        }
    }
    std::cout<<-1<<std::endl;
    return 0;
}