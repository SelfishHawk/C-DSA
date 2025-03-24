#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    cout<<"printing first element "<<q.front()<<endl;
    q.pop();
    cout<<"printing first element "<<q.front()<<endl;
    cout<<"Size of the stack is "<<q.size()<<endl;
    if(q.empty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack is non empty"<<endl;
    }
}