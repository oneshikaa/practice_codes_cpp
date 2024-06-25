#include <iostream>
using namespace std;

void insert(int A[], int n)
{
    int temp;
    int i = n;
    temp = A[i];
    while (i > 1 && temp > A[i / 2])
    {
        A[i] = A[i / 2];
        i = i / 2;
    }
    A[i] = temp;
}

void create(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        insert(A, i);
    }
}

int deletes(int A[],int n){
int val = A[1];    
int x = A[n];
int i = 1;
int j = 2*i;
A[1] = A[n];
A[n] = val;
while(j<=n-1){
    if (A[j+1]>A[j] && j<n-1)
    
        j = j+1;
    
    if (A[i]<A[j])
    {
        swap(A[i],A[j]);
        i = j;
        j = 2*j;
    }
    else{
        break;
    } 
}
return val;
}
int main() {
    int b[] ={30,49,50,20};

    create(b,sizeof(b)/sizeof(b[0]));

    for (int i = 3; i >0; i--)
    {
        deletes(b,i);
    }
    
    for (int i = 0; i <4; i++)
    {
        cout<<b[i]<<endl; 
    }

    
    
}