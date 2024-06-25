#include <iostream>
using namespace std;

class A
{
private:
    int a, b;

public:
    int c, d;

    void setData(int a1, int b1);
    void getData()
    {
        cout << "The value of a is " << a << endl;
        cout << "The value of b is " << b << endl;
        cout << "The value of c is " << c << endl;
        cout << "The value of d is " << d << endl;
    }
    };

    void A ::setData(int a1, int b1 )
    {
        a = a1;
        b = b1;
    }

    int main()
    {

        A anonymous;
        anonymous.c = 34;
        anonymous.d = 23;
        anonymous.setData(2, 5);
        anonymous.getData();

        return 0;

      
    }