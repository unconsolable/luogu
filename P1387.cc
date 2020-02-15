/*多测几组样例*/
#include <iostream>
#include <algorithm>
int main()
{
    int n, m, map[105][105], maxans = 1;
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> map[i][j];
        }
    }
    for (int len = 2; len <= std::min(m, n); ++len)
    {
        for (int i = len-1; i < n; ++i)
        {
            for (int j = len-1; j < m; ++j)
            {
                if (map[i][j - 1] >= len-1 && map[i - 1][j] >= len-1 && map[i - 1][j - 1] >= len-1 && map[i][j])
                    map[i][j] = len;
                if (maxans < map[i][j])
                    maxans = map[i][j];
            }
        }
    }
    std::cout << maxans;
}