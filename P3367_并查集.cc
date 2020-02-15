#include <iostream>
#include <cstring>
#define MAXN 10000
//找到
int Find(int k,int Set[])
{
    //非递归版:
    int k_orig=k;
    while (Set[k]!=k)
        k=Set[k];
    return Set[k_orig]=k;
}
int Find_Recursive(int k,int Set[])
{
    //递归版:
    if (Set[k]==k) 
    //与元素k有关的变量只有k
        return k;
    //用路径压缩 Set[k]中元素即为根元素的下标
    return Set[k]=Find(Set[k],Set); //沿相关元素找
}
int main()
{
    int relation[MAXN]={},operNum,elemNum;
    std::cin>>elemNum>>operNum;
    for (int i=0;i<elemNum;++i)
    {
        relation[i]=i;
    }
    for (int i=0;i<operNum;++i)
    {
        int operType,Xi,Yi;
        std::cin>>operType>>Xi>>Yi;
        // 数组中对第i个元素(i从1开始)的关系表现为relation[i-1]
        switch (operType)
        {
            case 1:
                // Wrong:
                // relation[Xi-1]=Find(Yi-1,relation);
                // 改变的是Xi所属的集合 应找到Xi所属的根源
                // 即集合中最先有的元素/relation[k]=k的元素
                // Right:
                relation[Find(Xi-1,relation)]=Find(Yi-1,relation);
                break;
            case 2:
                if (Find(Xi-1,relation)==Find(Yi-1,relation))
                    std::cout<<'Y'<<std::endl;
                else
                    std::cout<<'N'<<std::endl;
                break;
            default:
                break;
        }
    }
}