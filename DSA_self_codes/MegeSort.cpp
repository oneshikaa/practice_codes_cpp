#include<stdio.h>
#include<stdlib.h>

void MergeSort(int A[],int l,int mid,int h)
{
int i,j,k;
i=l;
j=mid+1;
k=l;
int B[100];
while(i<=mid&&j<=h)
{
    if(A[i]<A[j])
    {B[k++]=A[i++];
    }
    else{B[k++]=A[j++];}
}

for(;i<=mid;i++)
{B[k++]=A[i];}

for(;j<=h;j++)
{B[k++]=A[j];}

for(int i=l;i<=h;i++)
{A[i]=B[i];}
}

void IMergeSort(int A[],int n)
{int p,i,l,mid,h;
for(p=2;p<=n;p=p*2) //for passes
{
    for(int i=0;i+p-1<n;i=i+p) //for 2 way merging
   
    {l=i;
    h=i+p-1;
    mid=(l+h)/2;
    MergeSort(A,l,mid,h);}
}
/*if(n-i>p/2)
 {
 l = i;
 h = i+p-1;
 mid = (l+h)/2;
 MergeSort(A, l, mid, n-1);
 } */
if(p/2<n)
{MergeSort(A,0,(p/2)-1,n-1);}}






int main()
{int A[]={6,4,5,3,8};
int n=5;
IMergeSort(A,n);


for(int i=0;i<n;i++)
{printf("%d ",A[i]);}}