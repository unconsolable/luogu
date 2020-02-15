#include <iostream>
#include <algorithm>
struct Node
{
    int posx;
    int posy;
    long cnt;
};
int main()
{
    int M, N, K, totNode = 0, tmp;
    Node nodes[400];
    std::cin.sync_with_stdio(false);
    std::cin >> M >> N >> K;
    K -= 2;
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            std::cin >> tmp;
            if (tmp)
            {
                nodes[totNode].posx = i;
                nodes[totNode].posy = j;
                nodes[totNode++].cnt = tmp;
            }
        }
    }
    auto SortRule = [](Node &n1, Node &n2) -> bool {
        return n1.cnt > n2.cnt;
    };
    std::sort(nodes, nodes + totNode, SortRule);
    int curx = 0, cury = nodes[0].posy,curNode = 0;
    long sum = 0;
    while (K > 0)
    {
        int needx = abs(nodes[curNode].posx - curx);
        int needy = abs(nodes[curNode].posy - cury);
        int goback_now=curx;
        int goback_next=nodes[curNode].posx;
        if (K >= needx + needy + 1 + goback_next)
        {
            //时间够跳 采 回
            K -= needx + needy + 1;
            sum += nodes[curNode].cnt;
            curx = nodes[curNode].posx;
            cury = nodes[curNode++].posy;
        }
        else
        {
            K-=goback_now;
            break;
        }
        if (curNode==totNode) break;
    }
    std::cout << sum;
    return 0;
}