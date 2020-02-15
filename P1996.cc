#include <iostream>
#include <algorithm>
int main()
{
    int m,n;
    std::cin>>n>>m;
    int queue[n],cnt=0,curr=-1;
    for (int i=0;i<n;++i)
        queue[i]=i+1;
    while (cnt<n)
    {
        for (int i=0;i<m;++i)
        {
            ++curr;
            if (curr==n) curr=0;
            while (!queue[curr])
            {
                ++curr;
                if (curr==n) curr=0;
            }
        }
        std::cout<<queue[curr]<<' ';
        queue[curr]=0;
        cnt++;
    }
}