#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    size_t n,t;cin>>n;
    double a;
    //看清数据范围 特别是水题
    bool light[2000000];
    memset(light,0,sizeof(light));//0表关 1表开
    for (size_t i=1;i<=n;++i)
    {
        cin>>a>>t;
        for (size_t j=1;j<=t;++j)
        {
            light[static_cast<size_t>(a*j)]=!light[static_cast<size_t>(a*j)];
        }
    }
    for (size_t i=1;i<=2000000;++i)
    {
        if (light[i])
        {
            cout<<i;
            break;
        }
    }
}