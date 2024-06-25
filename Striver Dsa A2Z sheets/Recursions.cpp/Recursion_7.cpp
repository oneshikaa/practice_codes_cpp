#include <iostream>
using namespace std;

class recursion
{
    int *A, n;

public:
    recursion()
    {
        cout << "enter the size of array" << endl;
        cin >> n;
        A = new int[n];
        cout << "enter the elements" << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
    }

    void reverse(int i)
    {

        if (i <(n/2))
        {
            swap(A[i], A[n - i - 1]);
            reverse(i + 1);
        }

        else
        {
            return;
        }
    }

    void display(){
        for (int i = 0; i < n; i++)
        {
            cout<<A[i]<<" ";
        }
        
    }
};

int main()
{
    recursion r;
    r.reverse(0);
    r.display();
}