#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    if(n>=0){ cout<<"number is positive\n";
    }else{ cout<<"number is negative\n";
    }
    int count=1;
    while(count<=10){
        int a=count*n;
        cout<<n<<"*"<<count<<"="<<a<<endl;
        count++;
    }
    int s=1,sum=0;
    while(s<=n){
        sum+=s;
        s++;
    }
    cout<<"Sum of first "<<n<<" natural numbers is: "<<sum<<endl;
    
    int f=9;
    if(f==9){
        cout<<"f is 9\n";
    }
    if(f > 0){ cout<<"f is positive\n";} else{ cout<<"f is negative\n";
}

return 0;
}