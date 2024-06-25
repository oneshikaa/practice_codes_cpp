#include <iostream>
using namespace std;

class node
{
    public :
    int data;
    node *lchild;
    node *rchild;
};

class queue
{
    int front;
    int rear;
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

    bool isFull()
    {
        if (rear == size - 1)
        {
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        if (rear == front)
        {
            return true;
        }
        return false;
    }

    ~queue(){
        delete []q;
    }
};

class tree{
    node *root;
    public :
    tree(){
        root = NULL;
    }

    void create(){
        node *p,*t;
        root = new node;
        queue q(25);
        int x;
        cout<<"enter root value : "<<endl;
        cin>>x;
        root->data = x;
        root->lchild = NULL;
        root->rchild = NULL;
        q.enqueue(root);
        while(!q.isEmpty()){
            p = q.dequeue();
            int x;

            cout<<"enter left child value : "<<endl;
            cin>>x;
            if(x!=-1){
            t = new node;
            t->data = x;
            t->lchild = NULL;
            t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
            }

            cout<<"enter right child value : "<<endl;
            cin>>x;
            if(x!=-1){
            t = new node;
            t->data = x;
            t->lchild = NULL;
            t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
            }
        }
    }

    void level_order(){
        queue q(25);
        node *p = root;
        cout<<p->data<<" ";
        q.enqueue(p);
        while(!q.isEmpty()){
            p = q.dequeue();
            if (p->lchild)
            {
               p = p->lchild;
               cout<<p->data<<" ";
               q.enqueue(p);
            }

             if (p->rchild)
            {
               p = p->rchild;
               cout<<p->data<<" ";
               q.enqueue(p);
            }
            
        
       
        }
  
    }



};

int main(){
    tree T;
    T.create();

}