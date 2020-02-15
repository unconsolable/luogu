#include <iostream>
#include <algorithm>
struct Edge
{
    int begin;
    int end;
    int weight;
};
Edge edges[100010];
int nodecnt, edgecnt;
int maxedgeweight = 0;
int parents[400];
int chooseedgecnt = 0;
inline int Find(int k)
{
    while (parents[k]!=k)
        k=parents[k];
    return k;
}
void Kruskal()
{
    for (int i=0;i<nodecnt;++i)
    {
        parents[i]=i;
    }
    for (int i=0;i<edgecnt&&chooseedgecnt<nodecnt;++i)
    {
        int n=Find(edges[i].begin);
        int m=Find(edges[i].end);
        if (n!=m)
        {
            parents[n]=m;
            ++chooseedgecnt;
            maxedgeweight=edges[i].weight;
        }
    }
}
int main()
{
    std::cin>>nodecnt>>edgecnt;
    for (int i=0;i<edgecnt;++i)
        std::cin>>edges[i].begin>>edges[i].end>>edges[i].weight;
    std::sort(edges,edges+edgecnt,[](const Edge &e1,const Edge &e2){return e1.weight<e2.weight;});
    Kruskal();
    std::cout<<chooseedgecnt<<' '<<maxedgeweight<<std::endl;
}