#include<iostream>
#include<stack>
using namespace std;
int main(){
    string str="srijan";
    stack<char> rev;
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        rev.push(ch);
    }
    string ans="";
    for(int i=0;i<str.length();i++){
        char ch=rev.top();
        ans.push_back(ch);
        rev.pop();
    } 
    cout<<"Reverse of the string is "<<ans<<endl;
}