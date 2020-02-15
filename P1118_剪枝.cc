#include <iostream>
#include <cstring>
bool dfs(int calcsum,int calccnt,int targetsum,int targetcnt,int visited[],int (*yanghui)[14])
{
    if (calccnt==targetcnt&&calcsum==targetsum) return true;
    //最优性剪枝
    if (calccnt<targetcnt&&calcsum>=targetsum) return false;
    for (int i=1;i<=targetcnt;++i)
    {
        if (!visited[i])
        {
            visited[i]=calccnt+1;
            calcsum+=i*yanghui[targetcnt][calccnt+1];
            if (dfs(calcsum,calccnt+1,targetsum,targetcnt,visited,yanghui))
            {
                return true;
            }
            visited[i]=0;
            calcsum-=i*yanghui[targetcnt][calccnt+1];
        }
    }
    return false;
}
int main()
{
    int yanghui[14][14],n,sum,visited[14];
    int calcsum=0,calccnt=0;
    memset(yanghui,0,sizeof(yanghui));
    memset(visited,0,sizeof(visited));
    std::cin>>n>>sum;
    yanghui[1][1]=1;
    for (int i=2;i<=n;++i)
    {
        for (int j=1;j<=i;++j)
        {
            if (j==1||j==i)
                yanghui[i][j]=1;
            else
                yanghui[i][j]=yanghui[i-1][j-1]+yanghui[i-1][j];
        }
    }
    dfs(calcsum,calccnt,sum,n,visited,yanghui);
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=n;++j)
            if (visited[j]==i)
            {
                std::cout<<j<<' ';
                break;
            }
    }
    std::cout<<std::endl;
}