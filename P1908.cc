/*应读到正数但结果返回负数 应换范围更大类型*/
#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
#define MAXCNT 500000
inline long long read()
{
    long long x = 0, f = 1;
    char ch;
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return f * x;
}
void Merge(long long *value, long long start, long long middle, long long end, long long *tmp);
long long MergeSortAndCount(long long *value, long long start, long long end, long long *tmp)
{
    if (start + 1 == end)
        return 0;
    long long middle = (start + end) / 2;
    long long i = MergeSortAndCount(value, start, middle, tmp);
    long long j = MergeSortAndCount(value, middle, end, tmp);

    long long ptra = start, ptrb = middle, sum = i + j;
    while (ptra < middle && ptrb < end)
    {
        if (value[ptra] <= value[ptrb])
            ptrb++;
        if (value[ptra] > value[ptrb])
        {
            sum += end - ptrb;
            ptra++;
        }
    }

    Merge(value, start, middle, end, tmp);
    return sum;
}
void Merge(long long *value, long long start, long long middle, long long end, long long *tmp)
{
    long long ptra = start, ptrb = middle, ptrc = 0;
    while (ptra < middle && ptrb < end)
    {
        if (value[ptra] > value[ptrb])
            tmp[ptrc++] = value[ptra++];
        else
            tmp[ptrc++] = value[ptrb++];
    }
    while (ptra < middle)
        tmp[ptrc++] = value[ptra++];
    while (ptrb < middle)
        tmp[ptrc++] = value[ptrb++];
    for (long long i = 0; i < ptrc; ++i)
        value[start + i] = tmp[i];
}
int main()
{
    long long value[MAXCNT], n, tmp[MAXCNT];
    //std::cin >> n;
    n=read();
    for (long long i = 0; i < n; ++i)
        //std::cin >> value[i];
        value[i]=read();
    long long ans = MergeSortAndCount(value, 0, n, tmp);
    //std::cout << ans << std::endl;
    printf("%lld",ans);
}