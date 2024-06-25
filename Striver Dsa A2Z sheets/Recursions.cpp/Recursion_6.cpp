#include <iostream>
using namespace std;

class recursion
{

    int n;
    int counter = 1;
    int prod = 1;

public:
    recursion()
    {
        cout << "enter the number" << endl;
        cin >> n;
    }
    int product()
    {
        if (counter < n)
        {
            counter++;
            prod = prod * counter;

            product();
            return prod;
        }
    }
};

int main()
{
    recursion r;
    cout << r.product();
}