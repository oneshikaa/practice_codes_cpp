#include <iostream>
using namespace std;

template <class t1, class t2>

void show(t1 a, t2 b)
{
    cout << a << " " << b<<endl;
}

int main()
{
    show(100, "hello hello");
    show('k', 1500);
    show(1.23, 2987);

    return 0;
}