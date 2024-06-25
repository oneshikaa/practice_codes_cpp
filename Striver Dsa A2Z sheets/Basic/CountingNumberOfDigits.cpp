#include<iostream>
using namespace std;

int main(){
    int counter = 0;
    int n;
    cout<<"enter the number : "<<endl;
    cin>>n;
   while(n!=0){
    n = n/10;
    counter++;
   }

   cout<<"number of digits "<<counter<<endl;
    
}