#include <iostream>
#include <cmath>
long long ans;
int n, k;
long long elem[23];
bool isprime(long long num)
{
    if (num == 1)
        return false;
    bool prime = true;
    for (long long i = 2; i <= sqrt(num); ++i)
        if (!(num % i))
        {
            prime = false;
            break;
        }
    return prime;
}
void choose(int curnum, int choosenum, int currans)
{
    if (choosenum == k)
    {
        if (isprime(currans))
            ++ans;
        return;
    }
    if (curnum >= n)
        return;
    choose(curnum + 1, choosenum + 1, currans + elem[curnum]);
    choose(curnum + 1, choosenum, currans);
}
int main()
{
    std::cin >> n >> k;
    for (int i = 0; i < n; ++i)
        std::cin >> elem[i];
    choose(0, 0, 0);
    std::cout << ans;
}