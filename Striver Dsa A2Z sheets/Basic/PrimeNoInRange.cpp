#include<iostream>
using namespace std;

int main(){
    cout<<"enter the numbers : "<<endl;
    int i,a,b,n;
    cin>>a>>b;
    cout<<"enter the number between a and b to be checked : "<<endl;
    cin>>n;
    for(int i=a;i<=b;i++){
        for (int i = 2; i <n; i++)
        {
             
        if(n%i==0){
            cout<<"non prime"<<  
       endl;
            break;

        }

    }
      if(i==n){
        cout<<"prime.";
    }
    }
       }
