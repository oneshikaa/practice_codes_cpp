#include <iostream>
using namespace std;

class recursion
{

    int n,counter;

public:
    recursion()
    {
        cout<<"enter the number"<<endl;
        cin>>n;
        counter = n;

    }
    void print(){
    if(counter>=1){
        
    cout<<counter<<" ";
    counter--;
    print();

    }
    else{
        return;
    }
   
}
};

int main(){
    recursion R;
    R.print();
}