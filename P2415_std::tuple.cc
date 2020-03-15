#include <iostream>
#include <tuple>
#include <cmath>
int sets[35];
// 第一位表结果 第二位表子集个数
std::tuple<long long,long long> solution(int sets[],int i,int j)
{
    if (i+1==j)
    {
        return std::make_tuple(sets[i],2);
    }
    int middle=(i+j)/2;
    auto left=solution(sets,i,middle);
    auto right=solution(sets,middle,j);
    return std::make_tuple(std::get<0>(left)*std::get<1>(right)+std::get<1>(left)*std::get<0>(right),std::get<1>(left)*std::get<1>(right));
}
int main()
{
    unsigned int cnt=0;
    while (std::cin>>sets[cnt])
        ++cnt;
    auto ans=solution(sets,0,cnt);
    std::cout<<std::get<0>(ans)<<std::endl;
}