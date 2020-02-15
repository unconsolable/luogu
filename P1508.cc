#include <iostream>
#include <algorithm>
int main()
{
    int map[210][210], m, n;
    int way1 = -99999, way2 = -99999, way3 = -99999;
    std::cin >> m >> n;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            std::cin >> map[i][j];
    for (int i = 1; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (j - 1 >= 0)
            {
                way1 = map[i][j] + map[i - 1][j - 1];
            }
            if (j + 1 < n)
            {
                way3 = std::max(way1, map[i][j] + map[i - 1][j + 1]);
            }
            way2 = std::max(way3, map[i][j] + map[i - 1][j]);
            map[i][j] = way2;
        }
    }
    way1=map[m-1][n/2-1];
    way2=std::max(way1,map[m-1][n/2]);
    way3=std::max(way2,map[m-1][n/2+1]);
    std::cout<<way3<<std::endl;
}
