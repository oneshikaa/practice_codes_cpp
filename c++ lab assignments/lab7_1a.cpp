#include<iostream>
using namespace std;
class A{
    int x;
    public :
    A(int i)
    {   x = i;
        cout<<"constructor called"<<endl;}

   

    void operator +( ){
        x = -x;
    }

    void show(){
        cout<<"the value of x is "<<x<<endl;
    }


};
int main(){
    A obj(5);
    +obj;

    
    obj.show();




    return 0;
}