#include <iostream>
using namespace std;

class queue
{
    int front, rear;
    int size;
    int *q;

public:
    queue()
    {
        front = rear = -1;
        cout << "enter number of elements : " << endl;
        cin >> size;
        q = new int[size];
    }

    void enqueue()
    {
        int x;
        if (rear == size - 1)
        {
            cout << "overflow";
            // break;
        }
        else
        {
            rear++;
            cout << "enter data : ";
            cin >> x;
            q[rear] = x;
        }
    }

    int dequeue()
    {
        if (front == rear)
        {
            cout << "underflow";
            return -1;
        }
        else
        {
            front++;
            int x = q[front];
            return x;
        }
    }

   int get_size(){
    return size;
   }
};

int main()
{
}