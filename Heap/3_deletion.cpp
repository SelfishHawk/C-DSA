#include<iostream>
using namespace std;
class heap{
    public:
    int arr[100];
    int size;
    heap(){
        arr[0]=-1;
        size=0;
    }
    void insert(int val){
        size++;
        int index=size;
        arr[index]=val;
        while(index>1){
            int parent=index/2;
           if(arr[index]>arr[parent]){
            swap(arr[index],arr[parent]);
            index=parent;
           }else{
            return;
           }
        }
        
    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
    void heapify(int* arr,int i){
        int greater=i;
        int left=2*i;
        int right=2*i+1;
        if(left<=size && arr[left]>arr[greater]){
            greater=left;
        }
        if(right<=size && arr[right]>arr[greater]){
            greater=right;
        }
        if (greater!=i){
            swap(arr[i],arr[greater]);
            heapify(arr,greater);
        }
    }
    void deleteHeap(){
        if(size==0){
            cout<<"Heap is already empty"<<endl;
            return;
        }
        arr[1]=arr[size];
        size--;
        heapify(arr,1);
    }
};
int main(){
    //1-based indexing
    //parent of node at index n is at index n/2
    //left child at arr 2*n and right child at 2*n+1
    heap h;
    h.insert(10);
    h.insert(90);
    h.insert(70);
    h.insert(990);
    h.print();
    h.deleteHeap();
    h.print();
}