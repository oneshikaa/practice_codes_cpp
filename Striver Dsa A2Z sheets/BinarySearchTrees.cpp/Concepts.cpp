#include<iostream>
using namespace std;

class node{
    public :
    int data;
    node *lchild;
    node *rchild;
};

class tree{

    public :
    node *root;

    tree(){
        root = NULL;
    }

    void insert(){
        node *t = root;
        node *p;
        node *r;
        int x;
        cout<<"enter data";
        cin>>x;

        if(root==NULL){
            node *k = new node;
            k->data = x;
            k->lchild = NULL;
            k->rchild = NULL;
            k = root;
           // return ;
        }
        while(t!=NULL){     
           r = t;
           if( x < t->data){
            t = t->lchild;
           }
           if (x > t->data)
           {
            t = t->rchild;
           }
           else{
            return ;
           }
        }
        p = new node;
        p->data = x;
        p->lchild = NULL;
        p->rchild = NULL;
        if(r->data < x){
            r->lchild = p;
        }
        if (r->data > x)
        {
            r->rchild = p;
        }
    }

    void inorder(node *p){
        inorder(p->lchild);
        cout<<p->data<<" ";
        inorder(p->rchild);
    }

    node* deletes(node *p,int key){
        node *q;

        if(p==NULL){
            return NULL;
        }

        if (p->lchild==NULL && p->rchild==NULL)
        {
            if (p==root)
            {
                root=NULL;
            }
            delete p;
            return NULL;
        }
        if (key<p->data)
        {
            p->lchild = deletes(p->lchild,key);
        }
        if (key<p->data)
        {
            p->rchild = deletes(p->rchild,key);
        }
        
        



        


    }





};