#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

class stack
{
public:
    node *top;

    stack()
    {
        top = NULL;
    }
    void push(int x)
    {
        node *t = new node;
        t->next = top;
        top = t;
        t->data = x;
    }
    void pop()
    {
        node *p = top;
        int x = p->data;
        top = p->next;
        delete p;
    }
    int len()
    {
        int l = 0;
        node *p;
        while (p)
        {
            l++;
            p = p->next;
        }
        return l;
    }
    void display()
    {
        node *p = top;
        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }
    bool isEmpty(){
        if(top==NULL){
            return true;
        }
        return false;
    }
    int top_value(){
        if(isEmpty()){
            return -1;
        }
        else{
            return top->data;
        }
    }
};

void print()
{
    stack stk;
    int n;
    cout << "enter size of array" << endl;
    cin >> n;
    int *arr;
    arr = new int[n];
    int *nge;
    nge = new int[n];

    cout<<"enter the elements"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    //main working code
    for (int i = 2*n-1; i>=0; i--)
    {
        while (!stk.isEmpty() && stk.top_value()<=arr[i%n])
        {
            stk.pop();
            
        }
        if (i<n)
        {
            nge[i] = stk.top_value();
        }
      /*  else{
            nge[i] = -1;
        }*/
        
        stk.push(arr[i%n]);
    
    }

    //displaying the output array
    for (int i = 0; i < n; i++)
    {
        cout<<nge[i]<<" ";
    }
    
}

int main()
{
  print();
}