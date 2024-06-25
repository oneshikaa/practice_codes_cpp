#include<iostream>
using namespace std;

int main(){
    int arr[5];
    cout<<"enter elements : "<<endl;;
    for (int i = 0; i < 5; i++)
    {
       cin>>arr[i];
    }
    

    for(int i = 0;i<4;i++){
        int flag = 0;
        for (int j = 0; j < 4-i; j++)
        {
            if(arr[j]>arr[j+1]){
                flag = 1;
                
                swap(arr[j],arr[j+1]);
            }
            if (flag = 0){
                break;
            }
        }
        
    }
    cout<<"after bubble sort : "<<endl;
    for (int i = 0; i <5; i++)
    {
    cout<<arr[i]<<" ";
    }
    
}