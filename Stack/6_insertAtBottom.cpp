#include<iostream>
#include<stack>
using namespace std;
void insert(stack<int> &s,int d){
    if(s.empty()){
        s.push(d);
        return;
    }
    int temp=s.top();
    s.pop();
    insert(s,d);
    s.push(temp);
}
int main(){
    stack<int> s;
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    int d=10;
    insert(s,10);
    while(!s.empty()){
        cout<<" "<<s.top();
        s.pop();
    }
    return 0;
}