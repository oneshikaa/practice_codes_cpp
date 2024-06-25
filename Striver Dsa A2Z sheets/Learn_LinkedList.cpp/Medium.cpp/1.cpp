#include <iostream>
using namespace std;


class List{
    public : 
    typedef struct node
    {
        int data;
        node *next;
    } node;

    node *head = NULL;
    node *last;


    //creation of list
    void lists()
    {

        if (head == NULL)
        {
            int x;
            cout << "enter the elements : " << endl;
            cin >> x;

            head = new node;
            head->data = x;
            head->next = NULL;
            last = head;
        }
        else
        {
          int y;
          cout << "enter data" << endl;
            cin >> y;
            node *p;
            p = new node;
            p->data = y;
            last->next = p;
            p->next = NULL;
            last = p;

            
        }
    }
    
    void display()
    {
        node*p = head;
        while(p)
        {
            cout<<p->data<<endl;
            p=p->next;
        }
    }
    
    //finding length
    int length()
    {
        node *p = head;
        int n = 0;
        while (p)
        {
            n++;
            p = p->next;
        }
        return n;
    }

    //finding mid

    void mid()
    {
        node *p = head;
        int l = length();
        cout<<l<<endl;

        if (l % 2 == 0)
        {
            for (int i = 1; i < l / 2; i++)
            {
                p = p->next;
            }
        }
        else
        {
            for (int i = 1; i < (l + 1) / 2; i++)
            {
                p = p->next;
            }
        }
        
        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }
        
    }
};

  

int main()
{
    List l;
    int a;
    cout<<"enter number of elements : "<<endl;
    cin>>a;
    while(a--){
        l.lists();

    }
    l.mid();


}