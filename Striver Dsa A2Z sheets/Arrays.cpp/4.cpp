#include <iostream>
using namespace std;

int remove(int *arr, int n)
{
    int i = 0;
    for (int j = 0; j < n; j++)
    {

        if (arr[i] != arr[j])
        {
            i++;
            arr[i] = arr[j];
        }
    }
    return i+1;
}

int main()
{
    int *arr;
    int n;

    cout << "enter size" << endl;
    cin >> n;

    arr = new int[n];

    cout << "enter elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k = remove(arr, n);

    for (int i = 0; i < k; i++)
    {
        cout << arr[i] << " ";
    }
}
