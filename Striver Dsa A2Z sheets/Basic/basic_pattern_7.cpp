#include<iostream>
using namespace std;

 //   *
 //  ***
 // *****
 //*******
//*********

void printTriangle(int n) {

    

        for(int i=1; i<=n; i++){

            for(int j=n-i;j>0; j--)

                cout<<" ";

            for(int k=1; k<=2*i-1; k++)

                cout<<"*";

        cout<<endl;

        }

    }

int main(){


  printTriangle(5);
    

}

