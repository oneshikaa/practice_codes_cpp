#include<iostream>
using namespace std;
class Base {
   public:
      virtual void func() = 0; 
};

class Derived :public Base {
   public:
      void func() {
         cout << "Virtual Function in Derived class\n";
      }
};

int main() {
   Base *b;
   Derived dobj;
   b = &dobj;
   b->func();
   return 0;
}
