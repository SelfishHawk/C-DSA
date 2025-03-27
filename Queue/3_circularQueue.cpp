#include<iostream>
using namespace std;
class queue{
    int* arr;
    int front;
    int rear;
    int size;
    public:
    queue(int n){
        size=n;
        arr=new int[size];
        front=rear=-1;
    }
int circularQueue(int data){
    if((front==0 && rear==size-1) || (rear==(front-1)%(size-1))){
        cout<<"Queue is full"<<endl;
        return -1;
    }
    else if(front!=0 && rear==size-1){
        rear=0;
    }
    else if(front ==-1){
        front=rear=0;
    }
    else{
        rear++;
    }
    arr[rear]=data;
}
 void pop(){
    if(front==-1 && rear==-1){
        cout<<"Empty queue"<<endl;
        return;
    }
    int ans = arr[front];
    arr[front] = -1;
    if(front == rear) {
        front = rear = -1;
    }
    else if(front == size - 1) {
        front = 0;
    }
    else{
        front++;
    }
    return;
}
void print(){
    if (front == -1) {
        cout << "Queue is empty" << endl;
        return;
    }
    int i = front;
    while (true) {
        cout << arr[i] << " ";
        if (i == rear) break;
        i = (i + 1) % size;
    }
    cout << endl;
}
};

int main(){
    queue q(5);
    q.circularQueue(1);
    q.circularQueue(2);
    q.circularQueue(3);
    q.circularQueue(4);
    q.circularQueue(5);
    q.print();
    q.pop();
    q.print();
    q.circularQueue(5);
    return 0;
}