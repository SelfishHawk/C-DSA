#include<iostream>
#include "2_Hero.cpp"
using namespace std;
int main(){
    //static allocation
    Hero a;
    a.sethealth(65);
    a.setlevel(56);
    cout<<"Level "<<a.getlevel()<<endl;
    cout<<"Health "<<a.gethealth()<<endl;
    //dynamic allocation
    Hero* b=new Hero;
    (*b).sethealth(65);
    (*b).setlevel(56);
    cout<<"Level "<<(*b).getlevel()<<endl;
    cout<<"Health "<<b->gethealth()<<endl; //another way to present the notation
}