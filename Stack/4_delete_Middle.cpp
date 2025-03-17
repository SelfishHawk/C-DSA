#include<iostream>
#include<stack>
using namespace std;
void solve(stack<int> &org,int size,int n){
    if(n==size/2){
        org.pop();
        return;
    }
    int temp=org.top();
    org.pop();
    solve(org,size,n+1);
    org.push(temp);
}
int main(){
    stack<int> org;
    org.push(1);
    org.push(2);
    org.push(3);
    org.push(4);
    org.push(5);
    int size=org.size();
    int n=0;
    solve(org,size,n);
/*    stack<int> temp;
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
    */
   while(!org.empty()){
    cout<<" "<<org.top();
    org.pop();
}
}