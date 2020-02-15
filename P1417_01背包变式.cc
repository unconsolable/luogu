// 01背包变化
// 因为价值与选取时间t有关 所以应考虑选取顺序
// 现在考虑相邻的两个物品x,y。假设现在已经耗费p的时间，那么分别列出先做x,y的代价：
// a[x]-(p+c[x])*b[x]+a[y]-(p+c[x]+c[y])*b[y] (1) 
// a[y]-(p+c[y])*b[y]+a[x]-(p+c[y]+c[x])*b[x] (2) 
// 对这两个式子化简，得到1＞2的条件是c[x]*b[y]<c[y]*b[x].
// 参考:https://www.luogu.com.cn/problemnew/solution/P1417
#include <iostream>
#include <algorithm>
struct Node
{
    long long a,b,c;
};
long long tottime, cnt;
Node item[60];
long long ans[100010] = {}, maxans = 0;
bool visited[100010] = {};
int main()
{
    std::cin.sync_with_stdio(false);
    std::cout.sync_with_stdio(false);
    std::cin>>tottime>>cnt;
    for (int i=0;i<cnt;++i)
    {
        std::cin>>item[i].a;
    }
    for (int i=0;i<cnt;++i)
    {
        std::cin>>item[i].b;
    }
    for (int i=0;i<cnt;++i)
    {
        std::cin>>item[i].c;
    }
    auto Rule=[](Node &lhs,Node &rhs)
    {
        return lhs.c*rhs.b<rhs.c*lhs.b;
    };
    std::sort(item,item+cnt,Rule);
    for (int i=0;i<cnt;++i)
    {
        for (long long j=tottime;j>=item[i].c;--j)
        {
            if (!visited[j])
            {
                visited[j]=true;
                ans[j]=ans[j-item[i].c]+item[i].a-j*item[i].b;
            }
            else
            {
                ans[j]=std::max(ans[j],ans[j-item[i].c]+item[i].a-j*item[i].b);
            }
            if (ans[j]>maxans)
                maxans=ans[j];
        }
    }
    std::cout<<maxans;
}