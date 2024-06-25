#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Queue
{
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = rear = NULL;
    }

    void enqueue(int x)
    {
        Node *t = new Node;
        if (t == NULL)
        {
            cout << "queue is full" << endl;
        }

        else
        {
            t->data = x;
            t->next = NULL;

            if (front == NULL)
            {
                front = t;
                rear = t;
            }

            else
            {
                rear->next = NULL;
                rear = t;
            }
        }
    }

    int dequeue()
    {
        int x = -1;
        Node *p;
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
        }
        else
        {
            p = front;
            front = front->next;
            x = p->data;
            delete p;
        }
        return x;
    }

    bool isEmpty()
    {
        if (front == nullptr)
        {
            return true;
        }
        return false;
    }

    ~Queue()
    {
        Node *p = front;
        while (front)
        {
            front = front->next;
            delete p;
            p = front;
        }
    }

    void display()
    {
        Node *p = front;
        while (p)
        {
            cout << p->data <<" ";
            p = p->next;
           /* if (p != nullptr)
            {
                cout << " <- " << flush;
            }*/
        }
        cout << endl;
    }
};

int main()
{
   
    int A[] = {1, 3, 5, 7, 9};
 
    Queue q;
 
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        q.enqueue(A[i]);
    }
 
    q.display();
 
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        q.dequeue();
    }
    q.dequeue();
 
    return 0;
}