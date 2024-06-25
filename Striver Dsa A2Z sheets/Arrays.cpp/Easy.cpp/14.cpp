#include<iostream>
using namespace std;

int main(){
    int n,m;
    cin>>n;
    int *arr;
    arr = new int[n];
    for (int i = 0; i <n; i++)
    {
        cin>>arr[i];
    }
    for (int i = 0; i < n; i = i+2)
    {
       if(arr[i]==arr[i+1]){
        continue;
       }
       else{
        cout<<arr[i]<<" ";
        
       }
    }
    
    

    
}