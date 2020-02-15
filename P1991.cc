#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
struct Edge
{
    double weight[550] = {};
    // unsigned int begin[550] = {};
    // unsigned int end[550] = {};
    unsigned int cnt = 0;
};
double edges[550][550];
Edge spantree;
int phonecnt, placecnt;
int posx[550], posy[550];
inline double dist(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
void Prim()
{
    double distnum[550];
    unsigned int adjvex[550]={};
    for (int i=1;i<placecnt;++i)
        distnum[i]=edges[0][i];
    adjvex[0]=1;
    for (int i=1;i<placecnt;++i)
    {
        int minvex=-1;
        double min=21474835;
        for (int j=0;j<placecnt;++j)
        {
            if (!adjvex[j]&&distnum[j]<min)
            {
                minvex=j;
                min=distnum[j];
            }
        }
        adjvex[minvex]=1;
        spantree.weight[spantree.cnt++]=min;
        for (int j=0;j<placecnt;++j)
        {
            if (!adjvex[j]&&edges[minvex][j]<distnum[j])
                distnum[j]=edges[minvex][j];
        }
    }
}
int main()
{
    std::cin >> phonecnt >> placecnt;
    for (int i = 0; i < placecnt; ++i)
    {
        std::cin >> posx[i] >> posy[i];
        for (int j = 0; j < i; ++j)
            edges[i][j] = edges[j][i] = dist(posx[i], posy[i], posx[j], posy[j]);
    }
    Prim();
    std::sort(spantree.weight,spantree.weight+spantree.cnt,std::greater<double>());
    std::cout<<std::fixed<<std::setprecision(2)<<spantree.weight[phonecnt-1]<<std::endl;
}