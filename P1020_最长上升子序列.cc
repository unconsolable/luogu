// n^2: f[j+1]=max{f[1],f[2],...,f[j]}+1
// nlogn:以栈辅助求解 第一个元素入栈
// 循环从第二个元素开始 若循环中当前元素:
// 大于栈顶元素 入栈
// 等于栈顶元素 舍弃
// 小于栈顶元素 替换第一个大于/等于当前元素的元素
// 这样能够降低下限(也许能容更长的子序列) 
// 若不能容更长的子序列也不会影响长度(元素替换回后个数相同)
// upper_bound(第一个大于元素)与lower_bound(第一个大于等于元素)只能用于升序序列
// 传greater变成在降序序列找小于/小于等于元素
#include <iostream>
#include <functional>
#include <iterator>
#include <algorithm>
#define MAXCNT 100000
int cnt, data[MAXCNT];
int assistup[MAXCNT], assistnotup[MAXCNT],topup=0,topnotup=0;
int main()
{
    while (std::cin>>data[cnt])
        cnt++;
    assistup[topup++]=assistnotup[topnotup++]=data[0];
    for (int i=1;i<cnt;++i)
    {
        if (data[i]>assistup[topup-1])
        {
            assistup[topup++]=data[i];
        }
        else
        {
            *std::lower_bound(std::begin(assistup),std::begin(assistup)+topup,data[i])=data[i];
        }
        if (data[i]<=assistnotup[topnotup-1])
        {
            assistnotup[topnotup++]=data[i];
        }
        else
        {
            *std::upper_bound(std::begin(assistnotup),std::begin(assistnotup)+topnotup,data[i],std::greater<int>())=data[i];
        }
    }
    std::cout<<topnotup<<'\n'<<topup<<std::endl;
}