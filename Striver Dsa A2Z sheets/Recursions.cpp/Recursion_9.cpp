#include <iostream>
using namespace std;

class recursion
{
    int n;
    int sum = 0;

public:
    recursion(int a)
    {
        n = a;
    }

    int fib(int i)
    {
        if (i == 0)
        {
            sum = 0;
            cout << sum << " ";
        }
        else if (i == 1)
        {
            sum = 1;
            cout << sum << " ";
        }
        else if (i < n)
        {
            sum = fib(i - 1) + fib(i - 2);
            cout << sum << " ";
        }
        return sum;
    }
};

int main()
{
    int n;

    cout << "enter the number" << endl;
    cin >> n;
    recursion r(n);
    r.fib(n);
}