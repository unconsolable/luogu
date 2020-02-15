#include <iostream>
unsigned int edge[200010], visits[200010], times = 1;
int main()
{
    unsigned int cnt;
    std::cin.sync_with_stdio(false);
    std::cout.sync_with_stdio(false);
    std::cin >> cnt;
    for (unsigned int i = 0; i < cnt; ++i)
    {
        std::cin >> edge[i];
        visits[i] = edge[i];
    }
    bool flag = true;
    while (flag)
    {
        ++times;
        for (unsigned int i = 0; i < cnt; ++i)
        {
            visits[i] = edge[visits[i] - 1];
            if (visits[i] == i + 1)
            {
                flag = false;
                break;
            }
        }
    }
    std::cout << times << std::endl;
}