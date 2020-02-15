#include <stack>
#include <cctype>
#include <iostream>
int main()
{
    std::stack<long> value;
    std::stack<char> sgn;
    long tmpvalue=0,rightval=0,leftval=0;
    char tmpchar;
    while (std::cin >> tmpchar && tmpchar != '@')
    {
        if (isdigit(tmpchar))
        {
            tmpvalue = tmpvalue * 10 + tmpchar - '0';
        }
        if (tmpchar == '.')
        {
            value.push(tmpvalue);
            tmpvalue=0;
        }
        switch (tmpchar)
        {
        case '+':
            rightval = value.top();
            value.pop();
            leftval = value.top();
            value.pop();
            leftval += rightval;
            value.push(leftval);
            break;
        case '-':
            rightval = value.top();
            value.pop();
            leftval = value.top();
            value.pop();
            leftval -= rightval;
            value.push(leftval);
            break;
        case '*':
            rightval = value.top();
            value.pop();
            leftval = value.top();
            value.pop();
            leftval *= rightval;
            value.push(leftval);
            break;
        case '/':
            rightval = value.top();
            value.pop();
            leftval = value.top();
            value.pop();
            leftval /= rightval;
            value.push(leftval);
            break;
        default:
            break;
        }
    }
    std::cout<<value.top();
}