//记忆化搜索
#include <iostream>
#include <queue>
#include <cstring>
struct Node
{
    int x, y;
    Node() = default;
    Node(int x, int y) : x(x), y(y) {}
};
int main()
{
    int16_t map[1000][1000];
    int32_t result[1000][1000];
    memset(result,-1,sizeof(result));
    int32_t n, m;
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            char tmp;
            std::cin >> tmp;
            map[i][j] = tmp - '0';
        }
    }
    std::queue<Node> que;
    for (int i = 0; i < m; ++i)
    {
        int tmpx, tmpy;
        int32_t sum = 0;
        std::cin >> tmpx >> tmpy;
        if (result[tmpx][tmpy]!=-1) 
        {
            std::cout<<result[tmpx][tmpy];
            continue;
        }
        tmpx -= 1;
        tmpy -= 1;
        bool visited[1000][1000], iszero;
        memset(visited, false, sizeof(visited));
        visited[tmpx][tmpy] = true;
        que.push(Node(tmpx, tmpy));
        while (!que.empty())
        {
            auto cur = que.front();
            ++sum;
            que.pop();
            if (map[cur.x][cur.y] == 1)
            {
                iszero = false;
                for (int i = 0; i < 4; ++i)
                {
                    if (cur.x + dx[i] >= 0 && cur.x + dx[i] < n && cur.y + dy[i] >= 0 && cur.y + dy[i] < n && iszero && map[cur.x + dx[i]][cur.y + dy[i]] && !visited[cur.x + dx[i]][cur.y + dy[i]])
                    {
                        visited[cur.x + dx[i]][cur.y + dy[i]] = true;
                        que.push(Node(cur.x + dx[i], cur.y + dy[i]));
                    }
                    if (cur.x + dx[i] >= 0 && cur.x + dx[i] < n && cur.y + dy[i] >= 0 && cur.y + dy[i] < n && !iszero && !map[cur.x + dx[i]][cur.y + dy[i]] && !visited[cur.x + dx[i]][cur.y + dy[i]])
                    {
                        visited[cur.x + dx[i]][cur.y + dy[i]] = true;
                        que.push(Node(cur.x + dx[i], cur.y + dy[i]));
                    }
                }
            }
            else
            {
                iszero = true;
                for (int i = 0; i < 4; ++i)
                {
                    if (cur.x + dx[i] >= 0 && cur.x + dx[i] < n && cur.y + dy[i] >= 0 && cur.y + dy[i] < n && iszero && map[cur.x + dx[i]][cur.y + dy[i]] && !visited[cur.x + dx[i]][cur.y + dy[i]])
                    {
                        visited[cur.x + dx[i]][cur.y + dy[i]] = true;
                        que.push(Node(cur.x + dx[i], cur.y + dy[i]));
                    }
                    if (cur.x + dx[i] >= 0 && cur.x + dx[i] < n && cur.y + dy[i] >= 0 && cur.y + dy[i] < n && !iszero && !map[cur.x + dx[i]][cur.y + dy[i]] && !visited[cur.x + dx[i]][cur.y + dy[i]])
                    {
                        visited[cur.x + dx[i]][cur.y + dy[i]] = true;
                        que.push(Node(cur.x + dx[i], cur.y + dy[i]));
                    }
                }
            }
        }
        result[tmpx][tmpy]=sum;
        std::cout << sum << std::endl;
    }
}