#include <iostream>
#include <queue>
struct curstep
{
    curstep(int x = 0, int y = 0) : where(x), totstep(y) {}
    int where;
    int totstep;
};
int main()
{
    int n, a, b;
    int k[210];
    bool visited[210]{};
    std::cin >> n >> a >> b;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> k[i];
    }
    std::queue<curstep> solist;
    solist.push(std::move(curstep(a, 0)));
    visited[a]=true;
    while (!solist.empty())
    {
        auto cur = solist.front();
        solist.pop();
        if (cur.where == b)
        {
            std::cout << cur.totstep << '\n';
            exit(0);
        }
        if (!visited[cur.where + k[cur.where]] && cur.where + k[cur.where] <= n)
        {
            visited[cur.where + k[cur.where]] = true;
            solist.emplace(cur.where + k[cur.where], cur.totstep + 1);
        }
        if (!visited[cur.where - k[cur.where]] && cur.where - k[cur.where] > 0)
        {
            visited[cur.where - k[cur.where]] = true;
            solist.emplace(cur.where - k[cur.where], cur.totstep + 1);
        }
    }
    std::cout<<"-1\n";
}