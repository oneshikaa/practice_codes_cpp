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
    void insert_beg(){
        node *t = new node;
        int x;
        cout<<"enter data : "<<endl;
        cin>>x;
        t->data = x;
        
        t->next = last;
        last = t;
    }
    void push(){
        if(head==NULL){
            create();
        }
        else{
            insert_beg();
        }
    }
    //pop function should act as delete_end
    void pop(){
        node *p = last;
        last = p->next;
        delete p;


    }
    void display(){
        node *p = last;
        
        while(p!=NULL){
           // cout<<"inside display";
            cout<<p->data<<" ";
            p = p->next;
        }
    }
    int isEmpty(){
        if(last==NULL){
            return 1;
        }
        return -1;
    }
    int size(){
        int l = 0;
        node *p = last;
        while(p){
            l++;
            p = p->next;
        }
        return l;
    }
    int top(){
        node *p = last;
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