#include <iostream>
#include <string>
int main()
{
    std::string s1;int count=0;
    std::cin>>s1;
    for (const auto& a:s1)
        if (a=='1') ++count;
    std::cout<<count;
}