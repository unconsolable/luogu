#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int v,n;
    cin>>v>>n;
    int32_t c[26],w[26],f[30001];
    memset(c,0,sizeof(c));memset(w,0,sizeof(w));memset(f,0,sizeof(f));
    for (int i=1;i<=n;++i)
    {
        cin>>c[i]>>w[i];
        w[i]*=c[i];
    }
    for (int i=1;i<=n;++i)
    {
        for (int j=v;j>=c[i];--j)
        {
            f[j]=max(f[j],f[j-c[i]]+w[i]);
        }
    }
    cout<<f[v];
}