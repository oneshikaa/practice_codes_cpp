#include<iostream>
using namespace std;

int main(){
    int arr[3] ={1,2,3} ;

    for(int i =0;i<3;i++){
        for(int j =0;j<3;j++){
            if(i!=j){
                cout<<"0";

            }
            else{
                cout<<arr[i];
            }
            
        }
        cout<<"\n";
    }

    return 0;
}