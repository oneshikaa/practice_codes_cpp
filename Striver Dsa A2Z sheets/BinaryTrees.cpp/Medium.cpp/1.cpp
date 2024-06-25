#include <iostream>
using namespace std;

// only create is working ...

class node
{
public:
    int data;
    node *rchild;
    node *lchild;
};

class queue
{

    int front, rear;
    int size;
    node **q;

public:
    queue(int size)
    {
        front = rear = -1;
        this->size = size;
        q = new node *[size];
    }

    void enqueue(node *x)
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

    node *dequeue()
    {
        node *x = NULL;
        if (isEmpty())
        {
            cout << "underflow" << endl;
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
};

class tree
{
    node *root;

public:
    tree()
    {
        root = NULL;
    }

    node *get_root()
    {
        return root;
    }

    void create()
    {
        node *p, *t;
        int x;
        root = new node;
        queue Q(25);
        cout << "enter root value" << endl;
        cin >> x;
        root->data = x;
        root->lchild = NULL;
        root->rchild = NULL;
        Q.enqueue(root);
        while (!Q.isEmpty())
        {
            p = Q.dequeue();
            int x;
            cout << "enter value of left child of " << p->data << ":" << endl;
            cin >> x;
            if (x != -1)
            {
                t = new node;
                t->data = x;
                t->rchild = NULL;
                t->lchild = NULL;
                p->lchild = t;
                Q.enqueue(t);
            }

            cout << "enter value of right child of " << p->data << ":" << endl;
            cin >> x;
            if (x != -1)
            {
                t = new node;
                t->data = x;
                t->rchild = NULL;
                t->lchild = NULL;
                p->rchild = t;
                Q.enqueue(t);
            }
        }
    }

    int height(node *p)
    {
        int x = 0;
        int y = 0;
        if (!p)
        {
            return 0;
        }
        x = height(p->lchild);
        y = height(p->rchild);
        if (x > y)
        {
            return x + 1;
        }
        else
        {
            return y + 1;
        }
    }
};

int main()
{
    tree t;
    t.create();
    cout << "height : " << t.height(t.get_root()) << endl;
}