#include<iostream>
using namespace std;

class stack{

    typedef struct node{
        int data;
        node *next;

    }node;

    node *head = NULL;
    node *last;

    public :
    
    void create(){
        head = new node;
        int x;
        cout<<"enter data : "<<endl;
        cin>>x;
        head->data = x;
        head->next=NULL;
        last = head ; 
    }
    void insert_end(){
        node *t = new node;
        int x;
        cout<<"enter data : "<<endl;
        cin>>x;
        t->data = x;
        
        last->next=t;
        t->next = NULL;
        last = t;
    }
    void push(){
        if(head==NULL){
            create();
        }
        else{
            insert_end();
        }
    }
    //pop function should act as delete_beg
    void pop(){
        node *p = head;
        head = p->next;
        delete p;


    }
    void display(){
        node *p = head;
        
        while(p!=NULL){
           // cout<<"inside display";
            cout<<p->data<<" ";
            p = p->next;
        }
    }
    int isEmpty(){
        if(head==NULL){
            return 1;
        }
        return -1;
    }
    int size(){
        int l = 0;
        node *p = head;
        while(p){
            l++;
            p = p->next;
        }
        return l;
    }
    int top(){
        node *p = head;
        return p->data;

    }
};

int main(){
    stack s;
    s.push();
    s.push();
    s.push();
    s.push();
    s.display();
    cout<<endl;
    s.pop();
    s.display();
   cout<<endl;
    cout<<"size : "<<s.size()<<endl;
    cout<<"top : "<<s.top()<<endl;
    cout<<s.isEmpty()<<endl;
    s.pop();
    //s.display(); 
    s.pop();
    s.pop();
    cout<<s.isEmpty()<<endl;



}