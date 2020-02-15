// 注意数据范围
// 对整个问题设最优值 枚举合并点
// 将问题分解为左右两个部分 最后合并两个部分的最优值得到原问题的最优值
// 参考:https://oi-wiki.org/dp/interval/
#include <iostream>
#include <algorithm>
int main()
{
    long long n, data[220]{0}, ansmax[220][220]{0}, sum[220]{0}, ansmin[220][220]{0};
    long long finalansmax, finalansmin;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> data[i];
        data[n + i] = data[i];
        if (i)
            sum[i] = sum[i - 1] + data[i];
        else
            sum[i] = data[i];
    }
    for (int i = n; i < 2 * n; ++i)
        sum[i] = sum[i - 1] + data[i - n];
    //先枚举len(类似合并过程:先合并最小规模 再逐渐扩大)
    for (int len = 1; len < n; ++len)
    {
        for (int start = 0; start < 2 * n - len; ++start)
        {
            int end = start + len;
            for (int breakp = start; breakp < end; ++breakp)
            {
                ansmax[start][end] = std::max(ansmax[start][end], ansmax[start][breakp] + ansmax[breakp + 1][end] + sum[end] - sum[start] + data[start]);
                if (!ansmin[start][end])
                    ansmin[start][end] = ansmin[start][breakp] + ansmin[breakp + 1][end] + sum[end] - sum[start] + data[start];
                else
                {
                    //在所有的断点分割中选择最小方案
                    //比如:0-2共3堆石子合并 可先合并1 2(上一步求出) 再合并0 或先合并0 1(上一步求出) 再合并2
                    ansmin[start][end] = std::min(ansmin[start][end], ansmin[start][breakp] + ansmin[breakp + 1][end] + sum[end] - sum[start] + data[start]);
                }
            }
        }
    }
    finalansmax=ansmax[0][n-1];finalansmin=ansmin[0][n-1];
    for (int i=1;i<n;++i)
    {
        if (ansmax[i][i+n-1]>finalansmax) finalansmax=ansmax[i][i+n-1];
        if (ansmin[i][i+n-1]<finalansmin) finalansmin=ansmin[i][i+n-1];
    }
    std::cout<<finalansmin<<'\n'<<finalansmax<<std::endl;
}