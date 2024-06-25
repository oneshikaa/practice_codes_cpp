#include<iostream>
using namespace std;
template <class t>

class myclass{
    t x,y;
    public :
  

    t MyMax(t a,t b){
        t c;
        c = a>b?a:b; 
        return c;

    }

};

int main(){
    myclass<float>obj;
   cout<< obj.MyMax(3.9,2.0);
   
   

    return 0;


}