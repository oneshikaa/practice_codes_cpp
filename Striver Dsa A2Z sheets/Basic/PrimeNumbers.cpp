#include<iostream>
using namespace std;

int main(){
    int i, n;
    cout<<"enter the number : "<<endl;
    cin>>n;
    for(int i = 2;i<n;i++){
        if(n%i==0){
            cout<<"The number is not prime.";
            break;
        }
    }
   
    if(i==n){
        cout<<"prime.";
    }
  
}