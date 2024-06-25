#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *arr;
    arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];    }

    int *temp;
    temp = new int[n];
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
           
            temp[j] = arr[i];
             j++;
        }
  
    }

    for (int i = 0; i < n; i++)
    {
        if (temp[i] != 0)
        {
            continue;
        }
        else
        {
            temp[i] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << temp[i] << " ";
    }
}