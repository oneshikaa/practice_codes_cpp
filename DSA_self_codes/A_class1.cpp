#include <iostream>
using namespace std;

void Merge(int *arr, int low, int mid, int high)
{

    int *T;

    int ac = low;
    int bc = mid;
    int tc = 0;
    int l = mid - 1;

    while (ac <= l && bc <= high)
    {
        if (arr[ac] <= arr[bc])
        {
            T[tc] = arr[ac];
            tc++;
            ac++;
        }
        else
        {
            T[tc] = arr[bc];
            tc++;
            bc++;
        }
    }

    while (ac <= l)
    {
        T[tc] = arr[ac];
        tc++;
        ac++;
    }
    
    
    while (bc <= high)
    {
        T[tc] = arr[bc];
        tc++;
        bc++;
    }
    
    for (int i = low; i < high; i++)
    {
        arr[i] = T[i - low];
    }
}

void MergeSort(int *arr, int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        Merge(arr, low, mid + 1, high);
    }
}

int main()
{
    int n;
    int arr[100];
    cout << "enter size of array" << endl;
    cin >> n;
    cout << "enter the elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    MergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}