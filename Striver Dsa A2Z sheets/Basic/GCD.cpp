#include <iostream>
using namespace std;

int min(int a, int b)
{
    if (a >= b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

int main()
{
    int num1, num2, num;
    cout << "enter the numbers" << endl;
    cin >> num1;
    cin >> num2;

    int c = min(num1, num2); 

    for (int i = 1; i <= c ; i++)
    {
        if (num1 % i == 0 && num2 % i == 0)
        {
            num = i;
        }
    }

    cout << "HCF is " << num << endl;
}
