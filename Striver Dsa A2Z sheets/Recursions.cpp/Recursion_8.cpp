#include<iostream>
using namespace std;

class recursion{
    char *A;int n;

    public :

    recursion()
    {
        cout << "enter the size of array" << endl;
        cin >> n;
        A = new char[n];
        cout << "enter the characters" << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
    }

    void palindrome(int i){
        while(i<(n/2)){
        if(A[i]==A[n-i-1]){
            palindrome(i+1);
            
        }
        else{
            cout<<"not palindromic";
        }
        }
        cout<<"palindromic";
    }

};

int main(){
    recursion r;
    r.palindrome(0);

}