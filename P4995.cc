#include <iostream>
long long ans;
int hig[305];
int absdelta[305];
int main()
{
    int chosen = 0;
    bool ischosed[305]{};
    int maxdeltaindex = 0;
    int previous = 0;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> hig[i];
        absdelta[i] = hig[i] * hig[i];
        if (absdelta[i] > absdelta[maxdeltaindex])
            maxdeltaindex = i;
    }
    do
    {
        ans += absdelta[maxdeltaindex];
        ischosed[maxdeltaindex] = true;
        ++chosen;
        previous = maxdeltaindex;
        maxdeltaindex = -1;
        for (int i = 0; i < n; ++i)
        {
            if (!ischosed[i])
            {
                absdelta[i] = (hig[i] - hig[previous]) * (hig[i] - hig[previous]);
                if (maxdeltaindex < 0)
                    maxdeltaindex = i;
                else if (absdelta[i] > absdelta[maxdeltaindex])
                    maxdeltaindex = i;
            }
        }
    } while (chosen < n);
    std::cout << ans << std::endl;
}