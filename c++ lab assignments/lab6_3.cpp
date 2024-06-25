#include<iostream>
using namespace std;
#include<iostream>
using namespace std;
  

class Base
{
protected:
int x;
public:
void fun() {
              
            cout<<"Constructor of base called\n";
            }
};
  
class Derived: public Base
{
    int y;
public:
    
    void func() { cout << "derived class"<<endl ;}
};
  
int main(void)

{ 
    Base *b = new Base();
    b->fun();

    Derived *d = new Derived();
    d->func();

    Base *ptr = new Derived();
    ptr->fun();

    






    return 0;
}