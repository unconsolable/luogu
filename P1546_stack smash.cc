#include <iostream>
#include <algorithm>
#define MAXEDGE 5000
#define MAXVEX 400
#define INFINITY 100000
struct Edge
{
    int begin;
    int end;
    int64_t weight;
};
int parent[MAXVEX];
Edge edges[MAXEDGE];
//并查集
int Find(int parent[],int k)
{
    int k_orig=k;
    while (parent[k]!=k)
        k=parent[k];
    return parent[k_orig]=k;
}
int64_t MiniSpanTree_Kruskal(Edge edges[],int edgecnt,int nodecnt)
{
    int64_t sum=0;
    for (int i=0;i<nodecnt;++i)
    {
        parent[i]=i;
    }
    auto SortRule=[](Edge &i,Edge &j){return i.weight<j.weight;};
    std::sort(edges,edges+edgecnt,SortRule);
    for (int i=0;i<edgecnt;++i)
    {
        int fatherofbegin=Find(parent,edges[i].begin);
        int fatherofend=Find(parent,edges[i].end);
        //若起点与终点在同一并查集 则选边会形成环
        if (fatherofbegin!=fatherofend)
        {
            sum+=edges[i].weight;
            parent[fatherofbegin]=fatherofend;
        }
    }
    return sum;
}
int main()
{
    int vexNum,edgeNum=0;
    std::cin>>vexNum;
    for (int i=0;i<vexNum;++i)
    {
        for (int j=0;j<vexNum;++j)
        {
            int64_t tmp;
            std::cin>>tmp;
            if (i<=j&&tmp)
            {
                edges[edgeNum].begin=i;
                edges[edgeNum].end=j;
                edges[edgeNum++].weight=tmp;
            }
        }
    }
    std::cout<<MiniSpanTree_Kruskal(edges,edgeNum,vexNum);
}