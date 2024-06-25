#include<iostream>
using namespace std;

//**********
//****  ****
//***    ***
//**      **
//*        *
//*        *
//**      **
//***    ***
//****  ****
//**********

int main(){
    int n;
    cin>>n;
    //upper half
    for(int i = 0;i<n;i++){

        for(int j = n -i;j>0;j-- ){
            cout<<"*";
        }

       for (int k = 0; k <2*i; k++)
       {
        cout<<" ";
       }

       for(int l = n-i ;l>0;l--){
        cout<<"*";

       }

       cout<<"\n";

    }
    //lower half
     for(int i = 1;i<=n;i++){

        for(int j = 0;j<i;j++ ){
            cout<<"*";
        }


       for (int k = 2*(n-i) ; k>0; k--)
       {
        cout<<" ";
       }

       for(int l = 0 ;l<i;l++){
        cout<<"*";

       }

       cout<<"\n";

    }

}