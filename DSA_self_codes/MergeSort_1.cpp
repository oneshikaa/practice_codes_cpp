#include<iostream>
using namespace std;

int Merge(int A[],int l,int mid,int h){
    int i,j,k;
    int n1 = mid-l+1 ;
    int n2 = h-mid;

    int *B = new int;
    int *C = new int;
    
   // int B[n1];
    //int C[n2];
    for (int i = 0; i < n1; i++)
    {
        B[i] = A[i+l];
    }
    for (int i = 0; i < n2; i++)
    {
        C[i] = A[mid+1+i];
    }
    i = 0;
    j = 0;
    k = l;
    int inv_count = 0;
    while (i<n1 && j<n2)
    {
        if (B[i]<C[j])
        {
            A[k++] = B[i++];
        }
        else
        {
            A[k++] = C[j++];
            inv_count += (mid - i+1);
        }   
    }
    while(i <n1)
    {
         A[k++] = B[i++];
    }
    while(j <n2)
    {
        A[k++] = C[j++];
    }
   // cout << "Inversion count : " << inv_count << endl;
	return inv_count;
     
}

int MergeSort(int A[],int l,int h){
    int inv_count = 0;
    if (l<h)
    {
        int mid = (l+h)/2;
        inv_count += MergeSort(A,l,mid);
        inv_count +=MergeSort(A,mid+1,h);
        inv_count += Merge(A,l,mid,h);
    }
    return inv_count;
}

int main(){
    int A[7] = {5,2,7};
    int n =3;
    cout<<MergeSort(A,0,n-1);
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<A[i]<<" ";
    // }
    

}