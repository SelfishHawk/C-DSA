#include <iostream>
#include <stack>
using namespace std;
bool check(string str)
{
    stack<char> temp;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '(' || ch == '{' || ch == '[')
        {
            temp.push(ch);
        }
        else
        {
            if (!temp.empty())
            {
                char top = temp.top();
                if ((top == '(' && ch == ')') || (top == '{' && ch == '}') || (top == '[' && ch == ']'))
                {
                    temp.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    return temp.empty();
}
int main()
{
    string str = "{{()}}";
    check(str);
    if (check(str) == 1)
    {
        cout << "The string is valid" << endl;
    }
    else
    {
        cout << "The string is invalid" << endl;
    }
    return 0;
}