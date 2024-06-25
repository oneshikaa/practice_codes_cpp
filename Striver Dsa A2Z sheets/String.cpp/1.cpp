#include <iostream>
using namespace std;

class stack
{
    int top;
    int n;
    char *arr;

public:
    stack()
    {
        int top = -1;
    }

    void push(char *arr)
    {
        for (int i = 0; i < n; i++)
        {
            top++;
            arr[top] = arr[i];
        }
    }

    void pop()
    {
        for (int i = 0; i < n; i++)
        {
            top--;
        }
    }

    int len(int n)
    {
        int length = n;
        return length;
    }

    void display()
    {
        for (int i = 0; i < top; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    stack S;
    int n;
    char *arr;

    cout << "enter the size of array : " << endl;
    cin >> n;
    arr = new char[n];

    cout << "enter the string : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < S.len(n); i++)
    {
        if (arr[i] == arr[i + 1])
        {
            S.pop();
        }
        else
        {
            S.push(arr);
        }
    }

    S.display();
}