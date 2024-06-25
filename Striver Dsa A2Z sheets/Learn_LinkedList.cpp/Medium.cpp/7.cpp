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

public:
    void create()
    {
        if (head == NULL)
        {
            int x;
            cout << "enter data : " << endl;
            cin >> x;
            head = new node;
            head->next = NULL;
            last = head;
            head->data = x;
        }
        else
        {
            int x;
            cout << "enter data : " << endl;
            cin >> x;
            node *p = new node;
            last->next = p;
            p->next = NULL;
            last = p;
            p->data = x;
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

    int find()
    {
        node *q = head;
        node *p = head;
        int n = len();
        int arr[100];
        //taking q to next element of middle element
        if (n % 2 == 0)
        {
            for (int i = 0; i < n / 2; i++)
            {
                q = q->next;
            }
        }
        else
        {
            for (int i = 0; i < (n + 1) / 2; i++)
            {
                q = q->next;
            }
        }

            for (int i = 0; i < n / 2; i++)
            {
                arr[i] = p->data;
                p = p->next;
            }
    
        //comparing array with the right half of the list
    

            for (int i = (n-2) / 2; i >=0; i--)
            {

                if (arr[i] == q->data)
                {
                    q = q->next;
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
    int c = L.find();
    if (c==1)
    {
        cout<<"palindromic"<<endl;
    }
    else
    cout<<"not palindromic"<<endl;
    
}