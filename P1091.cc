// 计算每个点作为最高所能形成的队形的最大值
#include <iostream>
int main()
{
    int n,data[100],lis[100],lds[100];
    std::cin>>n;
    for (int i=0;i<n;++i)
        std::cin>>data[i];
    lis[0]=lds[n-1]=1;
    for (int i=1;i<n;++i)
    {
        int tmpmaxlen=0;
        for (int j=0;j<i;++j)
        {
            if (data[j]<data[i]&&lis[j]>tmpmaxlen)
                tmpmaxlen=lis[j];
        }
        lis[i]=tmpmaxlen+1;
    }
    for (int i=n-2;i>=0;--i)
    {
        int tmpmaxlen=0;
        for (int j=n-1;j>i;--j)
        {
            if (data[i]>data[j]&&lds[j]>tmpmaxlen)
                tmpmaxlen=lds[j];
        }
        lds[i]=tmpmaxlen+1;
    }
    int maxans=lis[0]+lds[0]-1;
    for (int i=1;i<n;++i)
    {
        if (lis[i]+lds[i]-1>maxans)
            maxans=lis[i]+lds[i]-1;
    }
    std::cout<<n-maxans;
}