#include <iostream>
using namespace std;

class queue
{
public:
    int front;
    int rear;
    int size;
    int *q;

    queue()
    {
        front = rear = -1;
        cout << "enter number of elements" << endl;
        cin >> size;
        q = new int[size];
    }
    void create()
    {
        cout << "enter the elements : " << endl;
        int x;
        for (int i = 0; i < size; i++)
        {
            cin >> x;
            enqueue(x);
        }
    }
    void enqueue(int x)
    {

        if (isFull())
        {
            cout << "overflow" << endl;
        }
        else
        {
            rear++;
            q[rear] = x;
        }
    }
    int dequeue()
    {
        int x;
        if (isEmpty())
        {
            cout << "underflow" << endl;
            return -1;
        }
        else
        {
            front++;
            x = q[front];
        }
        return x;
    }
    bool isEmpty()
    {
        if (front == rear)
        {
            return true;
        }
        return false;
    }
    bool isFull()
    {
        if (rear == size - 1)
        {
            return true;
        }
        return false;
    }
    int get_size()
    {
        return size;
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << q[i] << " ";
        }
    }
    int getTop()
    {
        return q[rear];
    }
};

void getStack()
{
    queue Q;
   int x;
    cout << "enter data" << endl;
    cin >> x;
    Q.enqueue(x);

    for (int i = 0; i < Q.get_size(); i++)
    {
         
        Q.enqueue(Q.getTop());
        Q.dequeue();
    }

    Q.display();
}

int main()
{
    getStack();
}