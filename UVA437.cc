#include <iostream>
#include <cstring>
#include <queue>
#define INF 2147483647
struct block
{
    long xi,yi,zi;
};
int main()
{
    int blockcnt,casecnt=0;
    while (std::cin>>blockcnt&&blockcnt)
    {
        block blocks[99];
        //xi yi为底且xi<yi
        bool edge[99][99]={};
        bool visited[99]={};
        long min0=0;
        long ans[99]={0},maxans=-1;
        for (int i=0;i<blockcnt;++i)
        {
            std::cin>>blocks[i].xi>>blocks[i].yi>>blocks[i].zi;
            if (blocks[i].xi>blocks[i].yi) std::swap(blocks[i].xi,blocks[i].yi);
            blocks[blockcnt+i].xi=blocks[i].yi;
            blocks[blockcnt+i].yi=blocks[i].zi;
            blocks[blockcnt+i].zi=blocks[i].xi;
            if (blocks[blockcnt+i].xi>blocks[blockcnt+i].yi) std::swap(blocks[blockcnt+i].xi,blocks[blockcnt+i].yi);
            blocks[2*blockcnt+i].xi=blocks[i].zi;
            blocks[2*blockcnt+i].yi=blocks[i].xi;
            blocks[2*blockcnt+i].zi=blocks[i].yi;
            if (blocks[2*blockcnt+i].xi>blocks[2*blockcnt+i].yi) std::swap(blocks[2*blockcnt+i].xi,blocks[2*blockcnt+i].yi);
            if (blocks[i].xi<blocks[min0].xi&&blocks[i].yi<blocks[min0].yi) min0=i;
            if (blocks[blockcnt+i].xi<blocks[min0].xi&&blocks[blockcnt+i].yi<blocks[min0].yi) min0=blockcnt+i;
            if (blocks[2*blockcnt+i].xi<blocks[min0].xi&&blocks[2*blockcnt+i].yi<blocks[min0].yi) min0=2*blockcnt+i;
        }
        for (int i=0;i<3*blockcnt;++i)
        {
            for (int j=0;j<3*blockcnt;++j)
            {
                if (blocks[i].xi<blocks[j].xi&&blocks[i].yi<blocks[j].yi) edge[i][j]=true;
            }
        }
        std::queue<int> next;
        next.push(min0);
        visited[min0]=true;
        ans[min0]=blocks[min0].zi;
        while (!next.empty())
        {
            auto curr=next.front();
            next.pop();
            visited[curr]=false;
            for (int j=0;j<3*blockcnt;++j)
            {
                if (edge[curr][j]&&ans[curr]+blocks[j].zi>ans[j])
                {
                    if (!visited[j])
                    {
                        visited[j]=true;
                        next.push(j);
                    }
                    ans[j]=ans[curr]+blocks[j].zi;
                    if (ans[j]>maxans) maxans=ans[j];
                }
            }
        }
        std::cout<<"Case "<<++casecnt<<": maximum height = "<<maxans<<std::endl;
    }
}