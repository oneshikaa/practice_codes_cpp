#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

class queue
{
    node *front;
    node *rear;

public:
    queue()
    {
        front = NULL;
        rear = NULL;
    }
    void enqueue(int d)
    {
        node *n = new node;
        n->data = d;
        n->next = NULL;
        if (rear == NULL && front == NULL)
        {
            front = rear = n;
            n->next = front;
        }
        else
        {
            rear->next = n;
            rear = n;
            n->next = front;
        }
    }
    void dequeue()
    {
        node *n;
        n = front;
        if (rear == NULL && front == NULL)
        {
            cout << "underflow";
        }
        else if (rear == front)
        {
            rear = front = NULL;
            delete n;
        }
        else
        {
            front = front->next;
            rear->next = front;
            delete n;
        }
    }
    void display()
    {
        node *n = front;
        if (front == NULL && rear == NULL)
        {
            cout << "q is empty" << endl;
        }
        else
        {
            do
            {
                cout << n->data << " ";
                n = n->next;
            } while (n != front);
        }
    }
};

int main(){
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.dequeue();
    q.display();


}
