#include<iostream>
using namespace std;

int main(){
    int n,digit,reverse;
    reverse = 0;

    cout<<"enter the number"<<endl;
    cin>>n;

    int num = n;

    while(num!=0){
        digit  = num%10;
        reverse  = reverse*10 + digit;
        num = num/10;
 
    }

    if(reverse==n){
        cout<<"Number is palindromic"<<endl;

    }
    else
    cout<<"Number is not palindromic"<<endl;





    
    


}