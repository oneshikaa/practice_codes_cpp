#include<iostream>
using namespace std;



int main(){
    int *arr;
    int n;
    arr = new int[n];
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int low = arr[0];
    int mid = arr[0];
    int high = arr[n-1];
    if(arr[mid]==0){
        swap(arr[mid],arr[low]);
        mid++;
    }
    

}