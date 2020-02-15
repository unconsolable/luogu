//从第一张牌向后推
//贪心
#include <iostream>
#define MAXCNT 100
int dfs(int curr,int card[],int target,int n)
{
    if (curr==n-1) return 0;
    if (card[curr]==target) 
        return dfs(curr+1,card,target,n);
    else
    {
        card[curr+1]+=card[curr]-target;
        card[curr]=target;
        return 1+dfs(curr+1,card,target,n);
    }
}
int main()
{
    int n,card[MAXCNT];
    int64_t total;
    std::cin>>n;
    for (int i=0;i<n;++i)
    {
        std::cin>>card[i];
        total+=card[i];
    }
    total/=n;
    int ans=dfs(0,card,total,n);
    std::cout<<ans;
}