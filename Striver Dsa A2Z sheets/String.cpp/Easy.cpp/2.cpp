#include<iostream>
using namespace  std;

void check(){
    char a[] = "madam";
    int j;
    for (j= 0;a[j]!='\0'; j++)
    {
    }
    j = j-1;
    for (int i = 0;i<j; i++,j--)
    {
       swap(a[i],a[j]);
    }
    for (int k = 0;a[k]!='\0'; k++)
    {
        cout<<a[k];
    }
}

int main(){
    check();
}