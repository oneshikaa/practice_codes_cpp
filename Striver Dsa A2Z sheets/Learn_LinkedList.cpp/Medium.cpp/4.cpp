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
            head->data = x;
            head->next = NULL;
            last = head;
        }
        else
        {
            int x;
            cout << "enter data : " << endl;
            cin >> x;
            node *p = new node;
            p->data = x;
            last->next = p;
            p->next = NULL;
            last = p;
        }
    }

    int len()
    {
        int l = 0;
        node *p = head;
        while (p)
        {
            l++;
            p = p->next;
        }

        return l;
    }

    void display()
    {
        node *p = head;
        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }

    void make_loop(){
        int x;
        cout<<" enter position where tail is connected "<<endl;
        cin>>x;
        node *q = head;
        node *r = head;
        

        for (int i = 0; i < x; i++)
        {
            q = q->next;
            r = r->next;
            
        }

       last->next = q;
       


    while(q){
       // cout<<q->data<<" ";
        
        q = q->next;
        if (last->next->data==q->data)
        {
          break;
        }
   
      
    }
    if(q->data==r->data){
        cout<<"loop exist"<<endl;
    }
    else{
        cout<<"loop doesnt exist"<<endl;
    }


    }
};

int main()
{
    list L;
    int n;
    cout << "enter the number of elements" << endl;
    cin >> n;
    while (n--)
    {
        L.create();
    }
   // L.display();
  L.make_loop();
}