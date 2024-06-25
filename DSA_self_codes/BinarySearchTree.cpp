#include<iostream>
using namespace std;

typedef struct node{
    public :
    node *lchild;
    int data;
    node *rchild;

}node;

node *root = NULL;
node *temp;

void create(){
    temp = new node;
    cout<<"enter data : ";
    int x;
    cin>>x;
    temp->data = x;
    temp->lchild = NULL;
    temp->rchild = NULL;
}

void search(node *p){
    if(temp->data < p->data && p->lchild==NULL){
        p->lchild = temp;
    }
    if(temp->data < p->data && p->lchild!=NULL){
        search(p->lchild);
    } 
    if(temp->data > p->data && p->rchild==NULL){
        p->rchild = temp;
    }
    if(temp->data > p->data && p->rchild!=NULL){
        search(p->rchild);
    }
}

void insert(){
    if(root==NULL){
        root = temp;
    }
    else{
        search(root);
    }
}

int tree_search(node *p,int key){

    if (p->data==key)
    {
        return 1;
    }
     if (p->data<key)
    {
        tree_search(p->rchild,key);
    }
     if (p->data>key)
    {
        tree_search(p->lchild,key);
    }
    if (p==NULL)
    {
        return 0;
    }
 
}

void tree_minimum(node *p)
{
    while (p != NULL)
    {
        p = p->lchild;
    }
    cout << p->data;
}

void inorder(node*p){
      if(p!=NULL){
        inorder(p->lchild);
        cout<<p->data<<" ";
        inorder(p->rchild);
      }
}

node *tree_succ(node *p){
    while(p && p->rchild!=NULL){
        p = p->rchild;
    }
    return p;
}

node *tree_pre(node *p){
    while(p && p->lchild!=NULL){
        p = p->lchild;
    }
    return p;
}

int height(node *p){
    int x = height(p->lchild);
    int y = height(p->rchild);
    if (x>y)
    {
        return x+1;
    }
    else{
        return y+1;
    }    
}

node* deletes(node *p,int key){
    node *q;
    //if no node is there
    if(p==NULL){
        return NULL;
    }
    //if only root is there
    if(p->lchild==NULL && p->rchild==NULL){
        if(p==root){
            root = NULL;
        }
        delete p;
        return NULL;
    }

    if(key>p->data){
        p->rchild = deletes(p->rchild,key);
    }
    if(key<p->data){
        p->lchild = deletes(p->lchild,key);
    }
    //key==p->data
    else{
        if(height(p->lchild)>height(p->rchild)){
            q = tree_pre(p->lchild);
            p->data = q->data;
            p->lchild = deletes(p->lchild,q->data);

        }
        else{
             q = tree_succ(p->rchild);
            p->data = q->data;
            p->rchild = deletes(p->rchild,q->data);

        }
    }
    return p;
}

int main(){

}