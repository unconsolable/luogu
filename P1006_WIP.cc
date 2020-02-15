#include <iostream>
#include <cstring>
int ans=0;
int m, n, startx, starty, endx, endy;
int map[55][55];
bool visited[55][55], isstart = true;
void goandback(bool isback, int curx, int cury, int curans)
{
    int dx[2],dy[2];
    if (curx<0||cury<0||curx>=m||cury>=n) 
        return;
    if (isback)
    {
        dx[0]=0;dx[1]=-1;dy[0]=-1;dy[1]=0;
    }
    else
    {
        dx[0]=0;dx[1]=1;dy[0]=1;dy[1]=0;
    }
    if (!isback&&curx==endx&&cury==endy)
    {
        goandback(true,curx,cury,curans);
    }
    if (isback&&curx==startx&&cury==starty)
    {
        if (curans>ans) ans=curans;
        return;
    }
    for (int i=0;i<2;++i)
    {
        if (curx+dx[i]>=0&&curx+dx[i]<m&&cury+dy[i]>=0&&cury+dy[i]<n&&!visited[curx+dx[i]][cury+dy[i]])
        {
            visited[curx+dx[i]][cury+dy[i]]=true;
            goandback(isback,curx+dx[i],cury+dy[i],curans+map[curx+dx[i]][cury+dy[i]]);
            visited[curx+dx[i]][cury+dy[i]]=false;
        }
    }
}
int main()
{
    memset(visited,false,sizeof(visited));
    std::cin>>m>>n;
    for (int i=0;i<m;++i)
    {
        for (int j=0;j<n;++j)
        {
            std::cin>>map[i][j];
            if (!map[i][j]&&isstart)
            {
                isstart=false;
                startx=i;starty=j;
            }
            if (!map[i][j]&&!isstart)
            {
                endx=i;endy=j;
            }
        }
    }
    goandback(false,startx,starty,0);
    std::cout<<ans<<std::endl;
}