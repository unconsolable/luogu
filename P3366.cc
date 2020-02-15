#include <iostream>
#include <algorithm>
typedef unsigned long IndexType;
struct Edge
{
    IndexType begin;
    IndexType end;
    IndexType weight;
};
int Find(IndexType k,IndexType parents[])
{
    if (k!=parents[k])
        return parents[k]=Find(parents[k],parents);
    return k;
}
IndexType Kruskal(const Edge e[],unsigned long long& ans,const IndexType& vexnum,const IndexType& edgenum)
{
    IndexType parents[vexnum],hasfind=1;
    for (IndexType i=0;i<vexnum;++i)
        parents[i]=i;
    for (IndexType i=0;i<edgenum-1;++i)
    {
        IndexType j=Find(e[i].begin-1,parents);
        IndexType k=Find(e[i].end-1,parents);
        if (j!=k)
        {
            parents[j]=k;
            ++hasfind;
            ans+=e[i].weight;
        }
    }
    return hasfind;
}
int main()
{
    IndexType vexnum,edgenum;
    unsigned long long ans=0;
    Edge edges[200010];
    std::cin>>vexnum>>edgenum;
    for (IndexType i=0;i<edgenum;++i)
    {
        std::cin>>edges[i].begin>>edges[i].end>>edges[i].weight;
    }
    std::sort(edges,edges+edgenum,[](const Edge& e1,const Edge& e2){return e1.weight<e2.weight;});
    if (Kruskal(edges,ans,vexnum,edgenum)<vexnum)
    {
        std::cout<<"orz"<<std::endl;
    }
    else
    {
        std::cout<<ans<<std::endl;
    }
    
}