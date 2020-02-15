#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_ROW 1000
int main()
{
    int n;
    cin>>n;
    int data[MAX_ROW][MAX_ROW];
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<=i;++j)
        {
            cin>>data[i][j];
        }
    }
    for (int i=n-2;i>=0;--i)
    {
        for (int j=0;j<=i;++j)
        {
            data[i][j]+=std::max(data[i+1][j],data[i+1][j+1]);
        }
    }
    cout<<data[0][0];
}