#include <iostream>
#include <queue>
#define MAXVEX 10000
struct Vertex
{
    int node;
    Vertex *next;
    Vertex() = default;
    Vertex(const int &n) : node(n) {}
    ~Vertex()
    {
        if (next)
        {
            delete next;
            next = nullptr;
        }
    }
};
struct FirstVertex
{
    int indegree;
    int weight;
    Vertex *first;
    ~FirstVertex()
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
    FirstVertex vexs[MAXVEX + 5];
    int vexnum;
    ~Graph()
    {
        for (int i = 0; i < vexnum; ++i)
        {
            if (vexs[i].first)
            {
                delete vexs[i].first;
                vexs[i].first = nullptr;
            }
        }
    }
};
Graph g1;
unsigned int etv[MAXVEX + 5], maxtime;
void create()
{
    std::cin >> g1.vexnum;
    for (int i = 0; i < g1.vexnum; ++i)
    {
        int nodeindex;
        std::cin >> nodeindex;
        --nodeindex;
        std::cin >> g1.vexs[nodeindex].weight;
        int temp;
        while (std::cin >> temp && temp)
        {
            --temp;
            ++g1.vexs[nodeindex].indegree;
            auto newedge = new Vertex(nodeindex);
            newedge->next = g1.vexs[temp].first;
            g1.vexs[temp].first = newedge;
        }
    }
}

void trosort()
{
    std::queue<int> next;
    for (int i = 0; i < g1.vexnum; ++i)
    {
        if (!g1.vexs[i].indegree)
        {
            next.push(i);
            etv[i] = g1.vexs[i].weight;
            break;
        }
    }
    while (!next.empty())
    {
        int curr = next.front();
        next.pop();
        auto curedge = g1.vexs[curr].first;
        while (curedge)
        {
            // 从所依赖的时间中选最大值+做这项任务所需时间
            etv[curedge->node] = std::max(etv[curedge->node], etv[curr] + g1.vexs[curedge->node].weight);
            if (maxtime < etv[curedge->node])
                maxtime = etv[curedge->node];
            if (!(--g1.vexs[curedge->node].indegree))
            {
                next.push(curedge->node);
            }
            curedge = curedge->next;
        }
    }
}

int main()
{
    std::cin.sync_with_stdio(false);
    std::cout.sync_with_stdio(false);
    create();
    trosort();
    std::cout << maxtime << '\n';
}