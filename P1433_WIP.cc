#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
double result=2147283.2;
double dist(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
struct Node
{
    double x=0;double y=0;
    Node()=default;
    Node(double x,double y):x(x),y(y) {}
};
struct Map
{
    Node Nodes[16];
    double Edge[16][16]={0};
    int numVexs;
};
void Init(Map &m1,int total)
{
    for (int i=0;i<total;++i)
    {
        for (int j=0;j<total;++j)
        {
            if (i>=j)
                m1.Edge[i][j]=m1.Edge[j][i]=dist(m1.Nodes[i].x,m1.Nodes[i].y,m1.Nodes[j].x,m1.Nodes[j].y);
        }
    }
}
void dfs(Map m,bool parents[],int finishEdge,int totEdge,int curNode,double curresult)
{
    if (curresult>result)
    {
        //长度剪枝
        return;
    }
    if (finishEdge==totEdge)
    {
        result=std::min(result,curresult);
        return;
    }
    for (int i=1;i<m.numVexs;++i)
    {
        if (!parents[i])
        {
            parents[i]=true;
            dfs(m,parents,finishEdge+1,totEdge,i,m.Edge[curNode][i]+curresult);
            parents[i]=false;
        }
    }
}
int main()
{
    Map map;bool parents[16];
    memset(parents,false,sizeof(parents));
    map.Nodes[0].x=0;map.Nodes[0].y=0;
    std::cin.sync_with_stdio(false);std::cout.sync_with_stdio(false);
    std::cin>>map.numVexs;++map.numVexs;
    for (int i=1;i<map.numVexs;++i)
    {
        std::cin>>map.Nodes[i].x>>map.Nodes[i].y;
    }
    Init(map,map.numVexs);
    //并查集初始化
    //从(0,0)点选边走
    for (int i=1;i<map.numVexs;++i)
    {
        parents[i]=true;
        dfs(map,parents,1,map.numVexs-1,i,map.Edge[0][i]);
        parents[i]=false;
    }
    std::cout<<std::fixed<<std::setprecision(2)<<result<<std::endl;
}