#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout<<"printing top element "<<s.top()<<endl;
    s.pop();
    cout<<"printing top element "<<s.top()<<endl;
    cout<<"Size of the stack is "<<s.size()<<endl;
    if(s.empty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack is non empty"<<endl;
    }
}