#include<iostream>
using namespace std;

int main(){
    char a[] = "medical";
    char b[] = "decimal";

    char h[26] = {0};
    for (int i = 0; a[i]!='\0'; i++)
    {
        h[a[i]-97]+=1;
    }
    for (int i = 0;b[i]!='\0'; i++)
    {
        h[b[i]-97]-=1;
    }
    for (int i = 0; i <26; i++)
    {
        if (h[i]==0)
    {
        continue;
    }
    else{
        cout<<"not anagram"<<endl;
        break;
    }
    
    }
    cout<<"anagram";

}


