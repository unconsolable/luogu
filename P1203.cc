#include <iostream>
int main()
{
    size_t n,maxans=0;
    char neck[710];
    std::cin>>n;
    for (size_t i=0;i<n;++i)
    {
        std::cin>>neck[i];
        neck[n+i]=neck[i];
    }
    for (size_t i=0;i<n;++i)
    {
        size_t tmpans=0,endpos=n+i-1,startpos=i;
        bool isstart=true,isend=true;
        char startc=neck[i],endc=neck[n+i-1];
        if (startc=='w')
        {
            auto tmpstartpos=i+1;
            while (neck[tmpstartpos]=='w')
                ++tmpstartpos;
            startc=neck[tmpstartpos];
        }
        if (endc=='w')
        {
            auto tmpendpos=n+i-2;
            while (neck[tmpendpos]=='w')
                --tmpendpos;
            startc=neck[tmpendpos];
        }
        while (startpos<endpos)
        {
            if (isstart&&(neck[startpos]==startc||neck[startpos]=='w'))
            {
                ++tmpans;
                ++startpos;
            }
            else
            {
                isstart=false;
            }
            if (isend&&(neck[endpos]==endc||neck[endpos]=='w'))
            {
                ++tmpans;
                --endpos;
            }
            else
            {
                isend=false;
            }
            if (!isstart&&!isend)
                break;
        }
        if (startpos==endpos)
        {
            if (neck[startpos]==neck[i]||neck[endpos]==neck[n+i-1]||neck[startpos]=='w')
                ++tmpans;
        }
        if (tmpans>maxans) maxans=tmpans;
    }
    std::cout<<maxans;
}