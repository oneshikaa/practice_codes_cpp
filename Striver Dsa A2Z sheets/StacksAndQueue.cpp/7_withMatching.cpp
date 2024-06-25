#include<iostream>
#include<cstring>

using namespace std;

class node{
    public :
    int data;
    node *next;
};

class stack{
    node *top;

    public : 

    stack(){
        top = NULL;
    }
    void push(char x){
        node *t = new node;
        t->data = x;
        t->next = top;
        top = t;

    }
    void pop(){
        node *p = top;
        char x = p->data;
        top = top->next;
        delete p;
    }
    bool isEmpty(){
        if(top==NULL){
            return true;
        }
        return false;
    }
};

int isBalanced(char* exp){
    stack stk;
 
    for (int i=0; i<strlen(exp); i++){
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
            stk.push(exp[i]);
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            if (stk.isEmpty()){
                return false;
            } else {
                stk.pop();
            }
        }
    }
    return stk.isEmpty() ? true : false;
}


int main(){
    char A[] = "(()))";
    
    if (isBalanced(A))
    {
      cout<<"is balanced";
    }
    else{
        cout<<"is not balanced";

    }
    

}

