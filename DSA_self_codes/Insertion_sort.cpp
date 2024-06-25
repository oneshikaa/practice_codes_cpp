#include<iostream>
using namespace std;

int main(){
    int *arr;
    int n,temp;
    cout<<"enter the size : "<<endl;
    cin>>n;
    arr = new int[n];

    cout<<"enter the elements"<<endl;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    for(int i = 1;i<n;i++){
        temp = arr[i];
        int j = i;
        while(j>0 && arr[j-1]>temp){
            arr[j] = arr[j-1];
            j = j-1;
        }
        arr[j] = temp;


    }

    cout<<"sorted array"<<endl;
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
  
}