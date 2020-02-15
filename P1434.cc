// PKU算法MOOC讲解
#include <iostream>
#include <cstring>
int64_t findans(int r, int c, int (*height)[100], int64_t (*ans)[100], int maxr, int maxc)
{
    if (ans[r][c] > 0)
        return ans[r][c];
    int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
    int maxstep = 0;
    bool isnoanswer = true;
    for (int i = 0; i < 4; ++i)
    {
        if (r + dx[i] >= 0 && r + dx[i] < maxr && c + dy[i] >= 0 && c + dy[i] < maxc && height[r + dx[i]][c + dy[i]] < height[r][c])
        {
            isnoanswer = false;
            break;
        }
    }
    if (isnoanswer)
    {
        ans[r][c] = 1;
        return 1;
    }
    for (int i = 0; i < 4; ++i)
    {
        if (r + dx[i] >= 0 && r + dx[i] < maxr && c + dy[i] >= 0 && c + dy[i] < maxc && height[r + dx[i]][c + dy[i]] < height[r][c])
        {
            int tmpstep = findans(r + dx[i], c + dy[i], height, ans, maxr, maxc) + 1;
            if (tmpstep > maxstep)
                maxstep = tmpstep;
        }
    }
    ans[r][c] = maxstep;
    return maxstep;
}
int main()
{
    int row, column;
    int height[100][100];
    int64_t ans[100][100];
    int64_t result=0;
    memset(ans, -1, sizeof(ans));
    int maxrow = 0, maxcolumn = 0;
    std::cin >> row >> column;
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            std::cin >> height[i][j];
            if (height[i][j] > height[maxrow][maxcolumn])
            {
                maxrow = i;
                maxcolumn = j;
            }
        }
    }
    for (int i=0;i<row;++i)
    {
        for (int j=0;j<column;++j)
        {
            if (ans[i][j]<0)
                findans(i,j,height,ans,row,column);
            if (ans[i][j]>result)
                result=ans[i][j];
        }
    }
    std::cout<<result;
}