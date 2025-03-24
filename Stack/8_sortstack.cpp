#include <iostream>
#include <stack>
using namespace std;
void insert(stack<int> &s, int d)
{
    if (s.empty() || s.top() < d)
    {
        s.push(d);
        return;
    }
    int temp = s.top();
    s.pop();
    insert(s, d);
    s.push(temp);
}
void sort(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int temp = s.top();
    s.pop();
    sort(s);
    insert(s, temp);
}
int main()
{
    stack<int> s;
    s.push(5);
    s.push(7);
    s.push(9);
    s.push(-2);
    s.push(3);
    sort(s);
    while (!s.empty())
    {
        cout << " " << s.top();
        s.pop();
    }
}