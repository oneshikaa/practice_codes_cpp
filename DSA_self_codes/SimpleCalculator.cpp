#include<iostream>
using namespace std;

int main(){
    int n1,n2;
    cout<<"enter the numbers : "<<endl;
    cin>>n1>>n2;
    char op;
    cout<<"enter the operator : "<<endl;
    cin>>op;
    switch(op){
        case '+':
        cout<<n1 +n2;
        break;

        case '-':
        cout<<n1-n2;
        break;

        case '%':
        cout<<n1%n2;
        break;

        case '/':
        cout<<n1/n2;
        break;

        default :
        cout<<"enter another operator";
        break;

    }


}