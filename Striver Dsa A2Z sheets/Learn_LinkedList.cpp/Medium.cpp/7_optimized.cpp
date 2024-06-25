#include <iostream>
using namespace std;

class list
{
    typedef struct node
    {
        int data;
        node *next;
    } node;

    node *head = NULL;
    node *last;
    int arr[100];

public:
    void create()
    {
        if (head == NULL)
        {
            head = new node;
            int x;
            cout << "enter data : " << endl;
            cin >> x;
            head->data = x;
            head->next = NULL;
            last = head;
        }
        else
        {
            node *p = new node;
            int x;
            cout << "enter data" << endl;
            cin >> x;
            p->data = x;
            last->next = p;
            p->next = NULL;
            last = p;
        }
    }

    int len()
    {
        node *q = head;
        int l = 0;
        while (q)
        {
            l++;
            q = q->next;
        }
        return l;
    }

    int detect()
    {
        node *fast = head;
        node *slow = head;
        node *p = head;

        while (fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        for (int i = 0; i < (len() + 1) / 2; i++)
        {
            slow = slow->next;
            arr[i] = slow->data;
        }

        for (int i = (len() -2) / 2; i >=0; i--)
        {
            if (arr[i] == slow->data)
            {
                slow = slow->next;
                continue;
            }
            else
            {
                return -1;
                break;
            }
        }

        return 1;
    }
};

int main()
{
    list L;
    cout << "enter the number of nodes" << endl;
    int n;
    cin >> n;
    while (n--)
    {
        L.create();
    }

    int c = L.detect();
    if (c == 1)
    {
        cout << "palindromic" << endl;
    }
    else
        cout << "not palindromic" << endl;
}
