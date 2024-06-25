#include<iostream>
using namespace std;

void digits(int n){
   
    n = n%10;
    
    n = n/10;


}

int main(){
    int n,digit;
    cout<<"enter the number :"<<endl;
    cin>>n;
    int reverse = 0;
    while(n!=0){
         digit = n%10;
         reverse  = reverse*10 + digit;
         n = n/10; 
    }
    cout<<"reversed number :"<<reverse;
    
    


}