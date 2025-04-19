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
            swap(arr[i],arr[largest]);
            heapify(largest);
        }
    }
    void HeapSort(){
        int originalsize=size;
        while(size>1){
        swap(arr[1],arr[size]);
        size--;
        heapify(1);
    }
        size=originalsize;
}
};
int main(){
    heap h;
    h.insert(10);
    h.insert(90);
    h.insert(70);
    h.insert(990);
    h.print();
    h.HeapSort();
    h.print();
}