#include<iostream>
#include<cstring>
using namespace std;



int main(){
    char a[] = "character";
    char h[26];
    char val = 97;

    for (int i = 0; i < 26; i++)
    {
        h[i] = 0;
    }
    
    for (int i = 0; a[i]!='\0'; i++)
    {
        h[a[i]-97] += 1;
    }

    for (int i = 0; i <26; i++)
    {
        if (h[i]>1)
        {
            cout<<(char)(i+val)<<" "<<h[i]<<endl;
        }
        
    }
    
    

}