#include<iostream>
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
};