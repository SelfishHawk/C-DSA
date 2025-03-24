#include<iostream>
using namespace std;
class queue{
    public:
    int data;
    queue* next;
    queue(int data){
        this->data=data;
        this->next=NULL;
    }
};
void push(queue* &front,queue* &rear,int d){
    queue* newnode=new queue(d);
    if(rear==NULL){
        front=rear=newnode;
        return;
    }
    rear->next=newnode;
    rear=newnode;
}
void pop(queue* &front,queue* &rear){
    if(front==NULL){
        cout<<"Empty queue"<<endl;
        return;
    }
    queue* temp=front;
    front=front->next;
    if(front==NULL) rear=NULL;
    delete temp;
}
int size(queue* &front,queue* &rear){
    int count=0;
    queue* temp=front;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
bool empty(queue* &front,queue* &rear){
    if(front==NULL){
        cout<<"Queue is empty"<<endl;
        return true;
    }
    else{
        cout<<"Queue is non empty"<<endl;
        return false;
    }
}
int peek(queue* &front,queue* &rear){
    if(front ==NULL){
        cout<<"EMpty queue"<<endl;
        return -1;
    }
    return front->data;
}
int main(){
    queue *front=NULL;
    queue *rear=NULL;
    push(front,rear,10);
    push(front,rear,20);
    push(front,rear,30);
    push(front,rear,40);
    push(front,rear,50);
    push(front,rear,60);
    cout<<"Size of the queue is "<<size(front,rear)<<endl;
    cout<<"First element of the queue is "<<peek(front,rear)<<endl;
    pop(front,rear);
    cout<<"Size of the queue is "<<size(front,rear)<<endl;
    cout<<"First element of the queue is "<<peek(front,rear)<<endl;
    return 0;
}