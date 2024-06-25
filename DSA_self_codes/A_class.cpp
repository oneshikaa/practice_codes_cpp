#include<iostream>
using namespace std;

int main(){
    int *arr;
    int n,temp,swap = 0;
    int count = 0;
   

    cout<<"enter the size : "<<endl;
    cin>>n;
    arr = new int[n];

    cout<<"enter the elements"<<endl;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    for(int i = 1;i<n;i++){
         int comparison = 0;
        count++;
        temp = arr[i];
        int j = i;
        while(j>0 && arr[j-1]>temp){
            if( arr[j-1]>temp){
                comparison++;
            }
            
            arr[j] = arr[j-1];
            j = j-1;
            swap++;
        
        }
        arr[j] = temp;


         cout<<"Pass "<<count<<endl;
         for(int k = 0;k<n;k++){
        cout<<arr[k]<<" ";
        
         }
         cout<<"No. of swaps for pass "<<count<<" is "<<swap<<endl;
          cout<<"No. of comparisons for pass "<<count<<" is "<<comparison<<endl;
         cout<<"\n";

    }
     

   /* cout<<"sorted array"<<endl;
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }*/
  
}