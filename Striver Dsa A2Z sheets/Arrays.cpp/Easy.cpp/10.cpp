#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int *arr;
    arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n-i; j++)
        {
           if (arr[j]>arr[j+1])
           {
              swap(arr[j],arr[j+1]);
           }
           
        }
        
        
    }


   for (int i = 0; i < n; i++)
   {
     
        if(arr[i]==i+1){
            continue;
        }
        else{
            cout<<i+1<<" "; 
            //break; 
     }
     
   }
 
}