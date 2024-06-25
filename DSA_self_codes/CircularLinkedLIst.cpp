#include <iostream>
using namespace std;

class ll
{
    typedef struct Node
    {
        int data;
        struct Node *next;
    } Node;

    Node *head;

    void create(int A[], int n)
    {
        int i;
        Node *t,last;
        head = new Node;
        head->data = A[0];
        head->next = head;
        last = head;
        
    }
};

int main()
{
}