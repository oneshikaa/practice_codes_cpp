#include<iostream>
#include<cstring>
using namespace std;

class str{
    char *s;
    //char *s2;
    int n;

    public :
    str(){
        cin>>n;
        cout<<"enter the string"<<endl;
        for (int i = 0; i<n; i++)
        {
            cin>>s[i];
        }
        
    }

    void sort(){
        for (int i = 0; i <n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (s[j]>s[j+1])
                {
                    swap(s[j],s[j+1]);
                }
                
            }
        }  
    }
    void display(){
        for (int i = 0; i < n; i++)
        {
            cout<<s[i];
        }
        
    }
};

int main(){
    str s1;
    s1.sort();
    //s2.sort();
    s1.display();
    //s2.display();

}

/*// C++ program to sort a string of characters
#include<bits/stdc++.h>
using namespace std;

// function to print string in sorted order
void sortString(string &str)
{
sort(str.begin(), str.end());
cout << str;
}

// Driver program to test above function
int main()
{
	string s = "geeksforgeeks";
	sortString(s);
	return 0;
}
*/