//快速幂与取余运算
//11=1011(2) 所以2^11=2^8*2^2*2^1 
//2^1 2^2等等可由自乘获得
// (A+B) mod R=((A mod R) + (B mod R)) mod R
// (A*B) mod R=((A mod R) * (B mod R)) mod R
#include <iostream>
#include <cmath>
int64_t power(int64_t x,int64_t y)
{
    int64_t ans=1;
    while (y>0)
    {
        if (y&1)   //y mod 2==1
        {
            ans*=x;
        }
        x*=x;
        y>>=1;  //y/=2
    }
    return ans;
}
//x^y mod R
int64_t mod(int64_t x,int64_t y,int64_t R)
{
    int64_t ans=1;
    if (y==0) return x%R;
    while (y>0)
    {
        if (y&1)   //y mod 2==1
        {
            ans*=x;
            ans%=R;
        }
        x*=x;
        x%=R;
        y>>=1;  //y/=2
    }
    return ans;
}

int main()
{
    int64_t b,p,k;
    std::cin>>b>>p>>k;
    std::cout<<b<<'^'<<p<<" mod "<<k<<'='<<mod(b,p,k);
}