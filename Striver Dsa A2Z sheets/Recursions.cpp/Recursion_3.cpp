#include<iostream>
using namespace std;

int counter = 1;

void print(int n){
    if(counter<=n){
        
    cout<<counter<<" ";
    counter++;
    print(n);

    }
    else{
        return;
    }
   
}

int main(){
    int a;
    cin>>a;
    print(a);

}