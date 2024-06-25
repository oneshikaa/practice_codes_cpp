#include<iostream>
#include<algorithm>
using namespace std;

class sol{
    int *arr;
    int n;

    public :

    void get_array(){
    cout<<"enter number of elements"<<endl;
    cin>>n;   
    arr = new int[n];
    cout<<"enter the elements"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }  
}

int min(int a,int b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }

}

void water(){
    int sum  = 0;
    for (int i = 1; i < n; i++)
    {
        int count = min(abs(arr[i]-arr[i+1]),abs(arr[i]-arr[i-1])); 
        sum = sum + count;

    }
    cout<<sum;   
}
};



int main(){
    sol s;
    s.get_array();
    s.water();
}