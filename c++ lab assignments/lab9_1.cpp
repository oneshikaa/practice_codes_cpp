#include<iostream>
using namespace std;
template <class t>

class myclass{
    t x,y;
    public :
    myclass(t a,t b){
        x = a;
        y = b;
    }

    int MyMax(){
        int c;
        c = x>y?x:y; 
        return c;

    }

};

int main(){
    myclass<int>obj(3,2);
   int c = obj.MyMax();
   cout<<c;
   

    return 0;


}
