#include<iostream>
using namespace std;

class Array{
    int n;
    int *arr;
    int k;

    public : 
    void array(){
        arr = new int[n];
        cin>>n;
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        cin>>k;
 
    }

    void sum(){
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if(arr[i]+arr[j]==k){
                    cout<<i<<" "<<j<<endl;
                    break;

                }
            }
            
        }
        
    }

};


int main(){
    Array A;
    A.array();
    A.sum();

}