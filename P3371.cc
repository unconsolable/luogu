#include <iostream>
#include <queue>
#include <cstring>
#define MAXVEX 10010
using IndexType=unsigned int;
struct EdgeNode
{
    IndexType endindex;
    IndexType weight;
    EdgeNode* next=nullptr;
    ~EdgeNode()
    {
        if (next) 
        {
            delete next;
            next=nullptr;
        }
    }
};
struct VexNode
{
    //IndexType data;
    EdgeNode *firstEdge=nullptr;
    ~VexNode()
    {
        if (firstEdge) 
        {
            delete firstEdge;
            firstEdge=nullptr;
        }
    }
};
struct Graph
{
    VexNode vexs[MAXVEX];
    IndexType vexcnt,edgecnt;
};
inline void DestroyGraph(Graph &g1)
{
    for (IndexType i=0;i<g1.vexcnt;++i)
    {
        if (!g1.vexs[i].firstEdge)
        {
            delete g1.vexs[i].firstEdge;
            g1.vexs[i].firstEdge=nullptr;
        }
    }
}
void SPFA(const Graph &g1,IndexType start,IndexType dist[])
{
    std::queue<IndexType> nextspfa;
    bool visited[MAXVEX]={};
    nextspfa.push(start);
    visited[start]=true;
    while (!nextspfa.empty())
    {
        auto curr=nextspfa.front();
        nextspfa.pop();
        visited[curr]=false;
        for (auto i=g1.vexs[curr].firstEdge;i;i=i->next)
        {
            if (dist[curr]+i->weight<dist[i->endindex])
            {
                if (!visited[i->endindex])
                {
                    visited[i->endindex]=true;
                    nextspfa.push(i->endindex);
                }
                dist[i->endindex]=dist[curr]+i->weight;
            }
        }
    }
}
int main()
{
    Graph g1;IndexType startp;
    IndexType dist[MAXVEX];
    std::cin>>g1.vexcnt>>g1.edgecnt>>startp;
    for (IndexType i=0;i<g1.vexcnt;++i)
    {
        if (i!=startp-1)
            dist[i]=2147483647;
        else
            dist[i]=0;
    }
    for (IndexType i=0;i<g1.edgecnt;++i)
    {
        IndexType begin,end,weight;
        std::cin>>begin>>end>>weight;
        auto e=new EdgeNode();
        e->endindex=end-1;
        e->weight=weight;
        e->next=g1.vexs[begin-1].firstEdge;
        g1.vexs[begin-1].firstEdge=e;
    }
    SPFA(g1,startp-1,dist);
    for (IndexType i=0;i<g1.vexcnt;++i)
    {
        std::cout<<dist[i]<<' ';
    }
    DestroyGraph(g1);
}