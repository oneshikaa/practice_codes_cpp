#include<iostream>
using namespace std;

int main(){

    int temp;
    int a[7] = {64,34,25,12,22,11,90};
    for(int i = 0;i<6;i++){
        for(int j = i+1;j<7;j++){
            if(a[i]>a[j]){
                temp = a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }


for(int i= 0;i<7;i++){
    cout<<a[i]<<" ";
}
}