#include<iostream>
#include<cstring>

using namespace std;

class node{
    public :
    int data;
    node *next;
};

class stack{
     public : 

    node *top;

    stack(){
        top = NULL;
    }
    void push(char x){
        node *t = new node;
        t->data = x;
        t->next = top;
        top = t;

    }
    char pop(){
        node *p = top;
        char x = p->data;
        top = top->next;
        delete p;
        return x;
    }
    bool isEmpty(){
        if(top==NULL){
            return true;
        }
        return false;
    }
};

int pre(char x){
    if(x=='+'|| x=='-'){
        return 1;
    }
    else if(x=='*' || x=='/'){
        return 2;
    }
    return 0;
}

int isOperand(char x){
    if(x=='+' || x=='-' || x=='*' || x=='/'){
        return 0;
    }
    return 1;

}

char *InToPost(char *infix){
    int i = 0;
    int j = 0;
    int len = strlen(infix);
    stack stk;

    char *postfix = new char[len+1];

    while(infix[i]!='\0'){
        if(isOperand(infix[i])){
            postfix[j++] = infix[i++];
        }
        else{
            if(pre(infix[i])>pre(stk.top->data)){
                stk.push(infix[i++]);
            }
            else{
                postfix[j++] = stk.pop();
            }
        }
        
    }
    while(stk.top!= NULL){
        postfix[j++] = stk.pop();  
    }
    postfix[j] = '\0';
    return postfix;
}

int main(){
    char A[] = "a+b*c";
    char *postfix =InToPost(A); 
    cout<<postfix;

}