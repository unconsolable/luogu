#include <iostream>
#define MAX_TIME 45
using namespace std;
int main()
{
    long long sum=0;
    int n;cin>>n;
    long price_sub[n],time_sub[n],totsub=0;
    //无效用-1表示
    for (int i=1;i<=n;++i)
    {
        int type;long time,price;
        cin>>type>>price>>time;
        if (!type)
        {
            //坐地铁
            //得优惠 有效45min 免费坐不超过票价的公交
            sum+=price;
            price_sub[totsub]=price;
            time_sub[totsub++]=time;
        }
        else
        {
            bool useticket=0;//假设无票用
            //坐公交 优先用时间早的票
            for (int i=0;i<totsub;++i)
            {
                if (time-time_sub[i]>MAX_TIME)
                {
                    //invaild time
                    price_sub[i]=time_sub[i]=-1;
                }
                else
                {
                    //vaild time
                    if (price>price_sub[i])
                    {
                        //invaild price
                        //但后续可能会有可用优惠劵
                        continue;
                    }
                    else
                    {
                        //vaild price
                        useticket=1;
                        //优惠劵作废
                        price_sub[i]=time_sub[i]=-1;
                        //停止搜索
                        break;
                    }
                }
            }
            if (!useticket)
                sum+=price;
        }
    }
    cout<<sum;
}