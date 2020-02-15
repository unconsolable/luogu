/*注意:)(a+b)(
和)(a+b)*/
#include <iostream>
int main()
{
    char a;
    int cntLeft = 0, cntRight = 0, cntComp = 0;
    while (std::cin >> a && a != '@')
    {
        if (a == '(')
        {
            ++cntLeft;
            ++cntComp;
        }
        if (a == ')')
        {
            ++cntRight;
            if (cntComp>0) --cntComp;
        }
    }
    ((cntLeft==cntRight)&&(cntComp==0)) ? (std::cout << "YES") : (std::cout << "NO");
}