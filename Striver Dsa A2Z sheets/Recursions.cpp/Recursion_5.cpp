#include<iostream>
using namespace std;

class recursion
{

    int n;
    int counter = 0;
    int prod = 0;

public:
    recursion()
    {
        cout<<"enter the number"<<endl;
        cin>>n;
    }
    int  sum(){
    if(counter<n){
    counter++;
    prod = prod + counter;
  
    sum();
    return prod;

    }
 
   
}
};

int main(){
    recursion r;
    cout<<r.sum();


}