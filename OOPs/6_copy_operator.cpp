#include<iostream>
using namespace std;
class hero{
    public:
    int level;
    int health;
    hero(int health,int level){
        this->health=health;
        this->level=level;
        cout<<"Constructor is called"<<endl;
    }
    ~hero(){
        cout<<"Destructor called"<<endl;
    }
};
int main(){
    hero a(70,65);
    cout<<"Level of a-"<<a.level<<endl;
    cout<<"health of a-"<<a.health<<endl;
   hero b = a;
   cout<<"Level of b-"<<b.level<<endl;
   cout<<"health of b-"<<b.health<<endl;

}