#include <iostream>
#include <cstring>
#include <queue>
#include <iomanip>
#define MAXN 400
struct Node
{
    int x=0,y=0,step=0;
    Node()=default;
    Node(int x,int y,int s):x(x),y(y),step(s){}
};
int main()
{
    int map[MAXN][MAXN],startx,starty,totx,toty;
    bool visited[MAXN][MAXN];
    memset(map,-1,sizeof(map));memset(visited,false,sizeof(visited));
    std::cin.sync_with_stdio(false);std::cout.sync_with_stdio(false);
    std::cin>>totx>>toty>>startx>>starty;
    startx-=1;starty-=1;
    std::queue<Node> que;
    que.push(Node(startx,starty,0));
    int dx[]={2,2,-2,-2,1,1,-1,-1};
    int dy[]={1,-1,1,-1,2,-2,2,-2};
    while (!que.empty())
    {
        Node cur=que.front();
        que.pop();
        map[cur.x][cur.y]=cur.step;visited[cur.x][cur.y]=true;
        for (int way=0;way<8;++way)
        {
            if (cur.x+dx[way]>=0&&cur.x+dx[way]<totx&&cur.y+dy[way]>=0&&cur.y+dy[way]<toty
                &&!visited[cur.x+dx[way]][cur.y+dy[way]])
                {
                    visited[cur.x+dx[way]][cur.y+dy[way]]=true;
                    que.push(Node(cur.x+dx[way],cur.y+dy[way],cur.step+1));
                }
        }
    }
    for (int i=0;i<totx;++i)
    {
        for (int y=0;y<toty;++y)
            std::cout<<std::left<<std::setw(5)<<map[i][y];
        std::cout<<std::endl;
    }
}