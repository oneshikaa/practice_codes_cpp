#include<iostream>
using namespace std;

class A{
    int x;
    public :
    A(){}
    A(int i)
    {   x = i;
        cout<<"constructor called"<<endl;}

   

    A operator -(A &y ){
    A obj1 ;
    obj1.x = -y.x ;
    return obj1;

    }
    void show(){
        cout<<"the value of x is "<<x<<endl;
    }
};
int main(){
    A 

    
}