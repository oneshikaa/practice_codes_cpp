#include<iostream>
using namespace std;

class base{
    public :

    void print(){
        cout<<"base class function"<<endl;

    }


};

class derived : public base{
    public :

    void show(){
        cout<<"base class function"<<endl;
        
    }


};
int main(){

    base *obj1;
    derived *obj2;
    obj1->print();
    obj2->show();
    return 0;

}