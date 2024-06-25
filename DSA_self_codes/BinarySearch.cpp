#include<iostream>
using namespace std;

int binarySearch(int arr[],int n,int target){
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid= (low+high)/2;
        if(target==arr[mid]){
            return mid;
        }
        if(target<arr[mid]){
            high = mid-1;
        }
        if(target>arr[mid]){
            low = mid+1;
        }
    }
    return -1;
}


int main(){
    int arr[6] = {2,4,5,6,7,8};
    cout<<binarySearch(arr,6,3);

}