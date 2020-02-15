//连通图的可走方块数相同
//补充输出时注意格式的符合性
//memset不是常数时间
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <iterator>
#include <fstream>
bool visited[1000][1000];
int32_t *result[1000][1000];
struct Node
{
    int x, y;
    Node() = default;
    Node(int x, int y) : x(x), y(y) {}
};
int main()
{
    int16_t map[1000][1000];
    int32_t n, m;
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    std::cin.sync_with_stdio(false);
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
        std::cin >> tmpx >> tmpy;
        tmpx -= 1;
        tmpy -= 1;
        if (result[tmpx][tmpy])
        {
            std::cout << *result[tmpx][tmpy] << std::endl;
            continue;
        }
        bool iszero;
        int32_t *sum = new int32_t();
        visited[tmpx][tmpy] = true;
        result[tmpx][tmpy] = sum;
        que.push(Node(tmpx, tmpy));
        while (!que.empty())
        {
            auto cur = que.front();
            ++*sum;
            que.pop();
            if (map[cur.x][cur.y] == 1)
            {
                iszero = false;
                for (int i = 0; i < 4; ++i)
                {
                    if (cur.x + dx[i] >= 0 && cur.x + dx[i] < n && cur.y + dy[i] >= 0 && cur.y + dy[i] < n && iszero && map[cur.x + dx[i]][cur.y + dy[i]] && !visited[cur.x + dx[i]][cur.y + dy[i]])
                    {
                        visited[cur.x + dx[i]][cur.y + dy[i]] = true;
                        result[cur.x + dx[i]][cur.y + dy[i]] = sum;
                        que.push(Node(cur.x + dx[i], cur.y + dy[i]));
                    }
                    if (cur.x + dx[i] >= 0 && cur.x + dx[i] < n && cur.y + dy[i] >= 0 && cur.y + dy[i] < n && !iszero && !map[cur.x + dx[i]][cur.y + dy[i]] && !visited[cur.x + dx[i]][cur.y + dy[i]])
                    {
                        visited[cur.x + dx[i]][cur.y + dy[i]] = true;
                        result[cur.x + dx[i]][cur.y + dy[i]] = sum;
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
                        result[cur.x + dx[i]][cur.y + dy[i]] = sum;
                        que.push(Node(cur.x + dx[i], cur.y + dy[i]));
                    }
                    if (cur.x + dx[i] >= 0 && cur.x + dx[i] < n && cur.y + dy[i] >= 0 && cur.y + dy[i] < n && !iszero && !map[cur.x + dx[i]][cur.y + dy[i]] && !visited[cur.x + dx[i]][cur.y + dy[i]])
                    {
                        visited[cur.x + dx[i]][cur.y + dy[i]] = true;
                        result[cur.x + dx[i]][cur.y + dy[i]] = sum;
                        que.push(Node(cur.x + dx[i], cur.y + dy[i]));
                    }
                }
            }
        }
        std::cout << *sum << std::endl;
    }
}