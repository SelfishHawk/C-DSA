#include<iostream>
#include<queue>
using namespace std;
int main(){
    //Heap is a CBT (every level is filled except last,nodes are added from left to right)
    // STL for max heap
    priority_queue<int> pq;
    pq.push(10);
    pq.push(90);
    pq.push(40);
    pq.push(70);
    pq.push(50);
    cout<<"Element at top is: "<<pq.top()<<endl;
    pq.pop();
    cout<<"Element at top is: "<<pq.top()<<endl;
    cout<<"Size of heap is "<<pq.size()<<endl;
    if(pq.empty()){
        cout<<"Heap is empty"<<endl;
    }else{
        cout<<"heap is not empty"<<endl;
    }
    //STL for min heap
    priority_queue<int,vector<int>,greater<int>> mh;
    mh.push(10);
    mh.push(90);
    mh.push(40);
    mh.push(70);
    mh.push(50);
    cout<<"Element at top is: "<<mh.top()<<endl;
    mh.pop();
    cout<<"Element at top is: "<<mh.top()<<endl;
    cout<<"Size of heap is "<<mh.size()<<endl;
    if(mh.empty()){
        cout<<"Heap is empty"<<endl;
    }else{
        cout<<"heap is not empty"<<endl;
    }   
}