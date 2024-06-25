#include<iostream>
using namespace std;

int main(){
    int arr[] = {3,5,2,6,4,8,7};
    int n = 7;
    for (int i = 0; i < n-1; i++)
    {
        int min = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j]<arr[i])
            {
                min = j;
            }
        
        }
            if (min!=i)
            {
                swap(arr[min],arr[i]);
            }
        
    }

    for (int i = 0; i < n;i++) {
        cout<<arr[i]<<" ";
    }
    
    
    
}