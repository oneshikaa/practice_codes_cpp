#include<iostream>
using namespace std;

class Memory{

    int *arr;
    int r;

    public :

    Memory(){
        cout<<"enter the requirement : "<<endl;;
        cin>>r;
        arr = new int[5];
        cout<<"enter the memory spaces available : "<<endl;
        for (int i = 0; i < 5; i++)
        {
            cin>>arr[i];
        }
        
    }

    int first_fit(){
       
       for (int i = 0; i < 5; i++)
       {
      
       
       if(arr[i]-r>=0){
        return arr[i];
       }
       }

    }

    int best_fit(){
        int min = r;

       
        for (int i = 0; i < 5; i++)
        {
        
            if( arr[i]-r>=0 && arr[i]<min){
                min = arr[i];
            }
        }

        return min;
        
    }

    int worst_fit(){
        int max = arr[0];
        for (int i = 1; i < 5; i++)
        {
            if(max<arr[i] && arr[i]-r>=0){
                max = arr[i];
            }
        }

        return max;

    }


};


int main(){

    Memory m;
    cout<<"first fit : "<<m.first_fit()<<endl;
    cout<<"best fit : "<<m.best_fit()<<endl;
    cout<<"worst fit : "<<m.worst_fit()<<endl;
    



}