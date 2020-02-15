#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXSIZE 100
// bool inSample(char* sample,char c)
// {
//     for (int i=0;i<strlen(sample);++i)
//     {
//         if (c==sample[i]) return true;
//     }
//     return false;
// }

//0未知 1向右 2向下 3向左 4向上 5右上 6右下 7左下 8左上
bool dfs(int direction,unsigned currIndex,int currRow,int currColumn,int totalMap,char (*map)[MAXSIZE],char sample[],int (*ans)[MAXSIZE])
{
    if (currRow<0||currRow>=totalMap||currColumn<0||currColumn>=totalMap) return false;
    if (direction==0)
    {
        ans[currRow][currColumn]=1;
        bool try1=dfs(1,currIndex+1,currRow,currColumn+1,totalMap,map,sample,ans);
        bool try2=dfs(2,currIndex+1,currRow+1,currColumn,totalMap,map,sample,ans);
        bool try3=dfs(3,currIndex+1,currRow,currColumn-1,totalMap,map,sample,ans);
        bool try4=dfs(4,currIndex+1,currRow-1,currColumn,totalMap,map,sample,ans);
        bool try5=dfs(5,currIndex+1,currRow-1,currColumn+1,totalMap,map,sample,ans);
        bool try6=dfs(6,currIndex+1,currRow+1,currColumn+1,totalMap,map,sample,ans);
        bool try7=dfs(7,currIndex+1,currRow+1,currColumn-1,totalMap,map,sample,ans);
        bool try8=dfs(8,currIndex+1,currRow-1,currColumn-1,totalMap,map,sample,ans);
        if (!try1&&!try2&&!try3&&!try4&&!try5&&!try6&&!try7&&!try8)
        {
            ans[currRow][currColumn]=0; //只第一个字符匹配
        }
    }
    if (sample[currIndex]==map[currRow][currColumn])
    {
        bool res=false,hasused;
        if (ans[currRow][currColumn]==1) hasused=true; else hasused=false;
        ans[currRow][currColumn]=1;
        if (currIndex==strlen(sample)-1) return true;
        switch (direction)
        {
        case 1:
            res=dfs(1,currIndex+1,currRow,currColumn+1,totalMap,map,sample,ans);
            break;
        case 2:
            res=dfs(2,currIndex+1,currRow+1,currColumn,totalMap,map,sample,ans);
            break;
        case 3:
            res=dfs(3,currIndex+1,currRow,currColumn-1,totalMap,map,sample,ans);;
            break;
        case 4:
            res=dfs(4,currIndex+1,currRow-1,currColumn,totalMap,map,sample,ans);
            break;
        case 5:
            res=dfs(5,currIndex+1,currRow-1,currColumn+1,totalMap,map,sample,ans);
            break;
        case 6:
            res=dfs(6,currIndex+1,currRow+1,currColumn+1,totalMap,map,sample,ans);;
            break;
        case 7:
            res=dfs(7,currIndex+1,currRow+1,currColumn-1,totalMap,map,sample,ans);
            break;
        case 8:
            res=dfs(8,currIndex+1,currRow-1,currColumn-1,totalMap,map,sample,ans);
            break;
        default:
            break;
        }
        if (!hasused&&!res)
            ans[currRow][currColumn]=0;
        return res;
    }
    else
    {
        return false;
    }
}
int main()
{
    char sample[]="yizhong",map[MAXSIZE][MAXSIZE];
    int ans[MAXSIZE][MAXSIZE]={};
    int n;
    std::cin.sync_with_stdio(false);
    std::cin>>n;
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<n;++j)
        {
            std::cin>>map[i][j];
            if (map[i][j]==sample[0])
            {
                ans[i][j]=-1;
            }
        }
    }
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<n;++j)
        {
            if (ans[i][j]==-1)
            {
                dfs(0,0,i,j,n,map,sample,ans);        
            }
        }
    }
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<n;++j)
            if (ans[i][j]) 
                std::cout<<map[i][j];
            else
                std::cout<<'*';
        std::cout<<std::endl;
    }

}