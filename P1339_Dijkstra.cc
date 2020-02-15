#include <iostream>
#include <queue>
#include <cstring>
#define MAXVEX 2520
#define MAXEDGE 2000
struct Graph
{
    long long edges[MAXVEX][MAXVEX] = {};
    int numvex = 0, numedge = 0;
};
int startpoint, endpoint;
long long dist[MAXVEX];
Graph g1;
void Dijkstra(const int &startp,Graph &g,long long dist[])
{
    bool final[MAXVEX]={};
    for (int i=0;i<g.numvex;++i)
        dist[i]=g.edges[startp][i];
    final[startp]=true;
    for (int i=1;i<g.numvex;++i)
    {
        long long minweight=INT32_MAX;int minind=-1;
        for (int j=0;j<g.numvex;++j)
        {
            if (!final[j]&&dist[j]<minweight)   
            {
                minweight=dist[j];
                minind=j;
            }
        }
        final[minind]=true;
        for (int j=0;j<g.numvex;++j)
        {
            if (!final[j]&&dist[minind]+g.edges[minind][j]<dist[j])
                dist[j]=dist[minind]+g.edges[minind][j];
        }
    }
}
int main()
{
    std::cin >> g1.numvex >> g1.numedge >> startpoint >> endpoint;
    for (int i = 0; i < g1.numedge; ++i)
    {
        int start, end, weight;
        std::cin >> start >> end >> weight;
        g1.edges[end - 1][start - 1] = g1.edges[start - 1][end - 1] = weight;
    }
    for (int i = 0; i < g1.numvex; ++i)
    {
        if (i == startpoint - 1)
            dist[i] = 0;
        else
            dist[i] = INT32_MAX;
        for (int j = 0; j < g1.numvex; ++j)
        {
            if (i != j && !g1.edges[i][j])
                g1.edges[j][i]=g1.edges[i][j] = INT32_MAX;
        }
    }
    Dijkstra(startpoint-1,g1,dist);
    std::cout << dist[endpoint - 1];
}