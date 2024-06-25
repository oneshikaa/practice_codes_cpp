#include<iostream>
using namespace std;

class Base{
    public :
    int x, y;

    Base(int x1,int y1){
        x = x1;
        y = y1;

    }

    void getData(){
        cout<<x<<endl;
        cout<<y<<endl;
    }
    
};

class Derived : public Base{
    public :
    int a, b;

    Derived(int a1,int b1){
        a = a1;
        b = b1;
    }

    void getData(){
        cout<<a<<endl;
        cout<<b<<endl;
    }

};

int main(){

    Base b1(5,6),b2(7,8);

    Derived d1(1,2), d2(3,4);
    return 0;
}