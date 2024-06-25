#include <iostream>
using namespace std;

class heap
{
    int *arr;
    int n;

public:
    heap()
    {
    
        cout << "enter size of the array : " << endl;
        cin >> n;
        arr = new int[n];
        cout << "enter the elements" << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

    
    }

    void max_heapify(int m)
    { 
        int j, t;
        t = arr[m];
        j = 2 * m;
        while (j <= n)
        {
            if (j < n && arr[j + 1] > arr[j])
                j = j + 1;
            if (t > arr[j])
                break;
            else if (t <= arr[j])
            {
                arr[j / 2] = arr[j];
                j = 2 * j;
            }
        }
         arr[j / 2] = t;
        return;
    }

    void build_maxheap(){
        for (int i = n/2; i>=1; i++)
        {
          max_heapify(1);
        }
        
    }

    void display(){
        for (int i = 0; i < n; i++)
        {
            cout<<arr[i]<<" ";
        }
    }
};

int main()
{
    heap hp;
    hp.build_maxheap();
    hp.display();
}