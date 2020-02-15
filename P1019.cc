/*有包含不能用
重叠部分取最小
包含关系不等价于完全一致*/
#include <iostream>
#include <string>
#include <cstring>
struct Graph
{
    std::string data[20];
    int arc[20][20] = {};
    int numVertexes = 0;
};
inline int isArcAble(std::string s1, std::string s2)
{
    int res = 0;
    bool writeProtect = false;
    for (int i = s1.size() - 1; i >= 0; --i)
    {
        bool can = true;
        unsigned j;
        for (j = 0; j < s1.size() - i; ++j)
        {
            if (s1[i + j] != s2[j])
                can = false;
            if (j == s2.size() - 1 && can)
            {
                can = false;
                return 0;
            }
        }
        if (i == 0 && can)
        {
            can = false;
            return 0;
        }
        if (can && !writeProtect)
        {
            writeProtect = true;
            res = j;
            return res;
        }
    }
    return res;
}
void findarc(Graph *g, int index)
{
    for (int i = 0; i <= index; ++i)
    {
        g->arc[i][index] = isArcAble(g->data[i], g->data[index]);
        g->arc[index][i] = isArcAble(g->data[index], g->data[i]);
    }
}
int dfs(Graph g1, int visited[], int curr)
{
    int ans = g1.data[curr].size(); 
    for (int i = 0; i < g1.numVertexes; ++i)
    {
        int tmplen;
        if (g1.arc[curr][i] && visited[i] < 2)
        {
            ++visited[i];
            tmplen = g1.data[curr].size() + dfs(g1, visited, i) - g1.arc[curr][i];
            --visited[i];
        }
        if (tmplen > ans)
            ans = tmplen;
    }
    return ans;
}
int main()
{
    Graph g1;
    std::cin >> g1.numVertexes;
    for (int i = 0; i < g1.numVertexes; ++i)
    {
        std::cin >> g1.data[i];
        findarc(&g1, i);
    }
    char start;
    int result = 0;
    int visited[20]={};

    std::cin >> start;
    for (int i = 0; i < g1.numVertexes; ++i)
    {
        if (g1.data[i][0] == start)
        {
            ++visited[i];
            int tmp = dfs(g1, visited, i);
            --visited[i];
            if (tmp > result)
                result = tmp;
        }
    }
    std::cout << result;
}