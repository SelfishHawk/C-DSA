#include<iostream>
using namespace std;
int main(){
    int n, sum=0;
    cout<<"Enter a number: ";
    cin>>n;
    while(n!=0){
        int r=n%10;
         sum=sum*10+r;
        n=n/10;
}
    cout<<"reverse of the given integar "<<sum;
    return 0;
}