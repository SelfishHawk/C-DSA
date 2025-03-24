#include <iostream>
#include <stack>
using namespace std;
/*
int valid(string &s)
{
    stack<char> st;
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch =='{')
        {
            st.push(ch);
        }
        else
        {
            if (st.empty())
            {
                count++;
            }
            else
            {
                st.pop();
            }
        }
        delete &s[i];
    }
    count+=st.size()/2;
    return count;
}
    */
   int valid(string &str){
    stack<char> s;
    for(int i=0;i<str.length();i++){
        char ch = str[i];
        if (ch =='{')
        {
            s.push(ch);
        }
        else
        {
            if(!s.empty() && s.top()=='{'){
                s.pop();
            }
            else{
                s.push(ch);
            }
        }
    }
    int a=0,b=0;
    while(!s.empty()){
        if(s.top()=='{') a++;
        else b++;
        s.pop();
    }
    int ans=(a+1)/2 +(b+1)/2 ;
    return ans;
}
    int main()
    {
        string str = "{{{}";
        if (str.length() % 2 != 0)
        {
            cout<<"Invalid no. of paranthesis and can't be sorted. "<<endl;
            return -1;
        }
        cout<< "Min valid changes "<<valid(str)<<endl;
        return 0;
    }