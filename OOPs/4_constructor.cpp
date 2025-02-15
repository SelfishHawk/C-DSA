#include<iostream>
using namespace std;
#include<cstring>
class Hero{
    public:
    std:: string name;
    private:
    int health;
    int level;
    public:
    int gethealth(){
        return health;
    }
    int getlevel(){
        return level;
    }
    void sethealth(int h){
        health=h;
    }
    void setlevel(int l){
        level=l;
    }
    //Constructor 
    Hero(){
        cout<<"Constructor Called"<<endl;
    }
    //destructor
    ~Hero(){
        cout<<"Destructor called  .."<< this->health<<endl;
    }
};
int main(){
    Hero a;
    a.sethealth(65);
    a.setlevel(56);
    cout<<"Level "<<a.getlevel()<<endl;
    cout<<"Health "<<a.gethealth()<<endl;
    //dynamic allocation
    Hero* b=new Hero; // Constructot called again
    (*b).sethealth(66);
    (*b).setlevel(56);
    cout<<"Level "<<(*b).getlevel()<<endl;
    cout<<"Health "<<b->gethealth()<<endl;
    delete b;
    return 0;
}