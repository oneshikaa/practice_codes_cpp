#include<iostream>
using namespace std;

int partition(int A[],int l , int h){
    int pivot = A[l];
    int i,j;
    i = l;
    j = h;
    do{
        do
        {
           i++;
        } while (A[i]<pivot);
        do
        {
            j--;
        } while (A[j]>pivot);
        if (i<j)
        {
            swap(A[i],A[j]);
        }    
    }while(i<j);

    swap(A[l],A[j]);

    return j;

}

void quicksort(int A[],int l,int h){
    if (l<h)
    {
        int j = partition(A,l,h);
        quicksort(A,l,j);
        quicksort(A,j+1,h);
    }
    
}

int main(){
    int A[] = {2,5,3,6,7,8};
    int n = 6;
    quicksort(A,0,n-1);
    for (int i = 0; i <n; i++)
    {
        cout<<A[i]<<" ";
    }
    

}