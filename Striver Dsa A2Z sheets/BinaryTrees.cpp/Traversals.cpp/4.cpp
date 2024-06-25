#include <iostream>
using namespace std;

//only create is working ...

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
            cout << "enter value of left child of "<<p->data<<":" << endl;
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

            cout << "enter value of right child of "<<p->data<<":" << endl;
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

    void inorder(node *p)
    {
        if (p)
        {
        inorder(p->lchild);
        cout << p->data << " ";
        inorder(p->rchild);
        }
        
       
    }
    void preorder(node *p)
    {
        if (p)
        {      
        cout << p->data << " ";
        preorder(p->lchild);
        preorder(p->rchild); 
        }
        

    }
    void postorder(node *p)
    {
        if (p)
        {
        postorder(p->lchild);
        postorder(p->rchild);
        cout << p->data << " ";
        }
        
    }

    void level_order( node *p )
    {
        queue Q(25);
       
        cout << p->data << " ";
        Q.enqueue(root);
        while (!Q.isEmpty())
        {
            p = Q.dequeue();
            if (p->lchild)
            {
                p = p->lchild;
                cout << p->data << " ";
                Q.enqueue(p);
            }
            if (p->rchild)
            {
                p = p->rchild;
                cout << p->data << " ";
                Q.enqueue(p);
            }
        }
    }
};

int main()
{
    tree t;
    t.create();
    cout << "Inorder : " << endl;
    t.inorder(t.get_root());
    cout << endl;

    cout << "preorder : " << endl;
    t.preorder(t.get_root());
    cout << endl;

    cout << "postorder : " << endl;
    t.postorder(t.get_root());
    cout << endl;

    cout << "level order : " << endl;
    t.level_order(t.get_root());
    cout << endl;


}
/*code from abdul bari course
#include <iostream>

using namespace std;
 
class Node{
public:
    Node* lchild;
    int data;
    Node* rchild;
};
 
class Queue{
private:
    int size;
    int front;
    int rear;
    Node** Q;  // [Node*]*: Pointer to [Pointer to Node]
public:
    Queue(int size);
    ~Queue();
    bool isFull();
    bool isEmpty();
    void enqueue(Node* x);
    Node* dequeue();
};
 
Queue::Queue(int size) {
    this->size = size;
    front = -1;
    rear = -1;
    Q = new Node* [size];
}
 
Queue::~Queue() {
    delete [] Q;
}
 
bool Queue::isEmpty() {
    if (front == rear){
        return true;
    }
    return false;
}
 
bool Queue::isFull() {
    if (rear == size-1){
        return true;
    }
    return false;
}
 
void Queue::enqueue(Node* x) {
    if (isFull()){
        cout << "Queue Overflow" << endl;
    } else {
        rear++;
        Q[rear] = x;
    }
}
 
Node* Queue::dequeue() {
    Node* x = nullptr;
    if (isEmpty()){
        cout << "Queue Underflow" << endl;
    } else {
        front++;
        x = Q[front];
    }
    return x;
}
 
 
class Tree{
private:
    Node* root;
public:
    Tree() { root = nullptr; }
    ~Tree();
    void CreateTree();
    void Preorder(){ Preorder(root); }  // Passing Private Parameter in Constructor
    void Preorder(Node* p);
    void Postorder(){ Postorder(root); }  // Passing Private Parameter in Constructor
    void Postorder(Node* p);
    void Inorder(){ Inorder(root); }
    void Inorder(Node* p);
    void Levelorder(){ Levelorder(root); }  // Passing Private Parameter in Constructor
    void Levelorder(Node* p);
    int Height(){ return Height(root); }  // Passing Private Parameter in Constructor
    int Height(Node* p);
    Node* getRoot(){ return root; }
};
 
void Tree::CreateTree() {
    Node* p;
    Node* t;
    int x;
 
    Queue q(25);
    root = new Node;
    cout << "Enter root value: " << flush;
    cin >> x;
    root->data = x;
    root->lchild = nullptr;
    root->rchild = nullptr;
    q.enqueue(root);
 
    while (! q.isEmpty()){
        p = q.dequeue();
 
        cout << "Enter left child value of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1){
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->lchild = t;
            q.enqueue(t);
        }
 
        cout << "Enter left child value of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1){
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}
 
void Tree::Preorder(Node *p) {
    if (p){
        cout << p->data << ", " << flush;
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
 
void Tree::Inorder(Node *p) {
    if (p){
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}
 
void Tree::Postorder(Node *p) {
    if (p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << ", " << flush;
    }
}
 
void Tree::Levelorder(Node *p) {
    Queue q(100);
    cout << root->data << ", " << flush;
    q.enqueue(root);
 
    while (! q.isEmpty()){
        p = q.dequeue();
        if (p->lchild){
            cout << p->lchild->data << ", " << flush;
            q.enqueue(p->lchild);
        }
        if (p->rchild){
            cout << p->rchild->data << ", " << flush;
            q.enqueue(p->rchild);
        }
    }
}
 
int Tree::Height(Node *p) {
    int l = 0;
    int r = 0;
    if (p == nullptr){
        return 0;
    }
 
    l = Height(p->lchild);
    r = Height(p->rchild);
    if (l > r){
        return l + 1;
    } else {
        return r + 1;
    }
}
 
Tree::~Tree() {
    // TODO
}
 
 
int main(){
 
    Tree t;
 
    t.CreateTree();
 
    cout << "Preorder: " << flush;
    t.Preorder(t.getRoot());
    cout << endl;
 
    cout << "Inorder: " << flush;
    t.Inorder(t.getRoot());
    cout << endl;
 
    cout << "Postorder: " << flush;
    t.Postorder(t.getRoot());
    cout << endl;
 
    cout << "Levelorder: " << flush;
    t.Levelorder(t.getRoot());
    cout << endl;
 
    cout << "Height: " << t.Height(t.getRoot()) << endl;
 
    cout << "Recursive Passing Private Parameter in Constructor" << endl;
 
    cout << "Preorder: " << flush;
    t.Preorder();
    cout << endl;
 
    cout << "Inorder: " << flush;
    t.Inorder();
    cout << endl;
 
    cout << "Postorder: " << flush;
    t.Postorder();
    cout << endl;
 
    cout << "Levelorder: " << flush;
    t.Levelorder();
    cout << endl;
 
    cout << "Height: " << t.Height() << endl;
 
}*/
