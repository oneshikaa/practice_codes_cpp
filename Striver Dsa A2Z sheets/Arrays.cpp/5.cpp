#include<iostream>
using namespace std;

# define n 5 

int main(){
    int arr[] = {1,2,3,4,5};
    //int n = 5;
    int temp[n];
    for (int i = 0; i <n-1; i++)
    {
        temp[i] = arr[i+1];
    }
    temp[n-2] = arr[0];

    for (int i = 0; i < n; i++)
    {
        cout<<temp[i]<<" ";
    }
    
    

}