#include<iostream>
using namespace std;
int main(){
    int n=4;
    for(int i=1; i<=n; i++){
        int a=64;
        if(i%2!=0){
            for (int j=1; j<=i; j++){
                cout<<j<<" ";
            }
        }
        else{
            for (int j=1; j<=i; j++){
                int b=a+j;
                char c=(char)b;
                cout<<c<<" ";
            }
        }
        cout<<"\n";
    }
}