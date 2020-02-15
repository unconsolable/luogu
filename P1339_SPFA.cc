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
void SPFA(const int &startp, Graph &g1, long long dist[])
{
    bool visited[MAXVEX] = {};
    std::queue<int> nextspfa;
    nextspfa.push(startp);
    visited[startp] = true;
    while (!nextspfa.empty())
    {
        auto curr = nextspfa.front();
        nextspfa.pop();
        visited[curr]=false;
        //是不在队列中 不是未曾进过队列
        for (int i = 0; i < g1.numvex; ++i)
        {
            if (dist[curr] + g1.edges[curr][i] < dist[i])
            {
                if (!visited[i])
                {
                    visited[i] = true;
                    nextspfa.push(i);
                }
                dist[i] = dist[curr] + g1.edges[curr][i];
            }
        }
    }
}
int startpoint, endpoint;
long long dist[MAXVEX];
Graph g1;
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
    SPFA(startpoint - 1, g1, dist);
    std::cout << dist[endpoint - 1];
}
