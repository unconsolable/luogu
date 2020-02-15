#include <iostream>
#include <algorithm>
int main()
{
    int n;
    std::cin>>n;
    int queue[n];
    for (int i=0;i<n;++i)
        std::cin>>queue[i];
    // 以下计算最大不连续字段和
    // for (int i=n-2;i>=0;--i)
    // {
    //     int max=queue[i]+queue[i+1];
    //     for (int j=i;j<n;++j)
    //     {
    //         if (queue[j]>max)
    //             max=queue[j];
    //     }
    //     queue[i]=max;
    // }
    bool isLink=true;
    for (int i=n-2;i>=0;--i)
    {
        int maxsum;
        if (isLink)
        {
            maxsum=std::max(queue[i]+queue[i+1],queue[i]);
        }
        else
        {
            maxsum=queue[i];
        }
        for (int j=i+1;j<n;++j)
        {
            //如果不连续能有更大和选不连续
            if (queue[j] > maxsum)
            {
                maxsum = queue[j];
                isLink = false;
            }
        }
    }
    std::cout<<queue[0];
}