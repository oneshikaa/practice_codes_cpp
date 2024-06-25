#include <iostream>
using namespace std;

class DoubleLL
{
public:
    typedef struct node
    {
        int data;
        struct node *prev;
        struct node *next;
    } node;

    node *head = NULL;
    node *last = NULL;

    void create(int A[], int n)
    {
        node *t;
        head = new node;
        head->data = A[0];
        head->next = NULL;
        last = head;

        for (int i = 1; i < n; i++)
        {
            t = new node;
            t->data = A[i];
            t->next = NULL;
            last->next = t;
            last = t;
        }
    }

    void display()
    {
        if (head == NULL)
            return;
        node *p = head;
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    void insert_beg()
    {
        int x;
        cout << "enter the number you want to add" << endl;
        cin >> x;
        node *t = new node;
        t->data = x;
        t->prev = NULL;
        t->next = head;
        head->prev = t;
        head = t;
    }

    void insert_mid()
    {
        int x, pos;
        node *p = head;
        cout << "enter the number you want to add" << endl;
        cin >> x;
        cout << "enter the position at which the number should be added" << endl;
        cin >> pos;
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }

        node *t = new node;
        t->data = x;

        t->prev = p;
        t->next = p->next;

        if (p->next)
        {
            p->next->prev = t;
        }
        p->next = t;
    }

    void del()
    {
        int pos;
        cout << "enter the position to be deleted" << endl;
        cin >> pos;

        // cout<<"enter else"<<endl;
        if (pos == 1)
        {
            node *p = head;

            head = head->next;
            delete p;
            head->prev = NULL;
        }

        else
        {
            node *p = head;

            for (int i = 0; i < pos - 1; i++)
            {
                // cout<<"del";
                p = p->next;
                // cout<<p->data<<endl;
            }
            // cout<<"change";
            p->prev->next = p->next;
            p->next->prev = p->prev;

            // cout<<"del p1"<<endl;
            delete p;
        }
    }

    void reverse()
    {
        node *p = head;
        node *temp;
        while (p)
        {
            temp = p->next;
            p->next = p->prev;
            p->prev = temp;
            p = p->prev;
            while (p->next == NULL)
            {
                p->next = p->prev;
                p->prev = NULL;
                head = p;
                break;
            }
        }
    }
};

int main()
{

    DoubleLL list;

    int A[] = {10, 20, 30, 40};
    list.create(A, 4);
    list.display();
    // list.insert_beg();

    // list.insert_mid();
    // list.display();
    // list.del();
    list.reverse();
    list.display();
}