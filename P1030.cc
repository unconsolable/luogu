    #include <iostream>
    #include <cstring>
    //[start,end)
    void findbegin(char *middle,int middlestart,int middleend,char* end,int endstart,int endend)
    {
        if (middlestart==middleend||endstart==endend) return;
        char root=end[endend-1];int i;
        for (i=middlestart;i<middleend;++i)
        {
            if (middle[i]==root) break;
        }
        std::cout<<root;
        int len=i-middlestart; //len为0只能说明缺一半子树
        findbegin(middle,middlestart,i,end,endstart,endstart+len);
        findbegin(middle,i+1,middleend,end,endstart+len,endend-1);
    }
    int main()
    {
        char middle[15];
        char last[15];
        std::cin>>middle;
        std::cin>>last;
        findbegin(middle,0,strlen(middle),last,0,strlen(last));
    }