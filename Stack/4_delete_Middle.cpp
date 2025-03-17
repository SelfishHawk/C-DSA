#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> org;
    org.push(1);
    org.push(2);
    org.push(3);
    org.push(4);
    stack<int> temp;
    int size=org.size();
    int mid=size/2;
    for(int i=0;i<mid;i++){
        temp.push(org.top());
        org.pop();
    }
    org.pop();
while(!temp.empty()){
    org.push(temp.top());
    temp.pop();
}
while(!org.empty()){
    cout<<" "<<org.top();
    org.pop();
}
}