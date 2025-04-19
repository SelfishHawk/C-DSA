#include<iostream>
#include<vector>
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
    
void heapify(int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<=size && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<=size && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(largest);
    }
}
void buildHeap(){
    for(int i=size/2;i>=1;i--){
        heapify(i);
    }
}
};
int main(){
    heap h;
    int arr[6]={-1,54,53, 55, 50,52};
    for(int i=0;i<6;i++){
        h.arr[i]=arr[i];
    }
    h.size=5;
    h.buildHeap();
    h.print();
}