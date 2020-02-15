#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
long ans[6005][2];
struct CTree_Node
{
    int happy;
    std::vector<int> child;
    int parent=-1;
};
int main()
{
    int cnt,root;
    CTree_Node tree[6005];
    //[i][0]表示节点i不参加 [i][1]表示参加
    std::cin>>cnt;
    for (int i=0;i<cnt;++i)
    {
        std::cin>>tree[i].happy;
    }
    int child,parent;
    while (std::cin>>child>>parent&&child&&parent)
    {
        tree[parent-1].child.push_back(child-1);
        tree[child-1].parent=parent-1;
    }
    auto rule=[](long (&arr)[2])
    {
        arr[0]=-2147483;
        arr[1]=-2147483;
    };
    std::for_each(ans,ans+cnt+2,rule);
    std::queue<int> process_next;
    bool visited[6005]{};
    //找叶子节点 沿叶子节点上找
    for (int i=0;i<cnt;++i)
    {
        if (tree[i].child.empty())
        {
            if (!visited[tree[i].parent])
            {
                visited[tree[i].parent] = true;
                process_next.push(tree[i].parent);
            }
            ans[i][0]=0;
            ans[i][1]=tree[i].happy;
        }
    }
    while (!process_next.empty())
    {
        auto curr=process_next.front();
        process_next.pop();
        visited[curr]=false;
        long tmpsum0=0,tmpsum1=0;
        for (const auto &i:tree[curr].child)
        {
            tmpsum0=std::max(tmpsum0+ans[i][1],tmpsum0);
            tmpsum1=std::max(tmpsum1+ans[i][0],tmpsum1);
        }
        //直接下属都不来 上司也不一定要来
        tmpsum1=std::max(tmpsum1+tree[curr].happy,tmpsum1);
        ans[curr][0]=std::max(ans[curr][0],tmpsum0);
        ans[curr][1]=std::max(ans[curr][1],tmpsum1);
        if (tree[curr].parent!=-1&&!visited[tree[curr].parent])
        {
            visited[tree[curr].parent]=true;
            process_next.push(tree[curr].parent);
        }
        if (tree[curr].parent==-1)
        {
            root=curr;
        }
    }
    std::cout<<std::max(ans[root][0],ans[root][1])<<std::endl;
}