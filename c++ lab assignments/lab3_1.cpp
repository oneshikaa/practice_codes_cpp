#include<iostream>
using namespace std;
 class A{
     int x;

     public :
      void setData(){

         
              cout<<"enter the value"<<endl;
              cin>>x;
          
        
     }

     void getData(){
         cout<<"the value of x is"<<x<<endl;
     }

 };

 int main(){
      
      A a[2];
      for(int i=0;i<2;i++){
          a[i].setData();
      }

       for(int i=0;i<2;i++){
          a[i].getData();
      }


     return 0;
 }