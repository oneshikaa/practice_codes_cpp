#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter size"<<endl;
    cin>>n;
    int *arr;
    arr = new int[n];
    cout<<"enter elements"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if(arr[i]>max){
            max = arr[i];
        }
    }

    int min = max - arr[0];
    for (int i = 0; i < n; i++)
    {
        if (min>max-arr[i] && max-arr[i]!=0)
        {
            min = max - arr[i];
          
        }
     
    }
    
    int c =  max - min ;
    cout<<" second largest element : "<<endl;
    cout<< c <<endl;
    

}