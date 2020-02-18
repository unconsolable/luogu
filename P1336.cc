#include <iostream>
#include <cmath>
int main()
{
    unsigned long long nedtme[205];
    unsigned int ai[25],bi[25],n,m;
    std::cin.sync_with_stdio(false);
    std::cout.sync_with_stdio(false);
    std::cin>>n>>m;
    for (unsigned int i=0;i<m;++i)
    {
        std::cin>>ai[i]>>bi[i];
    }
    nedtme[0]=0;
    for (unsigned int i=1;i<=n;++i)
    {
        nedtme[i]=ai[0]*static_cast<unsigned long long>(pow(i,bi[0]));
    }
    for (unsigned int curtype=1;curtype<m;++curtype)
    {
        for (unsigned int total=n;total>0;--total)
        {
            for (unsigned int chgcnt=1;chgcnt<=total;++chgcnt)
            {
                nedtme[total]=std::min(nedtme[total],nedtme[total-chgcnt]+ai[curtype]*static_cast<unsigned long long>(pow(chgcnt,bi[curtype])));
            }
        }
    }
    std::cout<<nedtme[n];
}