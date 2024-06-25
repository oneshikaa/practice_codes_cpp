#include<iostream>
using namespace std;

int main(){
    int arr[16] ={1,2,3,4,5,6,7,8,9,10} ;

    for(int i =0;i<4;i++){
        for(int j =0;j<4;j++){

            if(i<j){
                cout<<"0";

            }
            else{
                int k;
                cout<<arr[k];
                k++;
            }
            
        }
        cout<<"\n";
    }

    return 0;
}