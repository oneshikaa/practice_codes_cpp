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

    int arr[100];


    
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
        { // insert_end
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
        for (int i = len() - 1; i >= 0; i--)
        {
            cout << arr[i]<<" ";
        }
    }
    
    
    int len()
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

   
    void copy()
    {
        node *p = head;

        int i = 0;

        while (p)
        {

            arr[i] = p->data;
            i++;
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
    l.copy();
    l.display();

    
    
}
