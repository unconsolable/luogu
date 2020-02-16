#include <iostream>
#include <cstring>
struct Edge
{
    int end = 0;
    int weight = -1;
    Edge *next = nullptr;
    Edge() = default;
    Edge(int e, int w) : end(e), weight(w) {}
    ~Edge()
    {
        if (next)
        {
            delete next;
            next = nullptr;
        }
    }
};
struct Vertex
{
    Edge *first = nullptr;
    ~Vertex()
    {
        if (first)
        {
            delete first;
            first = nullptr;
        }
    }
};
struct Graph
{
    Vertex vexs[105];
    int numvex;
};
Graph g1;
int start, end;
int main()
{
    std::cin >> g1.numvex >> start >> end;
    --start;
    --end;
    for (int i = 0; i < g1.numvex; ++i)
    {
        int edgecnt, endpos;
        bool isfirst = true;
        std::cin >> edgecnt;
        for (int j = 0; j < edgecnt; ++j)
        {
            std::cin >> endpos;
            auto tmp = new Edge(endpos - 1, (isfirst) ? 0 : 1);
            if (isfirst)
                isfirst = false;
            tmp->next = g1.vexs[i].first;
            g1.vexs[i].first = tmp;
        }
    }
    bool final[105] = {};
    int result[105];
    memset(result, -1, sizeof(result));
    result[start] = 0;
    final[start] = true;
    for (auto i = g1.vexs[start].first; i; i = i->next)
    {
        result[i->end] = i->weight;
    }
    for (int i = 1; i < g1.numvex; ++i)
    {
        int min = 200, minpos = -1;
        for (int j = 0; j < g1.numvex; ++j)
        {
            if (!final[j] && result[j] != -1 && min > result[j])
            {
                min = result[j];
                minpos = j;
            }
        }
        final[minpos] = true;
        for (auto j = g1.vexs[minpos].first; j; j = j->next)
        {
            if (!final[j->end])
            {
                if (result[j->end] == -1)
                {
                    result[j->end] = result[minpos] + j->weight;
                }
                else
                {
                    result[j->end] = std::min(result[j->end], result[minpos] + j->weight);
                }
            }
        }
    }
    std::cout << result[end];
}