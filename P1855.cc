#include <iostream>
int main()
{
    int wishCnt,wishMoney[120],wishTime[120],ans[220][220]={};
    int totTime,totMoney;
    std::cin>>wishCnt>>totMoney>>totTime;
    for (int i=0;i<wishCnt;++i)
    {
        std::cin>>wishMoney[i]>>wishTime[i];
    }
    for (int i=0;i<wishCnt;++i)
    {
        for (int time=totTime;time>=wishTime[i];--time)
        {
            for (int money=totMoney;money>=wishMoney[i];--money)
            {
                ans[time][money]=std::max(ans[time][money],ans[time-wishTime[i]][money-wishMoney[i]]+1);
            }
        }
    }
    std::cout<<ans[totTime][totMoney];
}