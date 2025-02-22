#include<iostream>
using namespace std;
int main(){
    int count=0,n=5;
    int arr[5]={64,25,12,22,11};
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
        count ++;
    }
    cout<<"sorted array :-"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}