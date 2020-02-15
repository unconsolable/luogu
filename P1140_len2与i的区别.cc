#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
int rule[5][5] = { {-32766, -3, -4, -2, -1},
                  {-3, 5, -1, -2, -1},
                  {-4, -1, 5, -3, -2},
                  {-2, -2, -3, 5, -2},
                  {-1, -1, -2, -2, 5} };
int ans[210][210];
inline int transindex(char c)
{
    switch (c)
    {
    case '-':
        return 0;
        break;
    case 'A':
        return 1;
        break;
    case 'C':
        return 2;
        break;
    case 'G':
        return 3;
        break;
    case 'T':
        return 4;
        break;
    default:
        return -1;
        break;
    }
}
int main()
{
    int len1, len2, tmpl = 0;
    char gene1[120], gene2[120], tmpg[120] = {};
    scanf("%d %s\n", &len1, gene1 + 1);
    scanf("%d %s\n", &len2, gene2 + 1);
    // std::cin>>len1>>(gene1+1);
    // std::cin>>len2>>(gene2+1);
    if (len1 < len2)
    {
        strcpy(tmpg, gene1);
        strcpy(gene1, gene2);
        strcpy(gene2, tmpg);
        tmpl = len1;
        len1 = len2;
        len2 = tmpl;
    }
    ans[0][0] = 0;
    for (int i = 1; i <= len1; ++i)
    {
        if (i <= len1)
        {
            ans[i][0] = ans[i - 1][0] + rule[transindex(gene1[i])][0];
        }
        else
        {
            ans[i][0] = ans[i - 1][0] + rule[0][0];
        }
        if (i <= len2)
        {
            ans[0][i] = ans[0][i - 1] + rule[0][transindex(gene2[i])];
        }
        else
        {
            ans[0][i] = ans[0][i - 1] + rule[0][0];
        }
    }
    for (int i = 1; i <= len1; ++i)
    {
        // 这里写成len2 而不是i
        for (int j = 1; j <= len2; ++j)
        {
            int way1 = rule[transindex(gene1[i])][transindex(gene2[j])] + ans[i - 1][j - 1];
            int way2 = std::max(way1, rule[0][transindex(gene2[j])] + ans[i][j - 1]);
            int way3 = std::max(way2, rule[transindex(gene1[i])][0] + ans[i - 1][j]);
            ans[i][j] = way3;
        }
    }
    //std::cout<<ans[len1][len2]<<std::endl;
    printf("%d\n", ans[len1][len2]);
}