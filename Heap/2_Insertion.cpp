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
};
int main(){
    //1-based indexing
    //parent of node at index n is at index n/2
    heap h;
    h.insert(10);
    h.insert(90);
    h.insert(70);
    h.insert(990);
    h.print();
}