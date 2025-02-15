#include<iostream>
#include<cstring>
#include "2_Hero.cpp"
using namespace std;
int main(){
    Hero SS;
    SS.name = "Sahil";
    SS.setlevel(100);
    SS.sethealth(70);
    cout<<"Noob name "<<SS.name<<endl;
    cout<<"Level "<<SS.getlevel()<<endl;
    cout<<"Health "<<SS.gethealth()<<endl;
    return 0;
}