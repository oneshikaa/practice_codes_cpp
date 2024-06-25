#include<iostream>
using namespace  std;

/*this approach is working*/

int reverse(){
    char a[] = "nitin";
    char b[100];
    int i;
    for ( i = 0; a[i]!='\0'; i++)
    {     
    }
    int j;
    i = i-1;
    for ( j = 0;i>=0 ;i--, j++)
    {
        b[j] = a[i];
    }
    b[j] = '\0';
    //comparing
    int k,l;
    for (k = 0,l = 0;a[k]!='\0'; k++,l++)
    {
        if (a[k]==b[l])
        {
          continue;
        }
        else{
            return -1;
        }      
    }   
    return 1;
}

int main(){
    int a = reverse();
    if (a==1)
    {
        cout<<"palindrome"<<endl;
    }
    else{
        cout<<"not";
    }
    
 
}