#include <iostream>
#include <cstring>
#include <cmath>
//1->F 2->B 3->I
int isFBI(char *str,int start,int end)
{
    bool is0=true,is1=true;
    for (int i=start;i<end;++i)
    {
        if (str[i]=='1') is0=false;
        if (str[i]=='0') is1=false;
        if (!is0&&!is1) {return 1;break;}
    }   
    if (is0) 
        return 2;
    else
        return 3;
}
void trans_totree(char *str,int start,int end)
{
    if (end - start > 1)
    {
        trans_totree(str, start, (start + end) / 2);
        trans_totree(str, (start + end) / 2 , end);
    }
    switch (isFBI(str,start,end))
    {
    case 1:
        std::cout<<"F";
        break;
    case 2:
        std::cout<<"B";
        break;
    case 3:
        std::cout<<"I";
        break;
    default:
        break;
    }
}
int main()
{
    char str[1100];
    int len;
    std::cin>>len;
    len=pow(2,len);
    for (int i=0;i<len;++i)
    {
        std::cin>>str[i];
    }
    trans_totree(str,0,len);
    std::cout<<std::endl;
}